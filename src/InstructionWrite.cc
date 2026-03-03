/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file InstructionWrite.cc
 * @desc Implementación de la instrucción Write para memoria estática.
 *
 */

#include "../lib/InstructionWrite.h"

InstructionWrite::InstructionWrite(DataMemory* data_memory, OutputTape* output_tape)
    : data_memory_(data_memory), output_tape_(output_tape) {}

void InstructionWrite::execute(const InstructionContext& context) {
  if (context.op_type == 0) {
    output_tape_->write(context.pos);
    output_tape_->moveRight();
    return;
  }

  if (context.op_type == 1) {
    int op_value = data_memory_->read(context.regist);
    output_tape_->write(op_value);
    output_tape_->moveRight();
    return;
  }

  if (context.op_type == 2) {
    int regist = data_memory_->read(context.regist);
    if (regist > 20 || regist <= 0) {
      std::cerr << "Incorrect Register: R" << regist << " does not exist in memory" << '\n';
      return;
    }
    int op_value = data_memory_->read(regist);
    output_tape_->write(op_value);
    output_tape_->moveRight();
  }
}
