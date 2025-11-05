#include "algorithms/GulosoBeneficio.hpp"
#include "core/Ativo.hpp"           
#include "core/ResultadoUnitario.hpp" 

#include <vector>                                  
#include <iostream>                                
#include <algorithm> 

/**
 * Resolve o Problema da Mochila usando uma heurística gulosa
 * baseada no maior benefício (valor) individual.
 * Este algoritmo ordena os ativos pelo 'valor' (Benefício)
 * em ordem decrescente e, em seguida, preenche a mochila com os
 * melhores ativos (os de maior valor) que couberem, independente do custo.
 * Complexidade de Tempo: O(n log n), dominado pela etapa de ordenação.
 */
ResultadoUnitario GulosoBeneficio::resolver(int capacidade, const std::vector<Ativo>& ativos) {
    
    // 1. Inicializa o objeto de resultado
    ResultadoUnitario resultado;
    resultado.nome_algoritmo = "Guloso (Beneficio)"; // Define o nome para o CSV
    resultado.valor_total = 0;
    resultado.peso_total = 0;

    // 2. Trata casos de borda
    if (ativos.empty() || capacidade == 0) {
        return resultado;
    }

    // 3. Cria uma cópia local do vetor de ativos para poder ordená-lo
    std::vector<Ativo> copia_ativos = ativos;

    // 4. Ordena a cópia com base no MAIOR benefício (valor)
    std::sort(copia_ativos.begin(), copia_ativos.end(), [](const Ativo& a, const Ativo& b) {
        // Compara 'a.valor' com 'b.valor'
        // Queremos o maior valor primeiro (ordem decrescente)
        return a.valor > b.valor;
    });

    // 5. Itera sobre os ativos ordenados e preenche a mochila
    for (const Ativo& ativo : copia_ativos) {
        
        // Verifica se o ativo atual cabe na capacidade restante da mochila
        if (resultado.peso_total + ativo.peso <= capacidade) {
            
            // Adiciona o ativo à solução
            resultado.ativos_selecionados.push_back(ativo);
            resultado.valor_total += ativo.valor;
            resultado.peso_total += ativo.peso;
        }
    }

    // 6. Retorna a solução encontrada pela heurística
    return resultado;
}