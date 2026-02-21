#ifndef LOGICUNIT_H_
#define LOGICUNIT_H_

#include "DataMemory.h"


class LogicUnit {
  public:
    LogicUnit(DataMemory* data_memory) : data_memory_(data_memory) {};
    void Load(const int op_type, const int op);
    void Store(const int op_type, const int op);
    void Add(const int op_type, const int op);
    void Sub(const int op_type, const int op);
    void Mult(const int op_type, const int op);
    void Div(const int op_type, const int op);

  private:
    DataMemory* data_memory_; 
};



#endif //LOGICUNIT_H_
