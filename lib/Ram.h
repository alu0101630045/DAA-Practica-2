#ifndef RAM_H
#define RAM_H

#include "LogicUnitAbstract.h"

class Ram {
  public:
    Ram(LogicUnitAbstract* logic_unit) : logic_unit_(logic_unit) {}
    void executeInstruction(const std::string& instruction, int& program_counter);
  private:
    LogicUnitAbstract* logic_unit_;
};

#endif // RAM_H