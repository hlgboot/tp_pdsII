#include "algorithms/GulosoRazao.hpp"
#include "core/Ativo.hpp"           
#include "core/ResultadoUnitario.hpp" 

#include <vector>                                  
#include <iostream>

#include <algorithm>
#include <iostream>

/**
 * @brief Resolve o Problema da Mochila usando uma heurística gulosa
 * baseada na melhor razão valor/peso (custo-benefício).
 * * Este algoritmo ordena os ativos pela razão (Benefício / Preço)
 * em ordem decrescente e, em seguida, preenche a mochila com os
 * melhores ativos que couberem.
 * * Complexidade de Tempo: O(n log n), dominado pela etapa de ordenação.
 */
ResultadoUnitario GulosoRazao::resolver(int capacidade, const std::vector<Ativo>& ativos) {
    
    ResultadoUnitario resultado;
    resultado.nome_algoritmo = "Guloso (Razao)";
    resultado.valor_total = 0;
    resultado.peso_total = 0;

    if (ativos.empty() || capacidade == 0) {
        return resultado;
    }

    // Cópia do vetor de ativos para poder ordená-lo
    std::vector<Ativo> copia_ativos = ativos;

    std::sort(copia_ativos.begin(), copia_ativos.end(), [](const Ativo& a, const Ativo& b) {
        
        // Se ambos os ativos tem custo 0, prevalece o com maior valor
        if (a.peso == 0 && b.peso == 0) { return a.valor > b.valor; }

        // Se somente o ativo A tem custo 0, prevalece o A
        if (a.peso == 0) { return a.valor > 0; }

        // Se somente o ativo B tem custo 0, prevalece o B
        if (b.peso == 0) { return !(b.valor > 0); }

        double razao_a = static_cast<double>(a.valor) / a.peso;
        double razao_b = static_cast<double>(b.valor) / b.peso;

        return razao_a > razao_b;
    });

    for (const Ativo& ativo : copia_ativos) {
        
        // Se o resultado couber na mochila, partindo do melhor para o pior, ele é adicionado
        if (resultado.peso_total + ativo.peso <= capacidade) {

            resultado.ativos_selecionados.push_back(ativo);
            resultado.valor_total += ativo.valor;
            resultado.peso_total += ativo.peso;

        }
    }

    return resultado;
}