/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionJumpGreaterThanZeroDinamic.cc
 * @desc Implementación de la instrucción JumpGreaterThanZero para memoria dinámica.
 *
 */

#include "../lib/InstructionJumpGreaterThanZeroDinamic.h"

InstructionJumpGreaterThanZeroDinamic::InstructionJumpGreaterThanZeroDinamic(
    ProgramMemory* program_memory, DataMemoryDinamic* data_memory)
    : program_memory_(program_memory), data_memory_(data_memory) {}

void InstructionJumpGreaterThanZeroDinamic::execute(const InstructionContext& context) {
  if (data_memory_->read(0, 0) > 0) {
    int jump_address = program_memory_->getLabels()[context.label];
    *(context.program_counter) = jump_address - 1;
  }
}
