/**
 * @file ForcaBruta.hpp
 * @brief Define a classe do algoritmo de Força Bruta (solução ótima).
 */
#ifndef FORCA_BRUTA_H
#define FORCA_BRUTA_H

#include "Algoritmo.hpp"

/**
 * @class ForcaBruta
 * @brief Implementa a solução ótima (Exata) via Força Bruta.
 *
 * Encontra a solução perfeita testando todas as 2^n combinações possíveis
 * de ativos usando uma abordagem recursiva (backtracking).
 * É usado como 'baseline' para medir a qualidade das outras heurísticas.
 */
class ForcaBruta : public Algoritmo {
public:
    /**
     * @brief Executa o algoritmo de força bruta para encontrar a melhor combinação de ativos.
     * @param capacidade A capacidade máxima da mochila (orçamento).
     * @param ativos Um vetor contendo todos os ativos disponíveis.
     * @return Um objeto ResultadoUnitario com a solução ótima encontrada.
     */
    ResultadoUnitario resolver(int capacidade, const std::vector<Ativo>& ativos) override;
};

#endif // FORCA_BRUTA_H