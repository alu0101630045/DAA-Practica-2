#include "../lib/functions.h"

void MostrarMenu(std::string& ram_filename, int& mode) {
  std::cout << "\n========================================" << std::endl;
  std::cout << "        SIMULADOR MÁQUINA RAM           " << std::endl;
  std::cout << "========================================\n" << std::endl;

  std::string filename;
  std::cout << "Ingrese el nombre del programa RAM\n";
  std::cout << "Por ejemplo: insertion_sort.ram): ";
  std::cin >> filename;
  ram_filename = "programs/" + filename;

  std::cout << "\nSeleccione el modo de ejecución:\n";
  std::cout << "    1. Dinámico\n";
  std::cout << "    2. Estático\n";
  std::cout << "    Opción (1 o 2): ";
  std::cin >> mode;

  // Validación básica
  while (mode != 1 && mode != 2) {
    std::cout << "    [!] Opción inválida. Ingrese 1 o 2: ";
    std::cin >> mode;
  }
}