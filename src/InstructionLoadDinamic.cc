/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionLoadDinamic.cc
 * @desc Implementación de la instrucción Load para memoria dinámica.
 *
 */

#include "../lib/InstructionLoadDinamic.h"

InstructionLoadDinamic::InstructionLoadDinamic(DataMemoryDinamic* data_memory)
    : data_memory_(data_memory) {}

void InstructionLoadDinamic::execute(const InstructionContext& context) {
  if (context.op_type == 0) {
    data_memory_->write(0, 0, context.pos);
    return;
  }

  if (context.op_type == 1) {
    int data = data_memory_->read(context.regist, context.pos);
    data_memory_->write(0, 0, data);
    return;
  }

  if (context.op_type == 2) {
    int searched_regist = data_memory_->read(context.regist, context.pos);
    int data = data_memory_->read(searched_regist, context.pos_ind);
    data_memory_->write(0, 0, data);
  }
}
