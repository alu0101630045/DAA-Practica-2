/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de algoritmos
 *
 * @author Pablo García de los Reyes
 * @since Feb 24 2026
 * @file LogicUnitAbstract.h
 * @desc Interfaz abstracta para unidades lógicas.
 *
 */
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
    virtual ~LogicUnitAbstract() = default;

    /**
     * Ejecuta una instrucción dada por su opcode. La función implementa
     * el patrón estrategia delegando en la clase concreta correspondiente.
     * @param opcode nombre de la instrucción (por ejemplo "LOAD", "ADD")
     * @param context contexto con los operandos y el contador de programa
     */
    virtual void execute(const std::string& opcode,
                         const InstructionContext& context) = 0;
};

#endif //LOGICUNITABSTRACT_H_
