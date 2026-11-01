/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Complejidad Computacional
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    29/10/2026
 * @brief   El objetivo de la práctica consiste en implementar un programa que calcule la
            función potencia(x , y) como una función primitiva recursiva de números naturales.
*/

#include "includes/funcionPotencia.h"

#include <iostream>
#include <string>
#include <unistd.h>

void mostrar_ayuda(const char* nombre_programa) {
    std::cout << "Uso: " << nombre_programa << " -x <base> -y <exponente>\n";
    std::cout << "Opciones:\n";
    std::cout << "  -x <n>   Número natural base de la potencia.\n";
    std::cout << "  -y <n>   Número natural exponente de la potencia.\n";
    std::cout << "  -h       Muestra este mensaje de ayuda.\n";
}

int main(int argc, char* argv[]) {
  int opcion;
  bool base_proporcionada = false;
  bool exponente_proporcionado = false;
  uint64_t base = 0;
  uint64_t exponente = 0;
  while ((opcion = getopt(argc, argv, "x:y:h")) != -1) {
    switch (opcion) {
      case 'x':
        try {
          base = std::stoull(optarg);
          base_proporcionada = true;
        } catch (...) {
          std::cerr << "Error: La base (-x) debe ser un número natural válido.\n";
          return 1;
        }
        break;
      case 'y':
        try {
          exponente = std::stoull(optarg);
          exponente_proporcionado = true;
        } catch (...) {
          std::cerr << "Error: El exponente (-y) debe ser un número natural válido.\n";
          return 1;
        }
        break;
      case 'h':
        mostrar_ayuda(argv[0]);
        return 0;
      default:
        mostrar_ayuda(argv[0]);
        return 1;
    }
  }
  if (!base_proporcionada || !exponente_proporcionado) {
    std::cerr << "Error: Se requieren tanto la base (-x) como el exponente (-y).\n";
    mostrar_ayuda(argv[0]);
    return 1;
  }

  FuncionPrimitivaRecursiva::reiniciar_llamadas();
  FuncionPotencia funcion_potencia;
  try {
    uint64_t resultado = funcion_potencia.evaluar({base, exponente});
    uint64_t total_llamadas = FuncionPrimitivaRecursiva::obtener_llamadas();

    std::cout << "========================================\n";
    std::cout << "Operación: " << base << "^" << exponente << "\n";
    std::cout << "Resultado: " << resultado << "\n";
    std::cout << "Número de llamadas a funciones: " << total_llamadas << "\n";
    std::cout << "========================================\n";
  } catch (const std::exception& e) {
    std::cerr << "Error durante el cálculo: " << e.what() << "\n";
    return 2;
  }

  return 0;
}