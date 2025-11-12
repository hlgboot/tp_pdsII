/**
 * @file ResultadoInstancia.hpp
 * @brief Define a estrutura que agrupa os resultados de uma instância.
 */
#ifndef RESULTADO_INSTANCIA_H
#define RESULTADO_INSTANCIA_H

#include <vector>
#include "ResultadoUnitario.hpp" // Depende de ResultadoUnitario.h

/**
 * @struct ResultadoInstancia
 * @brief Agrupa os resultados de todos os algoritmos para uma única instância.
 */
struct ResultadoInstancia {
    // Armazena o número da instância
    int id_instancia;

    // Vetor com o resultado de cada um dos 4 algoritmos para esta instância
    std::vector<ResultadoUnitario> resultados_dos_algoritmos;
};

#endif // RESULTADO_INSTANCIA_H