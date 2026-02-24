/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file LogicUnitDinamic.cc
 * @desc Implementación de la unidad lógica para memoria dinámica.
 *
 */
#include "../lib/LogicUnitDinamic.h"


void LogicUnitDinamic::Load(const InstructionContext& context) {
  if (context.op_type == 0) {
    data_memory_->write(0, 0, context.pos);
  }

  if (context.op_type == 1) {
    int data = data_memory_->read(context.regist, context.pos);
    data_memory_->write(0, 0, data);
  }

  if (context.op_type == 2) {
    int searched_regist = data_memory_->read(context.regist, context.pos);
    int data = data_memory_->read(searched_regist, context.pos_ind);
    data_memory_->write(0, 0, data);
  }
}

void LogicUnitDinamic::Store(const InstructionContext& context) {
  if (context.op_type == 1) {
    int acc_data = data_memory_->read(0, 0);
    data_memory_->write(context.regist, context.pos, acc_data);
  }

  if (context.op_type == 2) {
    int acc_data = data_memory_->read(0, 0);
    int searched_regist = data_memory_->read(context.regist, context.pos);
    data_memory_->write(searched_regist, context.pos_ind, acc_data);
  }
}

void LogicUnitDinamic::Add(const InstructionContext& context) {
  if (context.op_type == 0) {
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc + context.pos);
  }

  if (context.op_type == 1) {
    int operand = data_memory_->read(context.regist, context.pos);
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc + operand);
  }

  if (context.op_type == 2) {
    int searched_regist = data_memory_->read(context.regist, context.pos);
    int operand = data_memory_->read(searched_regist, context.pos_ind);
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc + operand);
  }
}

void LogicUnitDinamic::Sub(const InstructionContext& context) {
  if (context.op_type == 0) {
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc - context.pos);
  }

  if (context.op_type == 1) {
    int operand = data_memory_->read(context.regist, context.pos);
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc - operand);
  }

  if (context.op_type == 2) {
    int searched_regist = data_memory_->read(context.regist, context.pos);
    int operand = data_memory_->read(searched_regist, context.pos_ind);
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc - operand);
  }
}

void LogicUnitDinamic::Mult(const InstructionContext& context) {
  if (context.op_type == 0) {
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc * context.pos);
  }

  if (context.op_type == 1) {
    int operand = data_memory_->read(context.regist, context.pos);
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc * operand);
  }

  if (context.op_type == 2) {
    int searched_regist = data_memory_->read(context.regist, context.pos);
    int operand = data_memory_->read(searched_regist, context.pos_ind);
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc * operand);
  }
}

void LogicUnitDinamic::Div(const InstructionContext& context) {
  if (context.op_type == 0) {
    if (context.pos == 0) {
      std::cerr << "Division by 0 not allowed\n";
      return;
    }
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc / context.pos);
  }

  if (context.op_type == 1) {
    int operand = data_memory_->read(context.regist, context.pos);
    if (operand == 0) {
      std::cerr << "Division by 0 not allowed\n";
      return;
    }
    int acc = data_memory_->read(0, 0);
    data_memory_->write(0, 0, acc / operand);
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

void LogicUnitDinamic::Read(const InstructionContext& context) {
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

void LogicUnitDinamic::Write(const InstructionContext& context) {
  if (context.op_type == 0) {
    output_tape_->write(context.pos);
    output_tape_->moveRight();
  }
  
  if (context.op_type == 1) {
    int op_value = data_memory_->read(context.regist, context.pos);
    output_tape_->write(op_value);
    output_tape_->moveRight();
  }

  if (context.op_type == 2) {
    int searched_regist = data_memory_->read(context.regist, context.pos);
    int op_value = data_memory_->read(searched_regist, context.pos_ind);
    output_tape_->write(op_value);
    output_tape_->moveRight();
  }
}

void LogicUnitDinamic::Jump(const InstructionContext& context) {
  int jump_address = program_memory_->getLabels()[context.label];
  *(context.program_counter) = jump_address - 1;
}

void LogicUnitDinamic::JumpZero(const InstructionContext& context) {
  if (data_memory_->read(0, 0) == 0) {
    int jump_address = program_memory_->getLabels()[context.label];
    *(context.program_counter) = jump_address - 1;
  }
}

void LogicUnitDinamic::JumpGreaterThanZero(const InstructionContext& context) {
  if (data_memory_->read(0, 0) > 0) {
    int jump_address = program_memory_->getLabels()[context.label];
    *(context.program_counter) = jump_address - 1;
  }
}