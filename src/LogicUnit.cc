/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file LogicUnit.cc
 * @desc Implementación de la unidad lógica para memoria estática.
 *
 */
#include "../lib/LogicUnit.h"

void LogicUnit::Load(const InstructionContext& context) {
  // CONSTANT (Op =i)
  if (context.op_type == 0) {
    data_memory_->write(0, context.pos);
  }

  // Register (Op i)
  if (context.op_type == 1) {
    int data = data_memory_->read(context.regist);
    data_memory_->write(0, data);
  }

  // Indirect (Op *i)
  if (context.op_type == 2) {
    int regist = data_memory_->read(context.regist);
    if (regist == -1) {
      std::cerr<<"Incorrect Register: R" << context.regist << " does not exist in memory"<<'\n';
      return;
    }
    int data = data_memory_->read(regist);
    if (data == -1) {
      std::cerr<<"Incorrect Register: R" << regist << " does not exist in memory"<<'\n';
      return;
    }
    data_memory_->write(0, data);
  }
}

void LogicUnit::Store(const InstructionContext& context) {
  if (context.op_type == 1) {
    int data = data_memory_->read(0);
    data_memory_->write(context.regist, data);
  }

  if (context.op_type == 2) {
    int regist = data_memory_->read(context.regist);
    if (regist > 20 || regist <= 0) {
      std::cerr<<"Incorrect Register: R" << regist << " does not exist in memory"<<'\n';
      return;
    }
    int data = data_memory_->read(0);
    data_memory_->write(regist, data);
  }
}

void LogicUnit::Add(const InstructionContext& context) {
  if (context.op_type == 0) {
    int r_cero_data = data_memory_->read(0);
    int sum = r_cero_data + context.pos;
    data_memory_->write(0, sum);
  }

  if (context.op_type == 1) {
    int r_op_data = data_memory_->read(context.regist);
    int r_cero_data = data_memory_->read(0);
    int sum = r_cero_data + r_op_data;
    data_memory_->write(0, sum);
  }

  if (context.op_type == 2) {
    int r_op_regist = data_memory_->read(context.regist);
    if (r_op_regist > 20 || r_op_regist <= 0) {
      std::cerr<<"Incorrect Register: R" << r_op_regist << " does not exist in memory"<<'\n';
      return;
    }
    int r_regist_data = data_memory_->read(r_op_regist);
    int r_cero_data = data_memory_->read(0);
    int sum = r_cero_data + r_regist_data;
    data_memory_->write(0, sum);
  }
}

void LogicUnit::Sub(const InstructionContext& context) {
  if (context.op_type == 0) {
    int r_cero_data = data_memory_->read(0);
    int sub = r_cero_data - context.pos;
    data_memory_->write(0, sub);
  }

  if (context.op_type == 1) {
    int r_op_data = data_memory_->read(context.regist);
    int r_cero_data = data_memory_->read(0);
    int sub = r_cero_data - r_op_data;
    data_memory_->write(0, sub);
  }

  if (context.op_type == 2) {
    int r_op_regist = data_memory_->read(context.regist);
    if (r_op_regist > 20 || r_op_regist <= 0) {
      std::cerr<<"Incorrect Register: R" << r_op_regist << " does not exist in memory"<<'\n';
      return;
    }
    int r_regist_data = data_memory_->read(r_op_regist);
    int r_cero_data = data_memory_->read(0);
    int sub = r_cero_data - r_regist_data;
    data_memory_->write(0, sub);
  }
}

void LogicUnit::Mult(const InstructionContext& context) {
  if (context.op_type == 0) {
    int r_cero_data = data_memory_->read(0);
    int mult = r_cero_data * context.pos;
    data_memory_->write(0, mult);
  }

  if (context.op_type == 1) {
    int r_op_data = data_memory_->read(context.regist);
    int r_cero_data = data_memory_->read(0);
    int mult = r_cero_data * r_op_data;
    data_memory_->write(0, mult);
  }

  if (context.op_type == 2) {
    int r_op_regist = data_memory_->read(context.regist);
    if (r_op_regist > 20 || r_op_regist <= 0) {
      std::cerr<<"Incorrect Register: R" << r_op_regist << " does not exist in memory"<<'\n';
      return;
    }
    int r_regist_data = data_memory_->read(r_op_regist);
    int r_cero_data = data_memory_->read(0);
    int mult = r_cero_data * r_regist_data;
    data_memory_->write(0, mult);
  }
}

void LogicUnit::Div(const InstructionContext& context) {
  if (context.op_type == 0) {
    int r_cero_data = data_memory_->read(0);
    if (context.pos == 0) {
      std::cerr << "Division by 0 not allowed"<<'\n';
      return;
    }
    int div = r_cero_data / context.pos;
    data_memory_->write(0, div);
  }

  if (context.op_type == 1) {
    int r_op_data = data_memory_->read(context.regist);
    int r_cero_data = data_memory_->read(0);
    if (r_op_data == 0) {
      std::cerr << "Division by 0 not allowed"<<'\n';
      return;
    }
    int div = r_cero_data / r_op_data;
    data_memory_->write(0, div);
  }

  if (context.op_type == 2) {
    int r_op_regist = data_memory_->read(context.regist);
    if (r_op_regist > 20 || r_op_regist <= 0) {
      std::cerr<<"Incorrect Register: R" << r_op_regist << " does not exist in memory"<<'\n';
      return;
    }
    int r_regist_data = data_memory_->read(r_op_regist);
    int r_cero_data = data_memory_->read(0);
    if (r_regist_data == 0) {
      std::cerr << "Division by 0 not allowed"<<'\n';
      return;
    }
    int div = r_cero_data / r_regist_data;
    data_memory_->write(0, div);
  }
}

void LogicUnit::Read(const InstructionContext& context) {
  int tape_head = input_tape_->read();
  data_memory_->write(context.regist, tape_head);
  input_tape_->moveRight();
}

void LogicUnit::Write(const InstructionContext& context) {
  if (context.op_type == 0) {
    output_tape_->write(context.pos);
    output_tape_->moveRight();
  }
  
  if (context.op_type == 1) {
    int op_value = data_memory_->read(context.regist);
    output_tape_->write(op_value);
    output_tape_->moveRight();
  }

  if (context.op_type == 2) {
    int regist = data_memory_->read(context.regist);
    if (regist > 20 || regist <= 0) {
      std::cerr<<"Incorrect Register: R" << regist << " does not exist in memory"<<'\n';
      return;
    }
    int op_value = data_memory_->read(regist);
    output_tape_->write(op_value);
    output_tape_->moveRight();
  }
}

void LogicUnit::Jump(const InstructionContext& context) {
  int jump_address = program_memory_->getLabels()[context.label];
  *(context.program_counter) = jump_address - 1;
}

void LogicUnit::JumpZero(const InstructionContext& context) {
  if (data_memory_->read(0) == 0) {
    int jump_address = program_memory_->getLabels()[context.label];
    *(context.program_counter) = jump_address - 1;
  }
}

void LogicUnit::JumpGreaterThanZero(const InstructionContext& context) {
  if (data_memory_->read(0) > 0) {
    int jump_address = program_memory_->getLabels()[context.label];
    *(context.program_counter) = jump_address - 1;
  }
}