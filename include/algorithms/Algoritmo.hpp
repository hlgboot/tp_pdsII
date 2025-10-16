#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <vector>
#include "core/Ativo.hpp"
#include "core/ResultadoUnitario.hpp"

class Algoritmo {
public:
    // Método virtual puro que define a interface para resolver o problema
    virtual ResultadoUnitario resolver(int capacidade, const std::vector<Ativo>& ativos) = 0;
    
    // Destrutor virtual é essencial para classes base com funções virtuais
    virtual ~Algoritmo() = default;
};

#endif // ALGORITMO_H