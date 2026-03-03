/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionDivDinamic.h
 * @desc Declaración de la instrucción Div para memoria dinámica.
 *
 */
#ifndef INSTRUCTIONDIVDINAMIC_H_
#define INSTRUCTIONDIVDINAMIC_H_

#include "Instruction.h"
#include "DataMemoryDinamic.h"

class InstructionDivDinamic : public Instruction {
  public:
    InstructionDivDinamic(DataMemoryDinamic* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemoryDinamic* data_memory_;
};

#endif // INSTRUCTIONDIVDINAMIC_H_
