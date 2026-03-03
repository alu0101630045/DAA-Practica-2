/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionDiv.h
 * @desc Declaración de la instrucción Div para memoria estática.
 *
 */
#ifndef INSTRUCTIONDIV_H_
#define INSTRUCTIONDIV_H_

#include "Instruction.h"
#include "DataMemory.h"

class InstructionDiv : public Instruction {
  public:
    InstructionDiv(DataMemory* data_memory);
    void execute(const InstructionContext& context) override;

  private:
    DataMemory* data_memory_;
};

#endif // INSTRUCTIONDIV_H_
