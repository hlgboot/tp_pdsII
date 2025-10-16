#ifndef ALEATORIO_H
#define ALEATORIO_H

#include "Algoritmo.hpp"

class Aleatorio : public Algoritmo {
public:
    /**
     * @brief Executa o algoritmo aleatório.
     * @param capacidade A capacidade máxima da mochila (orçamento).
     * @param ativos Um vetor contendo todos os ativos disponíveis.
     * @return Um objeto ResultadoUnitario com uma solução aleatória.
     */
    ResultadoUnitario resolver(int capacidade, const std::vector<Ativo>& ativos) override;
};

#endif // ALEATORIO_H