/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionJump.h
 * @desc Declaración de la instrucción Jump (saltos) para memoria estática.
 *
 */
#ifndef INSTRUCTIONJUMP_H_
#define INSTRUCTIONJUMP_H_

#include "Instruction.h"
#include "ProgramMemory.h"

class InstructionJump : public Instruction {
  public:
    InstructionJump(ProgramMemory* program_memory);
    void execute(const InstructionContext& context) override;

  private:
    ProgramMemory* program_memory_;
};

#endif // INSTRUCTIONJUMP_H_
