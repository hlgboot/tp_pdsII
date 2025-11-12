/**
 * @file Aleatorio.hpp
 * @brief Define a classe do algoritmo Aleatório (Monte Carlo).
 */
#ifndef ALEATORIO_H
#define ALEATORIO_H

#include "Algoritmo.hpp"

/**
 * @class Aleatorio
 * @brief Implementa a heurística Aleatória (Monte Carlo).
 *
 * Gera N (ex: 10.000) soluções aleatórias e retorna a melhor encontrada.
 */
class Aleatorio : public Algoritmo {
public:

    /**
     * @brief Executa a simulação de Monte Carlo.
     * @param capacidade A capacidade máxima da mochila.
     * @param ativos O vetor de ativos disponíveis.
     * @return O melhor ResultadoUnitario encontrado após N iterações.
     */
    ResultadoUnitario resolver(int capacidade, const std::vector<Ativo>& ativos) override;
};

#endif // ALEATORIO_H