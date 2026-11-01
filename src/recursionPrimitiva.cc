/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Complejidad Computacional
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    29/10/2026
*/

#include "../includes/recursionPrimitiva.h"

RecursionPrimitiva::RecursionPrimitiva(std::shared_ptr<FuncionPrimitivaRecursiva> base, std::shared_ptr<FuncionPrimitivaRecursiva> paso)
                                      : FuncionPrimitivaRecursiva(base->obtener_aridad() + 1),
                                        funcion_base_(base),
                                        funcion_paso_(paso) {
  if (paso->obtener_aridad() != base->obtener_aridad() + 2) {
    throw std::invalid_argument("Aridades incompatibles para el esquema de recursión primitiva.");
  }
}

uint64_t 
RecursionPrimitiva::ejecutar(const std::vector<uint64_t>& argumentos) {
  uint64_t variable_recursiva = argumentos.back();
  std::vector<uint64_t> parametros_base(argumentos.begin(), argumentos.end() - 1);
  if (variable_recursiva == 0) {
    return funcion_base_->evaluar(parametros_base);
  }
  std::vector<uint64_t> argumentos_previos = argumentos;
  argumentos_previos.back() = variable_recursiva - 1;
  uint64_t resultado_anterior = this->evaluar(argumentos_previos);
  std::vector<uint64_t> argumentos_paso = parametros_base;
  argumentos_paso.push_back(variable_recursiva - 1);
  argumentos_paso.push_back(resultado_anterior);
  return funcion_paso_->evaluar(argumentos_paso);
}