/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file Ram.cc
 * @desc Ejecuta instrucciones interpretando la sintaxis RAM.
 *
 */
#include "../lib/Ram.h"
#include <sstream>
#include <iostream>
#include <algorithm>

void Ram::executeInstruction(const std::string& instruction, int& program_counter) {
  if (instruction.empty()) {
    return;
  }

  std::istringstream iss(instruction);
  std::string opcode;
  if (!(iss >> opcode)) return;

  // Ignorar si el opcode empieza por comentario
  if (opcode[0] == '#') return;
  
  std::transform(opcode.begin(), opcode.end(), opcode.begin(), ::toupper);

  InstructionContext ctx{};
  ctx.program_counter = &program_counter;

  if (opcode == "HALT") {
    std::cout << "Program halted." << std::endl;
    return;
  }

  if (opcode == "JUMP" || opcode == "JZERO" || opcode == "JGTZ") {
    iss >> ctx.label;
    logic_unit_->execute(opcode, ctx);
    return;
  }

  std::string op;
  iss >> op; 

  if (op.empty()) return;

  // analizador hibrido
  size_t b_open = op.find('[');
  
  if (b_open != std::string::npos) {
    // sintaxis dinamica
    size_t b_close = op.find(']');
    ctx.regist = std::stoi(op.substr(0, b_open));
    int p_val = std::stoi(op.substr(b_open + 1, b_close - b_open - 1));
    std::string rem = op.substr(b_close + 1);

    if (rem.empty()) { ctx.op_type = 1; ctx.pos = p_val; }
    else if (rem[0] == '[') { 
        ctx.op_type = 2; 
        ctx.pos = p_val; 
        ctx.pos_ind = std::stoi(rem.substr(1, rem.find(']', 1) - 1));
    }
    else { ctx.op_type = 0; ctx.pos = std::stoi(rem); }
  } 
  else {
    // sintaxis estatica
    if (op[0] == '=') {
      ctx.op_type = 0;
      ctx.pos = std::stoi(op.substr(1));
    } else if (op[0] == '*') {
      ctx.op_type = 2;
      ctx.regist = std::stoi(op.substr(1));
      ctx.pos = 0;
    } else {
      ctx.op_type = 1;
      ctx.regist = std::stoi(op);
      ctx.pos = 0; 
    }
  }

  // Comprobacion de instrucciones ilegales
  // No se puede hacer STORE o READ a una constante
  if ((opcode == "STORE" || opcode == "READ") && ctx.op_type == 0) {
    std::cerr << "\nFATAL ERROR: Illegal instruction. Cannot execute '" 
              << opcode << "' with a constant operand at line " << program_counter << "." << std::endl;
    std::exit(EXIT_FAILURE);
  }

  if (ctx.op_type != 0 && ctx.regist == 0) {
    
    // WRITE y READ no se pueden usar en R0
    if (opcode == "WRITE" || opcode == "READ") {
      std::cerr << "\nFATAL ERROR: Illegal instruction. I/O operations ('" 
                << opcode << "') are not allowed directly on the Accumulator (R0) at line" << program_counter << "." << std::endl;
      std::exit(EXIT_FAILURE);
    }

    // STORE no tiene sentido usarse en R0
    if (opcode == "STORE") {
      std::cerr << "\nFATAL ERROR: Illegal instruction. 'STORE' to the "
                << "Accumulator (R0) is not allowed at line " << program_counter << "." << std::endl;
      std::exit(EXIT_FAILURE);
    }
  }

  // ejecución delegada al objeto lógico
  logic_unit_->execute(opcode, ctx);
}
