/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionRead.cc
 * @desc Implementación de la instrucción Read para memoria estática.
 *
 */

#include "../lib/InstructionRead.h"

InstructionRead::InstructionRead(DataMemory* data_memory, InputTape* input_tape)
    : data_memory_(data_memory), input_tape_(input_tape) {}

void InstructionRead::execute(const InstructionContext& context) {
  int tape_head = input_tape_->read();
  data_memory_->write(context.regist, tape_head);
  input_tape_->moveRight();
}
