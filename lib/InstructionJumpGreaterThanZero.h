/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionJumpGreaterThanZero.h
 * @desc Declaración de la instrucción JumpGreaterThanZero para memoria estática.
 *
 */
#ifndef INSTRUCTIONJUMPGREATERTHANZERO_H_
#define INSTRUCTIONJUMPGREATERTHANZERO_H_

#include "Instruction.h"
#include "ProgramMemory.h"
#include "DataMemory.h"

class InstructionJumpGreaterThanZero : public Instruction {
  public:
    InstructionJumpGreaterThanZero(ProgramMemory* program_memory, DataMemory* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    ProgramMemory* program_memory_;
    DataMemory* data_memory_;
};

#endif // INSTRUCTIONJUMPGREATERTHANZERO_H_
