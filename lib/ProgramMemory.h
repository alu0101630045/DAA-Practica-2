/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file ProgramMemory.h
 * @desc Declaración de la clase ProgramMemory para gestionar instrucciones.
 *
 */
#ifndef PROGRAM_MEMORY_H
#define PROGRAM_MEMORY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

class ProgramMemory {
  public:
    ProgramMemory(const std::string filename);
    void printLabels() const;
    std::vector<std::string> getInstructions() const { return instructions; }
    std::map<std::string, int> getLabels() const { return labels; }
  private:
    std::vector<std::string> instructions;
    std::map<std::string, int> labels;
};

#endif