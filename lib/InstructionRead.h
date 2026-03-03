/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionRead.h
 * @desc Declaración de la instrucción Read para memoria estática.
 *
 */
#ifndef INSTRUCTIONREAD_H_
#define INSTRUCTIONREAD_H_

#include "Instruction.h"
#include "DataMemory.h"
#include "Tape.h"

class InstructionRead : public Instruction {
  public:
    InstructionRead(DataMemory* data_memory, InputTape* input_tape);
    void execute(const InstructionContext& context) override;

  private:
    DataMemory* data_memory_;
    InputTape* input_tape_;
};

#endif // INSTRUCTIONREAD_H_
