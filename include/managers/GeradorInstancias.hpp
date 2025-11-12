/**
 * @file GeradorInstancias.hpp
 * @brief Define a classe que gera os arquivos de instância de teste.
 */
#ifndef GERADOR_INSTANCIAS_H
#define GERADOR_INSTANCIAS_H

#include <string>
#include <vector>

/**
 * @class GeradorInstancias
 * @brief Responsável por criar os arquivos .txt de teste.
 *
 * Lê um arquivo base de nomes e gera dados aleatórios (preço, retorno,
 * volatilidade) para cada ativo, calculando seu benefício (Sharpe).
 * É uma classe 'stateful' que rastreia o ID da próxima instância a ser criada.
 */
class GeradorInstancias {
public:
    /**
     * @brief Gera e salva um lote de arquivos de instância.
     * @param numeroDeInstancias Quantidade de instâncias a serem geradas neste lote.
     * @param itensPorInstancia Quantidade de ativos em cada instância.
     * @param arquivoNomes O caminho para o arquivo .csv com os nomes dos ativos.
     * @param diretorioSaida A pasta onde os arquivos .txt serão salvos (ex: "data/").
     */
    void gerarEsalvar(
        int numeroDeInstancias, 
        int itensPorInstancia,
        const std::string& arquivoEntrada,
        const std::string& diretorioSaida
    );
private:
    /**
     * @brief Contador para rastrear o ID da próxima instância (ex: 1, 2, ... 50).
     */
    int _proximoId = 1;
};

#endif // GERADOR_INSTANCIAS_H