/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionJumpZeroDinamic.h
 * @desc Declaración de la instrucción JumpZero para memoria dinámica.
 *
 */
#ifndef INSTRUCTIONJUMPZERODINAMIC_H_
#define INSTRUCTIONJUMPZERODINAMIC_H_

#include "Instruction.h"
#include "ProgramMemory.h"
#include "DataMemoryDinamic.h"

class InstructionJumpZeroDinamic : public Instruction {
  public:
    InstructionJumpZeroDinamic(ProgramMemory* program_memory, DataMemoryDinamic* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    ProgramMemory* program_memory_;
    DataMemoryDinamic* data_memory_;
};

#endif // INSTRUCTIONJUMPZERODINAMIC_H_
