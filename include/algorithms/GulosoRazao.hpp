#ifndef GULOSO_RAZAO_H
#define GULOSO_RAZAO_H

#include "Algoritmo.hpp"

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