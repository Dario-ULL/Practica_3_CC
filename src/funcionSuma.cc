/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Complejidad Computacional
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    29/10/2026
*/

#include "../includes/funcionSuma.h"

FuncionSuma::FuncionSuma() : FuncionPrimitivaRecursiva(2) {
	auto funcion_base = std::make_shared<FuncionProyeccion>(1, 1);
	auto sucesor = std::make_shared<FuncionSucesor>();
	auto proyeccion_z = std::make_shared<FuncionProyeccion>(3, 3);
	auto funcion_paso = std::make_shared<Composicion>(sucesor, std::vector<std::shared_ptr<FuncionPrimitivaRecursiva>>{ proyeccion_z });
	esquema_recursivo_ = std::make_shared<RecursionPrimitiva>(funcion_base, funcion_paso);
}

uint64_t 
FuncionSuma::ejecutar(const std::vector<uint64_t>& argumentos) {
	return esquema_recursivo_->evaluar(argumentos);
}