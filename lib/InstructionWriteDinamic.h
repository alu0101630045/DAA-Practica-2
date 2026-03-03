/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionWriteDinamic.h
 * @desc Declaración de la instrucción Write para memoria dinámica.
 *
 */
#ifndef INSTRUCTIONWRITEDINAMIC_H_
#define INSTRUCTIONWRITEDINAMIC_H_

#include "Instruction.h"
#include "DataMemoryDinamic.h"
#include "Tape.h"

class InstructionWriteDinamic : public Instruction {
  public:
    InstructionWriteDinamic(DataMemoryDinamic* data_memory, OutputTape* output_tape);
    void execute(const InstructionContext& context) override;

  private:
    DataMemoryDinamic* data_memory_;
    OutputTape* output_tape_;
};

#endif // INSTRUCTIONWRITEDINAMIC_H_
