/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionJumpGreaterThanZeroDinamic.h
 * @desc Declaración de la instrucción JumpGreaterThanZero para memoria dinámica.
 *
 */
#ifndef INSTRUCTIONJUMPGREATERTHANZERODINAMIC_H_
#define INSTRUCTIONJUMPGREATERTHANZERODINAMIC_H_

#include "Instruction.h"
#include "ProgramMemory.h"
#include "DataMemoryDinamic.h"

class InstructionJumpGreaterThanZeroDinamic : public Instruction {
  public:
    InstructionJumpGreaterThanZeroDinamic(ProgramMemory* program_memory, DataMemoryDinamic* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    ProgramMemory* program_memory_;
    DataMemoryDinamic* data_memory_;
};

#endif // INSTRUCTIONJUMPGREATERTHANZERODINAMIC_H_
