/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionMult.cc
 * @desc Implementación de la instrucción Mult para memoria estática.
 *
 */

#include "../lib/InstructionMult.h"
#include <iostream>

InstructionMult::InstructionMult(DataMemory* data_memory) : data_memory_(data_memory) {}

void InstructionMult::execute(const InstructionContext& context) {
  if (context.op_type == 0) {
    int r_cero_data = data_memory_->read(0);
    int mult = r_cero_data * context.pos;
    data_memory_->write(0, mult);
    return;
  }

  if (context.op_type == 1) {
    int r_op_data = data_memory_->read(context.regist);
    int r_cero_data = data_memory_->read(0);
    int mult = r_cero_data * r_op_data;
    data_memory_->write(0, mult);
    return;
  }

  if (context.op_type == 2) {
    int r_op_regist = data_memory_->read(context.regist);
    if (r_op_regist > 20 || r_op_regist <= 0) {
      std::cerr << "Incorrect Register: R" << r_op_regist << " does not exist in memory" << '\n';
      return;
    }
    int r_regist_data = data_memory_->read(r_op_regist);
    int r_cero_data = data_memory_->read(0);
    int mult = r_cero_data * r_regist_data;
    data_memory_->write(0, mult);
  }
}
