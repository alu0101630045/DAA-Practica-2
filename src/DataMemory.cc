/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file DataMemory.cc
 * @desc Implementación de los métodos de la clase DataMemory (memoria estática).
 *
 */

#include "../lib/DataMemory.h"

DataMemory::DataMemory() {
  memory.resize(20, 0); 
}

/// @brief Lee el valor almacenado en la dirección especificada. 
/// @param address 
/// @return El valor almacenado en la dirección especificada o -1 si la dirección es inválida. 
int DataMemory::read(const int address) const {
  if (address >= 0 && address < memory.size()) {
    return memory[address];
  }
  return -1; 
}

/// @brief Escribe un valor en la dirección especificada. Si la dirección es inválida, no se realiza ninguna operación.
/// @param address 
/// @param data 
void DataMemory::write(const int address, const int data) {
  if (address >= 0 && address < memory.size()) {
    memory[address] = data;
  }
}