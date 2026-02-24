/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file Tape.cc
 * @desc Manejo de cintas de entrada y salida.
 *
 */
#include "../lib/Tape.h"

InputTape::InputTape(const std::string filename) {
  std::ifstream is(filename);
  std::string line;
  is >> line;
  for (int i = 0; i < line.size(); i++) {
    int actual = line[i] - '0'; 
    tape.push_back(actual);
  }
  position = 0;
}

/// @brief Lee el valor en la posición actual de la cinta de entrada. Si la posición actual es mayor o igual al tamaño de la cinta, devuelve -1. 
/// @return El valor en la posición actual de la cinta de entrada o -1 si se ha alcanzado el final de la cinta. 
int InputTape::read() const {
    if (getPosition() < tape.size()) {
        return tape[getPosition()];
    }
    return -1; 
}

OutputTape::OutputTape() {}

/// @brief Escribe un valor en la posición actual de la cinta de salida. El valor se agrega al final de la cinta. 
/// @param data  
void OutputTape::write(const int data) {
  tape.push_back(data);
}

/// @brief Devuelve el contenido de la cinta de salida. 
/// @return El contenido de la cinta de salida. 
std::vector<int> OutputTape::getOutput() const {
  return tape;
}

/// @brief Imprime el contenido de la cinta de salida en un archivo. Cada valor se escribe en una nueva línea.
/// @param filename El nombre del archivo donde se imprimirá el contenido de la cinta de salida.
void OutputTape::printOutputFile(const std::string filename) const {
  std::ofstream os(filename);
  for (const auto& value : tape) {
    os << value;
  }
}