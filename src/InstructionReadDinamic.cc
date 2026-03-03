/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionReadDinamic.cc
 * @desc Implementación de la instrucción Read para memoria dinámica.
 *
 */

#include "../lib/InstructionReadDinamic.h"

InstructionReadDinamic::InstructionReadDinamic(DataMemoryDinamic* data_memory,
                                               InputTape* input_tape)
    : data_memory_(data_memory), input_tape_(input_tape) {}

void InstructionReadDinamic::execute(const InstructionContext& context) {
  int tape_head = input_tape_->read();

  if (context.op_type == 1) {
    data_memory_->write(context.regist, context.pos, tape_head);
  }

  if (context.op_type == 2) {
    int searched_regist = data_memory_->read(context.regist, context.pos);
    data_memory_->write(searched_regist, context.pos_ind, tape_head);
  }

  input_tape_->moveRight();
}
