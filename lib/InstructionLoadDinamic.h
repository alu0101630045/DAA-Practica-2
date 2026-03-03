/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionLoadDinamic.h
 * @desc Declaración de la instrucción Load para memoria dinámica.
 *
 */
#ifndef INSTRUCTIONLOADDINAMIC_H_
#define INSTRUCTIONLOADDINAMIC_H_

#include "Instruction.h"
#include "DataMemoryDinamic.h"

class InstructionLoadDinamic : public Instruction {
  public:
    InstructionLoadDinamic(DataMemoryDinamic* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemoryDinamic* data_memory_;
};

#endif // INSTRUCTIONLOADDINAMIC_H_
