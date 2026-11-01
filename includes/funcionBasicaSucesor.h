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

class FuncionSucesor : public FuncionPrimitivaRecursiva {
 public:
  FuncionSucesor() : FuncionPrimitivaRecursiva(1) {}

 protected:
  uint64_t ejecutar(const std::vector<uint64_t>& argumentos) override {
    return argumentos[0] + 1;
  }
};