/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionLoad.cc
 * @desc Implementación de la instrucción Load para memoria estática.
 *
 */

#include "../lib/InstructionLoad.h"
#include <iostream>

InstructionLoad::InstructionLoad(DataMemory* data_memory) : data_memory_(data_memory) {}

void InstructionLoad::execute(const InstructionContext& context) {
  if (context.op_type == 0) {
    data_memory_->write(0, context.pos);
    return;
  }

  if (context.op_type == 1) {
    int data = data_memory_->read(context.regist);
    data_memory_->write(0, data);
    return;
  }

  if (context.op_type == 2) {
    int regist = data_memory_->read(context.regist);
    if (regist == -1) {
      std::cerr << "Incorrect Register: R" << context.regist << " does not exist in memory" << '\n';
      return;
    }
    int data = data_memory_->read(regist);
    if (data == -1) {
      std::cerr << "Incorrect Register: R" << regist << " does not exist in memory" << '\n';
      return;
    }
    data_memory_->write(0, data);
  }
}
