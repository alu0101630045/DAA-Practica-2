/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionJump.cc
 * @desc Implementación de la instrucción Jump para memoria estática.
 *
 */

#include "../lib/InstructionJump.h"

InstructionJump::InstructionJump(ProgramMemory* program_memory)
    : program_memory_(program_memory) {}

void InstructionJump::execute(const InstructionContext& context) {
  int jump_address = program_memory_->getLabels()[context.label];
  *(context.program_counter) = jump_address - 1;
}
