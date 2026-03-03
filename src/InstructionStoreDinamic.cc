/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionStoreDinamic.cc
 * @desc Implementación de la instrucción Store para memoria dinámica.
 *
 */

#include "../lib/InstructionStoreDinamic.h"

InstructionStoreDinamic::InstructionStoreDinamic(DataMemoryDinamic* data_memory)
    : data_memory_(data_memory) {}

void InstructionStoreDinamic::execute(const InstructionContext& context) {
  if (context.op_type == 1) {
    int acc_data = data_memory_->read(0, 0);
    data_memory_->write(context.regist, context.pos, acc_data);
    return;
  }

  if (context.op_type == 2) {
    int acc_data = data_memory_->read(0, 0);
    int searched_regist = data_memory_->read(context.regist, context.pos);
    data_memory_->write(searched_regist, context.pos_ind, acc_data);
  }
}
