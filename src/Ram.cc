#include "../lib/Ram.h"

/// @brief Ejecuta una instrucción dada y actualiza el contador de programa si es necesario.
/// @param instruction La instrucción a ejecutar.
/// @param program_counter El contador de programa que se actualizará si la instrucción es un salto.
void Ram::executeInstruction(const std::string& instruction, int& program_counter) {
  std::istringstream iss(instruction);
  std::string opcode;
  iss >> opcode;

  if (opcode == "load") {
    int op_type;
    std::string op;
    iss >> op;
    if (op[0] == '=') {
      op_type = 0;
      op.erase(0, 1); // Remove '=' from the operand
    } else if (op[0] == '*') {
      op_type = 2;
      op.erase(0, 1); // Remove '*' from the operand
    } else {
      op_type = 1;
    }
    int op_value = std::stoi(op);
    logic_unit_.Load(op_type, op_value);
  } else if (opcode == "store") {
    int op_type, op;
    iss >> op_type >> op;
    logic_unit_.Store(op_type, op);
  } else if (opcode == "add") {
    int op_type, op;
    iss >> op_type >> op;
    logic_unit_.Add(op_type, op);
  } else if (opcode == "sub") {
    int op_type, op;
    iss >> op_type >> op;
    logic_unit_.Sub(op_type, op);
  } else if (opcode == "mult") {
    int op_type, op;
    iss >> op_type >> op;
    logic_unit_.Mult(op_type, op);
  } else if (opcode == "div") {
    int op_type, op;
    iss >> op_type >> op;
    logic_unit_.Div(op_type, op);
  } else if (opcode == "read") {
    int op;
    iss >> op;
    logic_unit_.Read(op);
  } else if (opcode == "write") {
    int op;
    iss >> op;
    logic_unit_.Write(op);
  } else if (opcode == "jump") {
    std::string label;
    iss >> label;
    logic_unit_.Jump(label, program_counter);
  } else if (opcode == "jzero") {
    std::string label;
    iss >> label;
    logic_unit_.JumpZero(label, program_counter);
  } else if (opcode == "jgtz") {
    std::string label;
    iss >> label;
    logic_unit_.JumpGreaterThanZero(label, program_counter);
  } else if (opcode == "halt") {
    std::cout << "Program halted." << std::endl;
    return;
  } else {
    std::cerr << "Unknown instruction: " << opcode << std::endl;
  }
}