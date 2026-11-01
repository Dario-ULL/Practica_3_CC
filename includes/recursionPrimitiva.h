/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Complejidad Computacional
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    29/10/2026
*/

#pragma once

#include "funcionPrimitivaRecursiva.h"

#include <memory>
#include <vector>

class RecursionPrimitiva : public FuncionPrimitivaRecursiva {
 private:
  std::shared_ptr<FuncionPrimitivaRecursiva> funcion_base_; // g(x)
  std::shared_ptr<FuncionPrimitivaRecursiva> funcion_paso_; // h(x, y, resultado_previo)
 public:
  RecursionPrimitiva(std::shared_ptr<FuncionPrimitivaRecursiva> base, std::shared_ptr<FuncionPrimitivaRecursiva> paso);
 protected:
  uint64_t ejecutar(const std::vector<uint64_t>& argumentos) override;
};