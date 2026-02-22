#ifndef RAM_H
#define RAM_H

#include "LogicUnit.h"

class Ram {
  public:
    Ram(LogicUnit logic_unit) : logic_unit_(logic_unit) {}
    void executeInstruction(const std::string& instruction, int& program_counter);
  private:
    LogicUnit logic_unit_;
};

#endif // RAM_H