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
#include "funcionBasicaSucesor.h"
#include "funcionBasicaProyeccion.h"
#include "funcionBasicaZero.h"
#include "composicion.h"
#include "recursionPrimitiva.h"
#include "funcionSuma.h"
#include "funcionMultiplicacion.h"

#include <memory>
#include <vector>

class FuncionPotencia : public FuncionPrimitivaRecursiva {
 private:
  std::shared_ptr<RecursionPrimitiva> esquema_recursivo_;
 public:
  FuncionPotencia();
 protected:
  uint64_t ejecutar(const std::vector<uint64_t>& argumentos) override;
};