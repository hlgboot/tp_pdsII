/**
 * @file GulosoRazao.hpp
 * @brief Define a classe do algoritmo Guloso por Razão (Custo-Benefício).
 */
#ifndef GULOSO_RAZAO_H
#define GULOSO_RAZAO_H

#include "Algoritmo.hpp"

/**
 * @class GulosoRazao
 * @brief Implementa a heurística Gulosa por Razão (Sharpe/Preço).
 *
 * Esta é uma estratégia avançada que seleciona primeiro os ativos com o
 * melhor "custo-benefício" (relação Benefício/Peso).
 * Otimiza o uso do capital, gerando soluções de alta qualidade.
 */
class GulosoRazao : public Algoritmo {
public:
    /**
     * @brief Executa o algoritmo guloso pela melhor razão benefício/custo.
     * @param capacidade A capacidade máxima da mochila (orçamento).
     * @param ativos Um vetor contendo todos os ativos disponíveis.
     * @return Um objeto ResultadoUnitario com a solução encontrada pela heurística.
     */
    ResultadoUnitario resolver(int capacidade, const std::vector<Ativo>& ativos) override;
};

#endif // GULOSO_RAZAO_H