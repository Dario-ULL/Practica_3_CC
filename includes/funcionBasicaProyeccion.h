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

class FuncionProyeccion : public FuncionPrimitivaRecursiva {
 private:
  uint32_t indice_seleccionado_; // Posición 1-indexada (i)
 public:
  FuncionProyeccion(uint32_t indice, uint32_t aridad_total)
                  : FuncionPrimitivaRecursiva(aridad_total), indice_seleccionado_(indice) {
    
    if (indice == 0 || indice > aridad_total) {
      throw std::invalid_argument("El índice de proyección debe estar entre 1 y la aridad total.");
    }
  }

  uint32_t obtener_indice() const {
    return indice_seleccionado_;
  }

 protected:
  uint64_t ejecutar(const std::vector<uint64_t>& argumentos) override {
    return argumentos[indice_seleccionado_ - 1];
  }
};