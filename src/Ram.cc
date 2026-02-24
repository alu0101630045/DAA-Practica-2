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
    if (opcode == "JUMP") logic_unit_->Jump(ctx);
    else if (opcode == "JZERO") logic_unit_->JumpZero(ctx);
    else if (opcode == "JGTZ") logic_unit_->JumpGreaterThanZero(ctx);
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

  // ejecución
  if (opcode == "LOAD") logic_unit_->Load(ctx);
  else if (opcode == "STORE") logic_unit_->Store(ctx);
  else if (opcode == "ADD") logic_unit_->Add(ctx);
  else if (opcode == "SUB") logic_unit_->Sub(ctx);
  else if (opcode == "MUL") logic_unit_->Mult(ctx);
  else if (opcode == "DIV") logic_unit_->Div(ctx);
  else if (opcode == "READ") logic_unit_->Read(ctx);
  else if (opcode == "WRITE") logic_unit_->Write(ctx);
  else {
    // Hay alguna instruccion ilegar
    std::cerr << "\nFatal ERROR: Ilegal instruction in line: " 
              << program_counter << " -> '" << opcode << "'" << std::endl;
    std::exit(EXIT_FAILURE);
  }
}
