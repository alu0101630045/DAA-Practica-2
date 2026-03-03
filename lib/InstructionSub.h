/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionSub.h
 * @desc Declaración de la instrucción Sub para memoria estática.
 *
 */
#ifndef INSTRUCTIONSUB_H_
#define INSTRUCTIONSUB_H_

#include "Instruction.h"
#include "DataMemory.h"

class InstructionSub : public Instruction {
  public:
    InstructionSub(DataMemory* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemory* data_memory_;
};

#endif // INSTRUCTIONSUB_H_
