#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class InputTape {
  public:
    InputTape(const std::string filename);
    int read() const;
    void moveRight() { position++; }
    int getPosition() const { return position; }
  private:
    std::vector<int> tape;
    int position;
};

class OutputTape {
  public:
    OutputTape();
    void write(const int data);
    void printOutputFile(const std::string filename) const;
    void moveRight() { position++; }
    std::vector<int> getOutput() const;
  private:
    std::vector<int> tape;
    int position;
};

#endif // TAPE_H