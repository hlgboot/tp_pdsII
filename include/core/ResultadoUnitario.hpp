/**
 * @file ResultadoUnitario.hpp
 * @brief Define a estrutura que armazena o resultado de um único algoritmo.
 */
#ifndef RESULTADO_UNITARIO_H
#define RESULTADO_UNITARIO_H

#include <string>
#include <vector>
#include "Ativo.hpp" // Depende de Ativo.h

/**
 * @struct ResultadoUnitario
 * @brief Armazena os dados da solução encontrada por um único algoritmo.
 */
struct ResultadoUnitario {
    std::string nome_algoritmo;
    int valor_total = 0;
    int peso_total = 0;
    double tempo_execucao_ms = 0.0;

    std::vector<Ativo> ativos_selecionados; 
};

#endif // RESULTADO_UNITARIO_H