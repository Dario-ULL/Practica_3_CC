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
#include <stdexcept>

class Composicion : public FuncionPrimitivaRecursiva {
private:
  std::shared_ptr<FuncionPrimitivaRecursiva> funcion_exterior_; // g(y1, ..., ym)
  std::vector<std::shared_ptr<FuncionPrimitivaRecursiva>> funciones_interiores_; // {h1, ..., hm}
public:
  Composicion(std::shared_ptr<FuncionPrimitivaRecursiva> exterior,
              const std::vector<std::shared_ptr<FuncionPrimitivaRecursiva>>& interiores);
protected:
  uint64_t ejecutar(const std::vector<uint64_t>& argumentos) override;
};