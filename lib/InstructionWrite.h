/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionWrite.h
 * @desc Declaración de la instrucción Write para memoria estática.
 *
 */
#ifndef INSTRUCTIONWRITE_H_
#define INSTRUCTIONWRITE_H_

#include "Instruction.h"
#include "DataMemory.h"
#include "Tape.h"

class InstructionWrite : public Instruction {
  public:
    InstructionWrite(DataMemory* data_memory, OutputTape* output_tape);
    void execute(const InstructionContext& context) override;

  private:
    DataMemory* data_memory_;
    OutputTape* output_tape_;
};

#endif // INSTRUCTIONWRITE_H_
