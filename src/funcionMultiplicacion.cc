/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Complejidad Computacional
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    29/10/2026
*/

#include "../includes/funcionMultiplicacion.h"

FuncionMultiplicacion::FuncionMultiplicacion() : FuncionPrimitivaRecursiva(2) {
  auto funcion_base = std::make_shared<FuncionCero>(1);
  auto suma = std::make_shared<FuncionSuma>();
  auto proyeccion_resultado_previo = std::make_shared<FuncionProyeccion>(3, 3); // z
  auto proyeccion_base_x = std::make_shared<FuncionProyeccion>(1, 3);           // x
  auto funcion_paso = std::make_shared<Composicion>(suma, std::vector<std::shared_ptr<FuncionPrimitivaRecursiva>>{ proyeccion_resultado_previo, proyeccion_base_x });
  esquema_recursivo_ = std::make_shared<RecursionPrimitiva>(funcion_base, funcion_paso);
}

uint64_t 
FuncionMultiplicacion::ejecutar(const std::vector<uint64_t>& argumentos) {
  return esquema_recursivo_->evaluar(argumentos);
}