#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Tape {
  public:
    Tape(const std::string filename);
    void moveRight();
    int getPosition() const;
    std::vector<int> getTape() const { return tape; }
  private:
    std::vector<int> tape;
    int position;
};

class InputTape : public Tape {
  public:
    InputTape(const std::string filename);
    int read() const;
  private:
    std::vector<int> tape;
    int position;
};

class OutputTape : public Tape {
  public:
    OutputTape();
    void write(const int data);
    std::vector<int> getOutput() const;
  private:
    std::vector<int> tape;
    int position;
};

#endif // TAPE_H