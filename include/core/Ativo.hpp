/**
 * @file Ativo.hpp
 * @brief Define a estrutura de dados para um Ativo (item da mochila).
 */
#ifndef ATIVO_H
#define ATIVO_H

#include <string>

/**
 * @struct Ativo
 * @brief Armazena os dados de um único ativo de investimento (item).
 */
struct Ativo {
    std::string nome;
    int valor; // Benefício (retorno esperado)
    int peso;  // Custo (preço do ativo)
};

#endif // ATIVO_H