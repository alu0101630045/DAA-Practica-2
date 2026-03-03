/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file LogicUnitDinamic.h
 * @desc Declaración de la unidad lógica para memoria dinámica.
 *
 */
#ifndef LOGICUNITDINAMIC_H_
#define LOGICUNITDINAMIC_H_

#include "DataMemoryDinamic.h"
#include "ProgramMemory.h"
#include "Tape.h"
#include "Instruction.h"
#include "LogicUnitAbstract.h"

#include <map>
#include <string>

class LogicUnitDinamic : public LogicUnitAbstract{
  public:
    LogicUnitDinamic(DataMemoryDinamic* data_memory, ProgramMemory* program_memory, InputTape* input_tape, OutputTape* output_tape);
    ~LogicUnitDinamic() override;

    void execute(const std::string& opcode,
                 const InstructionContext& context) override;
    
  private:
    DataMemoryDinamic* data_memory_; 
    OutputTape* output_tape_; 
    InputTape* input_tape_; 
    ProgramMemory* program_memory_;
    std::map<std::string, Instruction*> instructions_;
};

#endif //LOGICUNITDINAMIC_H_
