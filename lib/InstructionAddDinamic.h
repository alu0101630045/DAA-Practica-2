/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionAddDinamic.h
 * @desc Declaración de la instrucción Add para memoria dinámica.
 *
 */
#ifndef INSTRUCTIONADDDINAMIC_H_
#define INSTRUCTIONADDDINAMIC_H_

#include "Instruction.h"
#include "DataMemoryDinamic.h"

class InstructionAddDinamic : public Instruction {
  public:
    InstructionAddDinamic(DataMemoryDinamic* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemoryDinamic* data_memory_;
};

#endif // INSTRUCTIONADDDINAMIC_H_
