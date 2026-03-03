/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionDivDinamic.cc
 * @desc Implementación de la instrucción Div para memoria dinámica.
 *
 */

#include "../lib/InstructionDivDinamic.h"
#include <iostream>

InstructionDivDinamic::InstructionDivDinamic(DataMemoryDinamic* data_memory)
    : data_memory_(data_memory) {}

void InstructionDivDinamic::execute(const InstructionContext& context) {
  if (context.op_type == 0) {
    if (context.pos == 0) {
      std::cerr << "Division by 0 not allowed\n";
      return;
    }
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc / context.pos);
    return;
  }

  if (context.op_type == 1) {
    int operand = data_memory_->read(context.regist, context.pos);
    if (operand == 0) {
      std::cerr << "Division by 0 not allowed\n";
      return;
    }
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc / operand);
    return;
  }

  if (context.op_type == 2) {
    int searched_regist = data_memory_->read(context.regist, context.pos);
    int operand = data_memory_->read(searched_regist, context.pos_ind);
    if (operand == 0) {
      std::cerr << "Division by 0 not allowed\n";
      return;
    }
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc / operand);
  }
}
