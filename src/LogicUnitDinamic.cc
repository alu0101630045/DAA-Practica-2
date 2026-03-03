/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file LogicUnitDinamic.cc
 * @desc Implementación de la unidad lógica para memoria dinámica.
 *
 */
#include "../lib/LogicUnitDinamic.h"
#include "../lib/InstructionLoadDinamic.h"
#include "../lib/InstructionStoreDinamic.h"
#include "../lib/InstructionAddDinamic.h"
#include "../lib/InstructionSubDinamic.h"
#include "../lib/InstructionMultDinamic.h"
#include "../lib/InstructionDivDinamic.h"
#include "../lib/InstructionReadDinamic.h"
#include "../lib/InstructionWriteDinamic.h"
#include "../lib/InstructionJump.h"                // JUMP does not depend on memory type
#include "../lib/InstructionJumpZero.h"
#include "../lib/InstructionJumpGreaterThanZero.h"
#include "../lib/InstructionJumpZeroDinamic.h"
#include "../lib/InstructionJumpGreaterThanZeroDinamic.h"

LogicUnitDinamic::LogicUnitDinamic(DataMemoryDinamic* data_memory,
                                   ProgramMemory* program_memory,
                                   InputTape* input_tape,
                                   OutputTape* output_tape)
    : data_memory_(data_memory),
      output_tape_(output_tape),
      input_tape_(input_tape),
      program_memory_(program_memory) {
  instructions_["LOAD"] = new InstructionLoadDinamic(data_memory_);
  instructions_["STORE"] = new InstructionStoreDinamic(data_memory_);
  instructions_["ADD"] = new InstructionAddDinamic(data_memory_);
  instructions_["SUB"] = new InstructionSubDinamic(data_memory_);
  instructions_["MUL"] = new InstructionMultDinamic(data_memory_);
  instructions_["DIV"] = new InstructionDivDinamic(data_memory_);
  instructions_["READ"] = new InstructionReadDinamic(data_memory_, input_tape_);
  instructions_["WRITE"] = new InstructionWriteDinamic(data_memory_, output_tape_);
  instructions_["JUMP"] = new InstructionJump(program_memory_);
  instructions_["JZERO"] = new InstructionJumpZeroDinamic(program_memory_, data_memory_);
  instructions_["JGTZ"] = new InstructionJumpGreaterThanZeroDinamic(program_memory_, data_memory_);
}

LogicUnitDinamic::~LogicUnitDinamic() {
  for (auto& pair : instructions_) {
    delete pair.second;
  }
}

void LogicUnitDinamic::execute(const std::string& opcode,
                               const InstructionContext& context) {
  auto it = instructions_.find(opcode);
  if (it == instructions_.end()) {
    std::cerr << "Fatal ERROR: Ilegal instruction -> '" << opcode << "'" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  it->second->execute(context);
}
