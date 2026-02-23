#ifndef DATAMEMORYDINAMIC_H_
#define DATAMEMORYDINAMIC_H_

#include <vector>

class DataMemoryDinamic {
  public:
    DataMemoryDinamic();
    int read(const int regist, const int pos) const;
    void write(const int regist, const int pos, const int data);

  private:
    std::vector<std::vector<int>> memory_; 
};

#endif //DATAMEMORYDINAMIC_H_
