#include <iostream>
#include <fstream>
#include <string>
#include "../lib/Tape.h"
#include "../lib/ProgramMemory.h"
#include "../lib/Ram.h"
#include "../lib/DataMemoryDinamic.h"
#include "../lib/DataMemory.h"
#include "../lib/LogicUnitDinamic.h"
#include "../lib/LogicUnit.h"
#include "../lib/functions.h"


int main() {
  std::string ram_filename;
  int mode = 0;

  // Menu (se selecciona el programa RAM y si se quiere memoria estática o dinámica)
  MostrarMenu(ram_filename, mode);

  // 2. Inicialización compartida
  InputTape input("input_tape/input_tape1.txt");
  OutputTape output;
  ProgramMemory program(ram_filename);

  // Se instancian ambas memorias, dinámica y estática
  DataMemoryDinamic data_memory_dinamic;
  LogicUnitDinamic logic_unit_dinamic(&data_memory_dinamic, &program, &input, &output);

  DataMemory data_memory_static;
  LogicUnit logic_unit_static(&data_memory_static, &program, &input, &output);

  // Apuntamos al tipo de memoria elegido
  LogicUnitAbstract* logic_unit_ptr = nullptr;

  if (mode == 1) {
    std::cout << "\nIniciando en modo DINÁMICO..." << std::endl;
    logic_unit_ptr = &logic_unit_dinamic;
  } else {
    std::cout << "\nIniciando en modo ESTÁTICO..." << std::endl;
    logic_unit_ptr = &logic_unit_static;
  }

  // Instanciamos la maquina RAM
  Ram ram(logic_unit_ptr); 

  std::cout << "Ejecutando programa...\n" << std::endl;

  int program_counter = 0;
  int instruction_count = 0;

  while (program_counter < program.getInstructions().size()) { 
    std::string instruction = program.getInstructions()[program_counter];
    ram.executeInstruction(instruction, program_counter);
    program_counter++;
    instruction_count++;
  }
  
  // Se pone el resultado en la cinta de salida
  output.printOutputFile("output_tape/output_tape.out");

  std::cout << "========================================" << std::endl;
  std::cout << "Total de saltos e instrucciones ejecutadas: " << instruction_count << std::endl;
  std::cout << "Resultados guardados con éxito en 'output_tape/output_tape.out'." << std::endl;
  std::cout << "========================================\n" << std::endl;

  return 0;
}