/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file LogicUnit.h
 * @desc Declaración de la unidad lógica para memoria estática.
 *
 */
#ifndef LOGICUNIT_H_
#define LOGICUNIT_H_

#include "DataMemory.h"
#include "ProgramMemory.h"
#include "Tape.h"
#include "Instruction.h"

#include "LogicUnitAbstract.h"

#include <map>
#include <string>

class LogicUnit : public LogicUnitAbstract{
  public:
    LogicUnit(DataMemory* data_memory, ProgramMemory* program_memory, InputTape* input_tape, OutputTape* output_tape);
    ~LogicUnit() override;

    /**
     * Ejecuta la instrucción identificada por 
     * `opcode` delegando a la estrategia correspondiente.
     */
    void execute(const std::string& opcode,
                 const InstructionContext& context) override;

  private:
    DataMemory* data_memory_; 
    OutputTape* output_tape_; 
    InputTape* input_tape_; 
    ProgramMemory* program_memory_;
    std::map<std::string, Instruction*> instructions_;
};



#endif //LOGICUNIT_H_
