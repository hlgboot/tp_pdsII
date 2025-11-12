/**
 * @file GulosoBeneficio.hpp
 * @brief Define a classe do algoritmo Guloso por Benefício.
 */
#ifndef GULOSO_BENEFICIO_H
#define GULOSO_BENEFICIO_H

#include "Algoritmo.hpp"

/**
 * @class GulosoBeneficio
 * @brief Implementa a heurística Gulosa por Benefício (maior Sharpe).
 *
 * Esta estratégia seleciona primeiro os ativos com o maior benefício
 * (Índice de Sharpe) [cite_start]individual, sem considerar seu custo (preço)[cite: 104].
 * É rápido, mas pode não ser eficiente no uso do capital.
 */
class GulosoBeneficio : public Algoritmo {
public:
    /**
     * @brief Executa o algoritmo guloso por maior benefício.
     * @param capacidade A capacidade máxima da mochila (orçamento).
     * @param ativos Um vetor contendo todos os ativos disponíveis.
     * @return Um objeto ResultadoUnitario com a solução encontrada pela heurística.
     */
    ResultadoUnitario resolver(int capacidade, const std::vector<Ativo>& ativos) override;
};

#endif // GULOSO_BENEFICIO_H