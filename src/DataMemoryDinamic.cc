/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file DataMemoryDinamic.cc
 * @desc Implementación de los métodos de la clase DataMemoryDinamic (memoria dinámica).
 *
 */
#include "../lib/DataMemoryDinamic.h"

DataMemoryDinamic::DataMemoryDinamic() {
  memory_.resize(100);
  memory_[0].resize(1, 0);
  for (int i = 1; i < memory_.size(); ++i) {
    memory_[i].resize(100, 0);
  }
}

int DataMemoryDinamic::read(const int regist, const int pos) const {
  if (regist < 0 || regist >= memory_.size() || pos < 0 || pos >= memory_[regist].size()) {
    std::cerr << "Error: Índice fuera de rango en lectura de memoria." << std::endl;
    return -1;
  }
  return memory_[regist][pos];
}

void DataMemoryDinamic::write(const int regist, const int pos, const int data) {
  if (regist < 0 || regist >= memory_.size() || pos < 0 || pos >= memory_[regist].size()) {
    std::cerr << "Error: Índice fuera de rango en escritura de memoria." << std::endl;
    return;
  }
  memory_[regist][pos] = data;
}
