#include "../lib/Tape.h"
#include "../lib/DataMemory.h"
#include "../lib/ProgramMemory.h"
#include "../lib/LogicUnit.h"
#include "../lib/Ram.h"

int main() {
  InputTape input("input_tape/input_tape1.txt");
  OutputTape output;
  DataMemory dataMemory;
  ProgramMemory program("programs/test1.ram");
  std::cout << "Program Instructions:" << std::endl;
  for (const auto& instruction : program.getInstructions()) {
    std::cout << instruction << std::endl;
  }
  LogicUnit logic_unit(&dataMemory, &program, &input, &output);
  Ram ram(logic_unit);
  int program_counter = 0;
  while (program_counter < program.getInstructions().size()) {
    std::string instruction = program.getInstructions()[program_counter];
    std::cout << "Executing instruction: " << instruction << std::endl;
    ram.executeInstruction(instruction, program_counter);
    program_counter++;
  }
  output.printOutputFile("output_tape/output_tape.out");
  return 0;
}
