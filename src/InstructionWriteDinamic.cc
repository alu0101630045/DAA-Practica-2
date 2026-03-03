/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionWriteDinamic.cc
 * @desc Implementación de la instrucción Write para memoria dinámica.
 *
 */

#include "../lib/InstructionWriteDinamic.h"

InstructionWriteDinamic::InstructionWriteDinamic(DataMemoryDinamic* data_memory,
                                                 OutputTape* output_tape)
    : data_memory_(data_memory), output_tape_(output_tape) {}

void InstructionWriteDinamic::execute(const InstructionContext& context) {
  if (context.op_type == 0) {
    output_tape_->write(context.pos);
    output_tape_->moveRight();
    return;
  }

  if (context.op_type == 1) {
    int op_value = data_memory_->read(context.regist, context.pos);
    output_tape_->write(op_value);
    output_tape_->moveRight();
    return;
  }

  if (context.op_type == 2) {
    int searched_regist = data_memory_->read(context.regist, context.pos);
    int op_value = data_memory_->read(searched_regist, context.pos_ind);
    output_tape_->write(op_value);
    output_tape_->moveRight();
  }
}
