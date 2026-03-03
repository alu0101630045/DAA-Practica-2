/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionMultDinamic.cc
 * @desc Implementación de la instrucción Mult para memoria dinámica.
 *
 */

#include "../lib/InstructionMultDinamic.h"

InstructionMultDinamic::InstructionMultDinamic(DataMemoryDinamic* data_memory)
    : data_memory_(data_memory) {}

void InstructionMultDinamic::execute(const InstructionContext& context) {
  if (context.op_type == 0) {
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc * context.pos);
    return;
  }

  if (context.op_type == 1) {
    int operand = data_memory_->read(context.regist, context.pos);
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc * operand);
    return;
  }

  if (context.op_type == 2) {
    int searched_regist = data_memory_->read(context.regist, context.pos);
    int operand = data_memory_->read(searched_regist, context.pos_ind);
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc * operand);
  }
}
