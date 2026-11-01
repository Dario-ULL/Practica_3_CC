/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Complejidad Computacional
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    29/10/2026
*/

#pragma once

#include <vector>
#include <cstdint>
#include <stdexcept>

class FuncionPrimitivaRecursiva {
 protected:
  uint32_t aridad_;
  static inline uint64_t contador_llamadas_ = 0;
  virtual uint64_t ejecutar(const std::vector<uint64_t>& argumentos) = 0;
 public:
  explicit FuncionPrimitivaRecursiva(uint32_t aridad_inicial) : aridad_(aridad_inicial) {}
  virtual ~FuncionPrimitivaRecursiva() = default;

  uint32_t obtener_aridad() const;
  static uint64_t obtener_llamadas();
  static void reiniciar_llamadas();
  uint64_t evaluar(const std::vector<uint64_t>& argumentos);
};