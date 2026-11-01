/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Complejidad Computacional
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    29/10/2026
*/

#include "../includes/funcionPrimitivaRecursiva.h"

uint32_t 
FuncionPrimitivaRecursiva::obtener_aridad() const {
	return aridad_;
}


uint64_t 
FuncionPrimitivaRecursiva::obtener_llamadas() {
	return contador_llamadas_;
}

void 
FuncionPrimitivaRecursiva::reiniciar_llamadas() {
	contador_llamadas_ = 0;
}

uint64_t 
FuncionPrimitivaRecursiva::evaluar(const std::vector<uint64_t>& argumentos) {
	if (argumentos.size() != aridad_) {
		throw std::invalid_argument("El número de argumentos no coincide con la aridad de la función.");
	}
	contador_llamadas_++;
	return ejecutar(argumentos);
}