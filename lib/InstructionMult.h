/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionMult.h
 * @desc Declaración de la instrucción Mult para memoria estática.
 *
 */
#ifndef INSTRUCTIONMULT_H_
#define INSTRUCTIONMULT_H_

#include "Instruction.h"
#include "DataMemory.h"

class InstructionMult : public Instruction {
  public:
    InstructionMult(DataMemory* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemory* data_memory_;
};

#endif // INSTRUCTIONMULT_H_
