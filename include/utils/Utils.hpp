/**
 * @file Utils.hpp
 * @brief Declaração de funções utilitárias globais para o projeto.
 */
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

/**
 * @namespace Utils
 * @brief Agrupa funções auxiliares, puras e sem estado.
 */
namespace Utils {

    /**
     * @brief Gera uma lista de nomes de arquivos de instância seguindo o padrão "diretorio/instancia_xx.txt".
     * @param numeroDeInstancias O número total de arquivos a serem listados.
     * @param diretorio O diretório onde os arquivos estão localizados (ex: "data/").
     * @return std::vector<std::string> Um vetor com os caminhos completos dos arquivos.
     */
    std::vector<std::string> gerarNomesArquivosInstancias(int numeroDeInstancias, const std::string& diretorio);

    /**
     * @brief Calcula o grau de proximidade de um valor em relação a um valor ótimo.
     * @param valor_obtido O valor da solução a ser comparada.
     * @param valor_otimo O valor da solução ótima (referência de 100%).
     * @return A proximidade em porcentagem (ex: 98.5). Retorna 0.0 se o valor ótimo for 0.
     */
    double calcularProximidade(int valor_obtido, int valor_otimo);

    /**
     * @brief Calcula o Índice de Sharpe para um ativo.
     * @param retorno_esperado A taxa de retorno esperada do ativo (ex: 0.15).
     * @param volatilidade O risco (desvio padrão) do ativo.
     * @param taxa_livre_risco A taxa de retorno de um investimento sem risco.
     * @return O Índice de Sharpe calculado. Retorna 0.0 se a volatilidade for zero.
     */
    double calcularIndiceSharpe(
        double retorno_esperado, 
        double volatilidade, 
        double taxa_livre_risco
    );

    /**
     * @brief Extrai o ID numérico de um nome de arquivo de instância.
     * @param nomeArquivo O caminho do arquivo (ex: "data/instancia_05.txt").
     * @return O ID numérico (ex: 5). Retorna -1 se não conseguir extrair.
     */
    int extrairIdDoNomeArquivo(const std::string& nomeArquivo);

} // namespace Utils

#endif // UTILS_H