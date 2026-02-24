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
#include "LogicUnitAbstract.h"

class LogicUnitDinamic : public LogicUnitAbstract{
  public:
    LogicUnitDinamic(DataMemoryDinamic* data_memory, ProgramMemory* program_memory, InputTape* input_tape, OutputTape* output_tape) : data_memory_(data_memory), program_memory_(program_memory), input_tape_(input_tape), output_tape_(output_tape) {} 
    void Load(const InstructionContext& context) override;
    void Store(const InstructionContext& context) override;
    void Add(const InstructionContext& context) override;
    void Sub(const InstructionContext& context) override;
    void Mult(const InstructionContext& context) override;
    void Div(const InstructionContext& context) override;
    void Read(const InstructionContext& context) override;
    void Write(const InstructionContext& context) override;
    void Jump(const InstructionContext& context) override;
    void JumpZero(const InstructionContext& context) override;
    void JumpGreaterThanZero(const InstructionContext& context) override;
    
  private:
    DataMemoryDinamic* data_memory_; 
    OutputTape* output_tape_; 
    InputTape* input_tape_; 
    ProgramMemory* program_memory_;
};

#endif //LOGICUNITDINAMIC_H_
