#ifndef ATIVO_H
#define ATIVO_H

#include <string>

struct Ativo {
    std::string nome;
    int valor; // Benefício (retorno esperado)
    int peso;  // Custo (preço do ativo)
};

#endif // ATIVO_H