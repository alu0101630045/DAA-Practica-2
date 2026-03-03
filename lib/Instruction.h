/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file Instruction.h
 * @desc Interfaz abstracta para instrucciones (patrón estrategia).
 *
 */
#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "LogicUnitAbstract.h"

class Instruction {
  public:
    virtual ~Instruction() {}
    virtual void execute(const InstructionContext& context) = 0;
};

#endif // INSTRUCTION_H_
