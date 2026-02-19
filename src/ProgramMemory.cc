#include "../lib/ProgramMemory.h"

/// @brief Constructor de la clase ProgramMemory
/// @param filename El nombre del archivo que contiene las instrucciones del programa.
ProgramMemory::ProgramMemory(const std::string filename) {
  std::ifstream is(filename);
  std::string line;
  while (std::getline(is, line)) {
    line.erase(0, line.find_first_not_of(" \t"));
    if (!line.empty() && line[0] != '#') {
      instructions.push_back(line);
    }
  }
}