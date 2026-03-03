/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionStoreDinamic.h
 * @desc Declaración de la instrucción Store para memoria dinámica.
 *
 */
#ifndef INSTRUCTIONSTOREDINAMIC_H_
#define INSTRUCTIONSTOREDINAMIC_H_

#include "Instruction.h"
#include "DataMemoryDinamic.h"

class InstructionStoreDinamic : public Instruction {
  public:
    InstructionStoreDinamic(DataMemoryDinamic* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemoryDinamic* data_memory_;
};

#endif // INSTRUCTIONSTOREDINAMIC_H_
