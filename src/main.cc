#include "../lib/Tape.h"
#include "../lib/DataMemory.h"
#include "../lib/ProgramMemory.h"
#include "../lib/LogicUnit.h"

int main() {
  InputTape input("input_tape/input_tape1.txt");
  OutputTape output;
  DataMemory dataMemory;
  ProgramMemory program("programs/test1.ram");
  LogicUnit logic_unit(&dataMemory);
  
  for (int i = 0; i < program.getInstructions().size(); i++) {
    std::string instruction = program.getInstructions()[i];
    std::cout << "Executing instruction: " << instruction << std::endl;
  }
  //te dejo las pruebas por si quieres ver que funciona bien, quitalas luego bebé

  // PRUEBAS INSTRUCCION LOAD
  dataMemory.write(10, 5);
  dataMemory.write(5, 8);
  logic_unit.Load(0, 20);
  //CONSTANTE
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  logic_unit.Load(1, 3);
  //DIRECTO
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  logic_unit.Load(2, 10);
  //INDIRECTO
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';

  //PRUEBAS INSTRUCCION LOAD
  logic_unit.Store(1, 11);
  std::cout << "El registro R11 contiene:" << dataMemory.read(11)<<'\n';
  logic_unit.Store(2, 11);
  std::cout << "El registro R8 contiene:" << dataMemory.read(8)<<'\n';


  //PRUEBAS INSTRUCCION ADD
  //CONSTANTE
  logic_unit.Add(0, 1);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  // DIRECTO
  logic_unit.Add(1, 10);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  // INDIRECTO
  logic_unit.Add(2, 10);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';

  //PRUEBAS INSTRUCCION SUB
  //CONSTANTE
  logic_unit.Sub(0,1);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  //Directo
  logic_unit.Sub(1, 10);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  //Indirecto
  logic_unit.Sub(2, 10);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';

  //PRUEBAS INSTRUCCION MULT
  //CONSTANTE
  logic_unit.Mult(0,2);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  //Directo
  logic_unit.Mult(1, 10);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  //Indirecto
  logic_unit.Mult(2, 10);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';


  //PRUEBAS INSTRUCCION DIV
  //CONSTANTE
  logic_unit.Div(0, 8);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  //Directo
  logic_unit.Div(1, 10);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  //Indirecto
  logic_unit.Div(2, 10);
  std::cout << "El registro R0 contiene:" << dataMemory.read(0)<<'\n';
  return 0;
}
