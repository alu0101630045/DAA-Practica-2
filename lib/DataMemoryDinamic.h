/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file DataMemoryDinamic.h
 * @desc Declaración de la clase DataMemoryDinamic (memoria dinámica).
 *
 */
#ifndef DATAMEMORYDINAMIC_H_
#define DATAMEMORYDINAMIC_H_

#include <vector>

class DataMemoryDinamic {
  public:
    DataMemoryDinamic();
    int read(const int regist, const int pos) const;
    void write(const int regist, const int pos, const int data);

  private:
    std::vector<std::vector<int>> memory_; 
};

#endif //DATAMEMORYDINAMIC_H_
