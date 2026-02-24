/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file main.cc
 * @desc Función principal que inicializa y ejecuta la máquina RAM.
 *
 */
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


int main(int argc, char* argv[]) {
  std::string input_tape_filename = argv[1];
  std::string output_tape_filename = argv[2];
  std::string ram_filename;
  int mode = 0;
  MostrarMenu(ram_filename, mode);

  InputTape input(input_tape_filename);
  OutputTape output;
  ProgramMemory program(ram_filename);

  DataMemoryDinamic data_memory_dinamic;
  LogicUnitDinamic logic_unit_dinamic(&data_memory_dinamic, &program, &input, &output);

  DataMemory data_memory_static;
  LogicUnit logic_unit_static(&data_memory_static, &program, &input, &output);

  LogicUnitAbstract* logic_unit_ptr = nullptr;

  if (mode == 1) {
    std::cout << "\nIniciando en modo DINÁMICO..." << std::endl;
    logic_unit_ptr = &logic_unit_dinamic;
  } else {
    std::cout << "\nIniciando en modo ESTÁTICO..." << std::endl;
    logic_unit_ptr = &logic_unit_static;
  }

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
  output.printOutputFile(output_tape_filename);

  std::cout << "========================================" << std::endl;
  std::cout << "Total de saltos e instrucciones ejecutadas: " << instruction_count << std::endl;
  std::cout << "Resultados guardados con éxito en '" << output_tape_filename << "'." << std::endl;
  std::cout << "========================================\n" << std::endl;

  return 0;
}