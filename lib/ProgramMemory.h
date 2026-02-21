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