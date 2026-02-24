/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file Ram.h
 * @desc Declaración de la clase Ram que ejecuta instrucciones.
 *
 */
#ifndef RAM_H
#define RAM_H

#include "LogicUnitAbstract.h"

class Ram {
  public:
    Ram(LogicUnitAbstract* logic_unit) : logic_unit_(logic_unit) {}
    void executeInstruction(const std::string& instruction, int& program_counter);
  private:
    LogicUnitAbstract* logic_unit_;
};

#endif // RAM_H