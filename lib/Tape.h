/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file Tape.h
 * @desc Declaración de clases para cintas de entrada y salida.
 *
 */
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