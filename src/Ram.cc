#include "../lib/Ram.h"

/// @brief Ejecuta una instrucción dada y actualiza el contador de programa si es necesario.
/// @param instruction La instrucción a ejecutar.
/// @param program_counter El contador de programa que se actualizará si la instrucción es un salto.
void Ram::executeInstruction(const std::string& instruction, int& program_counter) {
  std::istringstream iss(instruction);
  std::string opcode;
  iss >> opcode;

  if (opcode == "load" || opcode == "LOAD") {
    int op_type;
    std::string op;
    iss >> op;
    if (op[0] == '=') {
      op_type = 0;
      op.erase(0, 1); 
    } else if (op[0] == '*') {
      op_type = 2;
      op.erase(0, 1); 
    } else {
      op_type = 1;
    }
    int op_value = std::stoi(op);
    std::cout << "LOAD operation type: " << op_type << ", operand value: " << op_value << std::endl;
    logic_unit_.Load(op_type, op_value);
  } else if (opcode == "store" || opcode == "STORE") {
    int op_type;
    std::string op;
    iss >> op;
    if (op[0] == '=') {
      op_type = 0;
      op.erase(0, 1); 
    } else if (op[0] == '*') {
      op_type = 2;
      op.erase(0, 1); 
    } else {
      op_type = 1;
    }
    int op_value = std::stoi(op);
    logic_unit_.Store(op_type, op_value);
  } else if (opcode == "add" || opcode == "ADD") {
    int op_type;
    std::string op;
    iss >> op;
    if (op[0] == '=') {
      op_type = 0;
      op.erase(0, 1); 
    } else if (op[0] == '*') {
      op_type = 2;
      op.erase(0, 1); 
    } else {
      op_type = 1;
    }
    int op_value = std::stoi(op);
    logic_unit_.Add(op_type, op_value);
  } else if (opcode == "sub" || opcode == "SUB") {
    int op_type;
    std::string op;
    iss >> op;
    if (op[0] == '=') {
      op_type = 0;
      op.erase(0, 1); 
    } else if (op[0] == '*') {
      op_type = 2;
      op.erase(0, 1); 
    } else {
      op_type = 1;
    }
    int op_value = std::stoi(op);
    logic_unit_.Sub(op_type, op_value);
  } else if (opcode == "mul" || opcode == "MUL") {
    int op_type;
    std::string op;
    iss >> op;
    if (op[0] == '=') {
      op_type = 0;
      op.erase(0, 1); 
    } else if (op[0] == '*') {
      op_type = 2;
      op.erase(0, 1); 
    } else {
      op_type = 1;
    }
    int op_value = std::stoi(op);
    logic_unit_.Mult(op_type, op_value);
  } else if (opcode == "div" || opcode == "DIV") {
    int op_type;
    std::string op;
    iss >> op;
    if (op[0] == '=') {
      op_type = 0;
      op.erase(0, 1); 
    } else if (op[0] == '*') {
      op_type = 2;
      op.erase(0, 1); 
    } else {
      op_type = 1;
    }
    int op_value = std::stoi(op);
    logic_unit_.Div(op_type, op_value);
  } else if (opcode == "read" || opcode == "READ") {
    int op;
    iss >> op;
    logic_unit_.Read(op);
  } else if (opcode == "write" || opcode == "WRITE") {
    int op_type;
    std::string op;
    iss >> op;
    if (op[0] == '=') {
      op_type = 0;
      op.erase(0, 1); 
    } else if (op[0] == '*') {
      op_type = 2;
      op.erase(0, 1); 
    } else {
      op_type = 1;
    }
    int op_value = std::stoi(op);
    logic_unit_.Write(op_type, op_value);
  } else if (opcode == "jump" || opcode == "JUMP") {
    std::string label;
    iss >> label;
    logic_unit_.Jump(label, program_counter);
  } else if (opcode == "jzero" || opcode == "JZERO") {
    std::string label;
    iss >> label;
    logic_unit_.JumpZero(label, program_counter);
  } else if (opcode == "jgtz" || opcode == "JGTZ") {
    std::string label;
    iss >> label;
    logic_unit_.JumpGreaterThanZero(label, program_counter);
  } else if (opcode == "halt" || opcode == "HALT") {
    std::cout << "Program halted." << std::endl;
    return;
  } else {
    std::cerr << "Unknown instruction: " << opcode << std::endl;
  }
}