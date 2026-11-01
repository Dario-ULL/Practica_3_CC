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

#include <vector>
#include <cstdint>
#include <stdexcept>

class FuncionCero : public FuncionPrimitivaRecursiva {
 public:
  explicit FuncionCero(uint32_t aridad_inicial = 1)
                      : FuncionPrimitivaRecursiva(aridad_inicial) {}

 protected:
  uint64_t ejecutar(const std::vector<uint64_t>&) override {
    return 0;
  }
};