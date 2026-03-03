/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionJumpZero.h
 * @desc Declaración de la instrucción JumpZero para memoria estática.
 *
 */
#ifndef INSTRUCTIONJUMPZERO_H_
#define INSTRUCTIONJUMPZERO_H_

#include "Instruction.h"
#include "ProgramMemory.h"
#include "DataMemory.h"

class InstructionJumpZero : public Instruction {
  public:
    InstructionJumpZero(ProgramMemory* program_memory, DataMemory* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    ProgramMemory* program_memory_;
    DataMemory* data_memory_;
};

#endif // INSTRUCTIONJUMPZERO_H_
