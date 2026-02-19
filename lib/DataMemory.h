#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <iostream>
#include <vector>

class DataMemory {
  public:
    DataMemory();
    int read(const int address) const;
    void write(const int address, const int data);
  private:
    std::vector<int> memory;
};

#endif // DATA_MEMORY_H