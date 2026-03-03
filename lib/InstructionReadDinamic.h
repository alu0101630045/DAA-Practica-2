/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionReadDinamic.h
 * @desc Declaración de la instrucción Read para memoria dinámica.
 *
 */
#ifndef INSTRUCTIONREADDINAMIC_H_
#define INSTRUCTIONREADDINAMIC_H_

#include "Instruction.h"
#include "DataMemoryDinamic.h"
#include "Tape.h"

class InstructionReadDinamic : public Instruction {
  public:
    InstructionReadDinamic(DataMemoryDinamic* data_memory, InputTape* input_tape);
    void execute(const InstructionContext& context) override;

  private:
    DataMemoryDinamic* data_memory_;
    InputTape* input_tape_;
};

#endif // INSTRUCTIONREADDINAMIC_H_
