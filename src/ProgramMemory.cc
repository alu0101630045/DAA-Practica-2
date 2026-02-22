#include "../lib/ProgramMemory.h"

/// @brief Constructor de la clase ProgramMemory
/// @param filename El nombre del archivo que contiene las instrucciones del programa.
ProgramMemory::ProgramMemory(const std::string filename) {
  std::ifstream is(filename);
  if (!is.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return;
  }
  std::string line;
  int line_counter = 0;
  while (std::getline(is, line)) {
    line.erase(0, line.find_first_not_of(" \t"));
    if (line.empty() || line[0] == '#') {
      continue;
    }
    if (line.find(':') != std::string::npos) {
      std::string label = line.substr(0, line.find(':'));
      label.erase(label.find_last_not_of(" \t") + 1);
      labels[label] = line_counter;
      line = line.substr(line.find(':') + 1);
      line.erase(0, line.find_first_not_of(" \t"));
    }
    instructions.push_back(line);
    line_counter++;
  }
}

/// @brief Imprime las etiquetas almacenadas en la memoria del programa.
void ProgramMemory::printLabels() const {
  std::cout << "Labels in Program Memory:" << std::endl;
  for (const auto& label : labels) {
    std::cout << label.first << ": " << label.second << std::endl;
  }
}