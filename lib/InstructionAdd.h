/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionAdd.h
 * @desc Declaración de la instrucción Add para memoria estática.
 *
 */
#ifndef INSTRUCTIONADD_H_
#define INSTRUCTIONADD_H_

#include "Instruction.h"
#include "DataMemory.h"

class InstructionAdd : public Instruction {
  public:
    InstructionAdd(DataMemory* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemory* data_memory_;
};

#endif // INSTRUCTIONADD_H_
