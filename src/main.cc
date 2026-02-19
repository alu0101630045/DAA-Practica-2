#include "../lib/Tape.h"
#include "../lib/DataMemory.h"
#include "../lib/ProgramMemory.h"

int main() {
  InputTape input("input_tape/input_tape1.txt");
  OutputTape output;
  DataMemory dataMemory;
  ProgramMemory program("programs/test1.ram");
  for (int i = 0; i < program.getInstructions().size(); i++) {
    std::string instruction = program.getInstructions()[i];
    std::cout << "Executing instruction: " << instruction << std::endl;
  }

  return 0;
}