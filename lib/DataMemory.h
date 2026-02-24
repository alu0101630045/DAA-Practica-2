/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file DataMemory.h
 * @desc Declaración de la clase DataMemory (memoria estática).
 *
 */
#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <iostream>
#include <vector>

class DataMemory {
  public:
    DataMemory();
    int read(const int address) const;
    void write(const int address, const int data);
  private:
    std::vector<int> memory;
};

#endif // DATA_MEMORY_H