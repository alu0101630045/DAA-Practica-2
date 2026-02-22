#ifndef LOGICUNIT_H_
#define LOGICUNIT_H_

#include "DataMemory.h"
#include "ProgramMemory.h"
#include "Tape.h"


class LogicUnit {
  public:
    LogicUnit(DataMemory* data_memory, ProgramMemory* program_memory, InputTape* input_tape, OutputTape* output_tape) : data_memory_(data_memory), program_memory_(program_memory), input_tape_(input_tape), output_tape_(output_tape) {}
    void Load(const int op_type, const int op);
    void Store(const int op_type, const int op);
    void Add(const int op_type, const int op);
    void Sub(const int op_type, const int op);
    void Mult(const int op_type, const int op);
    void Div(const int op_type, const int op);
    void Read(const int op);
    void Write(const int op_type, const int op);
    void Jump(const std::string label, int& program_counter);
    void JumpZero(const std::string label, int& program_counter);
    void JumpGreaterThanZero(const std::string label, int& program_counter);      
  private:
    DataMemory* data_memory_; 
    ProgramMemory* program_memory_;
    OutputTape* output_tape_;
    InputTape* input_tape_;
};



#endif //LOGICUNIT_H_
