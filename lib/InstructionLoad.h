/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionLoad.h
 * @desc Declaración de la instrucción Load para memoria estática.
 *
 */
#ifndef INSTRUCTIONLOAD_H_
#define INSTRUCTIONLOAD_H_

#include "Instruction.h"
#include "DataMemory.h"
#include "ProgramMemory.h"
#include "Tape.h"

class InstructionLoad : public Instruction {
  public:
    InstructionLoad(DataMemory* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemory* data_memory_;
};

#endif // INSTRUCTIONLOAD_H_
