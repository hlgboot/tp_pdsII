#ifndef GULOSO_BENEFICIO_H
#define GULOSO_BENEFICIO_H

#include "Algoritmo.hpp"

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