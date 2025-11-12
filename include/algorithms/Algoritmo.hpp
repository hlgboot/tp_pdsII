/**
 * @file Algoritmo.hpp
 * @brief Define a interface (classe base abstrata) para todos os algoritmos.
 */
#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <vector>
#include "core/Ativo.hpp"
#include "core/ResultadoUnitario.hpp"

/**
 * @class Algoritmo
 * @brief Interface (classe base abstrata) para uma estratégia de solução.
 *
 * Define o contrato 'resolver()' que todas as implementações concretas
 * (ForcaBruta, Aleatorio, etc.) devem fornecer. Isso permite o uso
 * de polimorfismo pelo MainController.
 */
class Algoritmo {
public:
    /**
     * @brief Método virtual puro que executa a estratégia do algoritmo.
     * @param capacidade A capacidade máxima da mochila (orçamento).
     * @param ativos Um vetor constante com todos os ativos disponíveis.
     * @return Um objeto ResultadoUnitario contendo a solução encontrada.
     */
    virtual ResultadoUnitario resolver(int capacidade, const std::vector<Ativo>& ativos) = 0;
    
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Algoritmo() = default;
};

#endif // ALGORITMO_H