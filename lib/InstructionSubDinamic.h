/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionSubDinamic.h
 * @desc Declaración de la instrucción Sub para memoria dinámica.
 *
 */
#ifndef INSTRUCTIONSUBDINAMIC_H_
#define INSTRUCTIONSUBDINAMIC_H_

#include "Instruction.h"
#include "DataMemoryDinamic.h"

class InstructionSubDinamic : public Instruction {
  public:
    InstructionSubDinamic(DataMemoryDinamic* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemoryDinamic* data_memory_;
};

#endif // INSTRUCTIONSUBDINAMIC_H_
