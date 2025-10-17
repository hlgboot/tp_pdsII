#ifndef RESULTADO_UNITARIO_H
#define RESULTADO_UNITARIO_H

#include <string>
#include <vector>
#include "Ativo.hpp" // Depende de Ativo.h

struct ResultadoUnitario {
    std::string nome_algoritmo;
    int valor_total = 0;
    int peso_total = 0;
    double tempo_execucao_ms = 0.0;

    std::vector<Ativo> ativos_selecionados; 
};

#endif // RESULTADO_UNITARIO_H