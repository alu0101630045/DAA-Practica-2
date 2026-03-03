/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionStore.cc
 * @desc Implementación de la instrucción Store para memoria estática.
 *
 */

#include "../lib/InstructionStore.h"
#include <iostream>

InstructionStore::InstructionStore(DataMemory* data_memory) : data_memory_(data_memory) {}

void InstructionStore::execute(const InstructionContext& context) {
  if (context.op_type == 1) {
    int data = data_memory_->read(0);
    data_memory_->write(context.regist, data);
    return;
  }

  if (context.op_type == 2) {
    int regist = data_memory_->read(context.regist);
    if (regist > 20 || regist <= 0) {
      std::cerr << "Incorrect Register: R" << regist << " does not exist in memory" << '\n';
      return;
    }
    int data = data_memory_->read(0);
    data_memory_->write(regist, data);
  }
}
