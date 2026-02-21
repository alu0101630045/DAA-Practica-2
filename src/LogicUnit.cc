#include "../lib/LogicUnit.h"

void LogicUnit::Load(const int op_type, const int op) {
  // CONSTANT (Op =i)
  if (op_type == 0) {
    data_memory_->write(0, op);
  }

  // Register (Op i)
  if (op_type == 1) {
    int data = data_memory_->read(op);
    if (data == -1) {
      std::cerr<<"Incorrect Register: R" << op << " does not exist in memory"<<'\n';
      return;
    }
    data_memory_->write(0, data);
  }

  // Indirect (Op *i)
  if (op_type == 2) {
    int regist = data_memory_->read(op);
    if (regist == -1) {
      std::cerr<<"Incorrect Register: R" << op << " does not exist in memory"<<'\n';
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

void LogicUnit::Store(const int op_type, const int op) {
  if (op_type == 1) {
    int data = data_memory_->read(0);
    data_memory_->write(op, data);
  }

  if (op_type == 2) {
    int regist = data_memory_->read(0);
    if (regist > 20 || regist <= 0) {
      std::cerr<<"Incorrect Register: R" << regist << " does not exist in memory"<<'\n';
      return;
    }
    int data = data_memory_->read(0);
    data_memory_->write(regist, data);
  }
}

void LogicUnit::Add(const int op_type, const int op) {
  if (op_type == 0) {
    int r_cero_data = data_memory_->read(0);
    int sum = r_cero_data + op;
    data_memory_->write(0, sum);
  }

  if (op_type == 1) {
    int r_op_data = data_memory_->read(op);
    int r_cero_data = data_memory_->read(0);
    int sum = r_cero_data + r_op_data;
    data_memory_->write(0, sum);
  }

  if (op_type == 2) {
    int r_op_regist = data_memory_->read(op);
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

void LogicUnit::Sub(const int op_type, const int op) {
  if (op_type == 0) {
    int r_cero_data = data_memory_->read(0);
    int sub = r_cero_data - op;
    data_memory_->write(0, sub);
  }

  if (op_type == 1) {
    int r_op_data = data_memory_->read(op);
    int r_cero_data = data_memory_->read(0);
    int sub = r_cero_data - r_op_data;
    data_memory_->write(0, sub);
  }

  if (op_type == 2) {
    int r_op_regist = data_memory_->read(op);
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

void LogicUnit::Mult(const int op_type, const int op) {
  if (op_type == 0) {
    int r_cero_data = data_memory_->read(0);
    int mult = r_cero_data * op;
    data_memory_->write(0, mult);
  }

  if (op_type == 1) {
    int r_op_data = data_memory_->read(op);
    int r_cero_data = data_memory_->read(0);
    int mult = r_cero_data * r_op_data;
    data_memory_->write(0, mult);
  }

  if (op_type == 2) {
    int r_op_regist = data_memory_->read(op);
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

void LogicUnit::Div(const int op_type, const int op) {
  if (op_type == 0) {
    int r_cero_data = data_memory_->read(0);
    if (op == 0) {
      std::cerr << "Division by 0 not allowed"<<'\n';
      return;
    }
    int div = r_cero_data / op;
    data_memory_->write(0, div);
  }

  if (op_type == 1) {
    int r_op_data = data_memory_->read(op);
    int r_cero_data = data_memory_->read(0);
    if (r_op_data == 0) {
      std::cerr << "Division by 0 not allowed"<<'\n';
      return;
    }
    int div = r_cero_data / r_op_data;
    data_memory_->write(0, div);
  }

  if (op_type == 2) {
    int r_op_regist = data_memory_->read(op);
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

void LogicUnit::Read(const int op) {
  int tape_head = input_tape_->read();
  data_memory_->write(op, tape_head);
}

void LogicUnit::Write(const int op) {
  int op_value = data_memory_->read(op);
  output_tape_->write(op_value);
}

void LogicUnit::Jump(const std::string label, int& program_counter) {
  int jump_address = program_memory_->getLabels()[label];
  program_counter = jump_address;
}

void LogicUnit::JumpZero(const std::string label, int& program_counter) {
  if (data_memory_->read(0) == 0) {
    int jump_address = program_memory_->getLabels()[label];
    program_counter = jump_address;
  }
}

void LogicUnit::JumpGreaterThanZero(const std::string label, int& program_counter) {
  if (data_memory_->read(0) > 0) {
    int jump_address = program_memory_->getLabels()[label];
    program_counter = jump_address;
  }
}