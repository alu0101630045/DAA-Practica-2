/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file LogicUnit.cc
 * @desc Implementación de la unidad lógica para memoria estática.
 *
 */
#include "../lib/LogicUnit.h"
#include "../lib/InstructionLoad.h"
#include "../lib/InstructionStore.h"
#include "../lib/InstructionAdd.h"
#include "../lib/InstructionSub.h"
#include "../lib/InstructionMult.h"
#include "../lib/InstructionDiv.h"
#include "../lib/InstructionRead.h"
#include "../lib/InstructionWrite.h"
#include "../lib/InstructionJump.h"
#include "../lib/InstructionJumpZero.h"
#include "../lib/InstructionJumpGreaterThanZero.h"

#include <algorithm>
#include <iostream>

LogicUnit::LogicUnit(DataMemory* data_memory,
                     ProgramMemory* program_memory,
                     InputTape* input_tape,
                     OutputTape* output_tape)
    : data_memory_(data_memory),
      output_tape_(output_tape),
      input_tape_(input_tape),
      program_memory_(program_memory) {
  // Register strategies
  instructions_["LOAD"] = new InstructionLoad(data_memory_);
  instructions_["STORE"] = new InstructionStore(data_memory_);
  instructions_["ADD"] = new InstructionAdd(data_memory_);
  instructions_["SUB"] = new InstructionSub(data_memory_);
  instructions_["MUL"] = new InstructionMult(data_memory_);
  instructions_["DIV"] = new InstructionDiv(data_memory_);
  instructions_["READ"] = new InstructionRead(data_memory_, input_tape_);
  instructions_["WRITE"] = new InstructionWrite(data_memory_, output_tape_);
  instructions_["JUMP"] = new InstructionJump(program_memory_);
  instructions_["JZERO"] = new InstructionJumpZero(program_memory_, data_memory_);
  instructions_["JGTZ"] = new InstructionJumpGreaterThanZero(program_memory_, data_memory_);
}

LogicUnit::~LogicUnit() {
  for (auto& pair : instructions_) {
    delete pair.second;
  }
}

void LogicUnit::execute(const std::string& opcode,
                        const InstructionContext& context) {
  auto it = instructions_.find(opcode);
  if (it == instructions_.end()) {
    std::cerr << "Fatal ERROR: Ilegal instruction -> '" << opcode << "'" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  it->second->execute(context);
}
