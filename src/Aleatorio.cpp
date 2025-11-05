#include "algorithms/Aleatorio.hpp"
#include "core/Ativo.hpp"
#include "core/ResultadoUnitario.hpp"

#include <vector>
#include <random>
#include <iostream>

/**
 * Resolve o Problema da Mochila usando um algoritmo ALEATÓRIO.
 * 
 * O algoritmo gera várias combinações aleatórias de ativos
 * (sem ultrapassar a capacidade) e guarda o melhor resultado encontrado.
 * 
 * Como o nome sugere, o processo é puramente aleatório — não há garantia
 * de encontrar a solução ótima, mas pode gerar boas soluções em pouco tempo.
 */
ResultadoUnitario Aleatorio::resolver(int capacidade, const std::vector<Ativo>& ativos) {

    // 1. Cria o objeto que guardará o melhor resultado encontrado
    ResultadoUnitario melhor_resultado;
    melhor_resultado.nome_algoritmo = "Aleatório";
    melhor_resultado.valor_total = 0;
    melhor_resultado.peso_total = 0;

    // 2. Cria o gerador de números aleatórios
    std::random_device rd;      // Usa o hardware para gerar uma semente aleatória
    std::mt19937 gerador(rd()); // Gerador Mersenne Twister
    std::uniform_int_distribution<> dist_binaria(0, 1); // Gera 0 ou 1 (50% de chance cada)

    // 3. Define quantas soluções aleatórias serão testadas
    const int NUM_ITERACOES = 10000; // Pode ajustar conforme desempenho desejado

    // 4. Loop principal — repete várias vezes para gerar diferentes mochilas aleatórias
    for (int i = 0; i < NUM_ITERACOES; ++i) {

        std::vector<Ativo> mochila_atual; // Guarda os ativos selecionados nesta iteração
        int peso_total = 0;               // Soma dos pesos
        int valor_total = 0;              // Soma dos valores

        // 5. Gera uma solução aleatória
        // Percorre todos os ativos e decide (aleatoriamente) se coloca ou não na mochila
        for (const auto& ativo : ativos) {

            // Se sair "1", tentamos adicionar o ativo
            if (dist_binaria(gerador)) {

                // Só adiciona se couber dentro da capacidade
                if (peso_total + ativo.peso <= capacidade) {
                    mochila_atual.push_back(ativo);
                    peso_total += ativo.peso;
                    valor_total += ativo.valor;
                }
            }
        }

        // 6. Verifica se a solução atual é melhor que a melhor encontrada até agora
        if (valor_total > melhor_resultado.valor_total) {
            melhor_resultado.valor_total = valor_total;
            melhor_resultado.peso_total = peso_total;
            melhor_resultado.ativos_selecionados = mochila_atual;
        }
    }

    // 7. Retorna o melhor resultado encontrado após todas as iterações
    return melhor_resultado;
}
