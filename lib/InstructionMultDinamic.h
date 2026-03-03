/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionMultDinamic.h
 * @desc Declaración de la instrucción Mult para memoria dinámica.
 *
 */
#ifndef INSTRUCTIONMULTDINAMIC_H_
#define INSTRUCTIONMULTDINAMIC_H_

#include "Instruction.h"
#include "DataMemoryDinamic.h"

class InstructionMultDinamic : public Instruction {
  public:
    InstructionMultDinamic(DataMemoryDinamic* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemoryDinamic* data_memory_;
};

#endif // INSTRUCTIONMULTDINAMIC_H_
