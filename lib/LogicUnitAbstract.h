#ifndef LOGICUNITABSTRACT_H_
#define LOGICUNITABSTRACT_H_

#include <string>

struct InstructionContext {
    int op_type; // tipo del operador (constante, directo, indirecto)
    int op;  // Operador para memoria estática
    int regist; // Registro al que acceder en memoria dinamica
    int pos; // Posicion a la que acceder del registro anterior en memoria dinamica
    int pos_ind;  // Posicion a la que acceder en caso de que pos sea un registro en direccionamiento indirecto
    std::string label; // Etiqueta para los saltos
    int* program_counter; // Contador del programa
};

class LogicUnitAbstract {
  public:
    virtual void Load(const InstructionContext& context) = 0;
    virtual void Store(const InstructionContext& context) = 0;
    virtual void Add(const InstructionContext& context) = 0;
    virtual void Sub(const InstructionContext& context) = 0;
    virtual void Mult(const InstructionContext& context) = 0;
    virtual void Div(const InstructionContext& context) = 0;
    virtual void Read(const InstructionContext& context) = 0;
    virtual void Write(const InstructionContext& context) = 0;
    virtual void Jump(const InstructionContext& context) = 0;
    virtual void JumpZero(const InstructionContext& context) = 0;
    virtual void JumpGreaterThanZero(const InstructionContext& context) = 0;
};

#endif //LOGICUNITABSTRACT_H_
