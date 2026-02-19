#ifndef PROGRAM_MEMORY_H
#define PROGRAM_MEMORY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class ProgramMemory {
  public:
    ProgramMemory(const std::string filename);
    std::vector<std::string> getInstructions() const { return instructions; }
  private:
    std::vector<std::string> instructions;
    std::vector<std::pair<std::string, int>> labels;
};

#endif