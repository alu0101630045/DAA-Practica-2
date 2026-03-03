/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionStore.h
 * @desc Declaración de la instrucción Store para memoria estática.
 *
 */
#ifndef INSTRUCTIONSTORE_H_
#define INSTRUCTIONSTORE_H_

#include "Instruction.h"
#include "DataMemory.h"

class InstructionStore : public Instruction {
  public:
    InstructionStore(DataMemory* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemory* data_memory_;
};

#endif // INSTRUCTIONSTORE_H_
