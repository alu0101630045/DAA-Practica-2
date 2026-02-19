#include "../lib/Tape.h"

/// @brief Constructor de la clase Tape
Tape::Tape(const std::string filename) : position(0) {
  std::ifstream is(filename);
  std::string line;
  is >> line;
  for (int i = 0; i < line.size(); i++) {
    int actual = line[i] - '0'; 
    tape.push_back(actual);
  }
}

/// @brief Mueve la posición de la cinta a la derecha, si no se ha alcanzado el final de la cinta.
void Tape::moveRight() {
    if (position < tape.size() - 1) {
        position++;
    }
}

/// @brief Devuelve la posición actual de la cinta.
/// @return La posición actual de la cinta. 
int Tape::getPosition() const {
    return position;
}

InputTape::InputTape(const std::string filename) : Tape(filename) {
  tape = Tape(filename).getTape();
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

OutputTape::OutputTape() : Tape({}) {}

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