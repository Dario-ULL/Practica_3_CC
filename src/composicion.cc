/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Complejidad Computacional
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    29/10/2026
*/

#include "../includes/composicion.h"

Composicion::Composicion(std::shared_ptr<FuncionPrimitivaRecursiva> exterior,
            						 const std::vector<std::shared_ptr<FuncionPrimitivaRecursiva>>& interiores)
												: FuncionPrimitivaRecursiva(interiores.empty() ? 0 : interiores.front()->obtener_aridad()),
												funcion_exterior_(exterior),
												funciones_interiores_(interiores) {
	if (interiores.empty()) {
		throw std::invalid_argument("La lista de funciones interiores no puede estar vacía.");
	}
	if (funciones_interiores_.size() != funcion_exterior_->obtener_aridad()) {
		throw std::invalid_argument("El número de funciones interiores debe coincidir con la aridad de la función exterior.");
	}
	uint32_t aridad_comun = interiores.front()->obtener_aridad();
	for (const auto& funcion_interior : interiores) {
		if (funcion_interior->obtener_aridad() != aridad_comun) {
			throw std::invalid_argument("Todas las funciones interiores deben tener la misma aridad.");
		}
	}
}

uint64_t 
Composicion::ejecutar(const std::vector<uint64_t>& argumentos) {
	std::vector<uint64_t> resultados_intermedios;
	resultados_intermedios.reserve(funciones_interiores_.size());
	for (const auto& funcion_interior : funciones_interiores_) {
		uint64_t resultado = funcion_interior->evaluar(argumentos);
		resultados_intermedios.push_back(resultado);
	}
	return funcion_exterior_->evaluar(resultados_intermedios);
}
