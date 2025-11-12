/**
 * @file MainController.hpp
 * @brief Define a classe orquestradora principal da aplicação.
 */
#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <string>
#include <vector>
#include "algorithms/Algoritmo.hpp" 
#include "core/ResultadoInstancia.hpp"

/**
 * @class MainController
 * @brief Orquestra todo o fluxo de análise e geração de resultados.
 *
 * É responsável por ler as instâncias, chamar os algoritmos
 * (usando polimorfismo), medir o tempo e gerar o relatório CSV.
 */
class MainController {
public:
    /**
     * @brief Construtor do MainController.
     * @param algoritmos Um vetor de ponteiros para os 4 algoritmos.
     */
    MainController(const std::vector<Algoritmo*>& algoritmos);

    /**
     * @brief Executa a análise para uma lista de arquivos de instância.
     *
     * Itera por cada arquivo, lê seus dados, e executa os algoritmos passando os dados da instância.
     * Cria um vetor ResultadoInstancia com os 4 ResultadosUnitarios e o numero da instância e armazena em _resultados_por_instancia.
     * Contém a lógica para pular a Força Bruta em instâncias grandes.
     * @param arquivos_instancias Um vetor de strings com os caminhos para os arquivos .txt.
     */
    void executar(const std::vector<std::string>& arquivos_instancias);

    /**
     * @brief Gera o relatório CSV final com todos os resultados coletados.
     * 
     * Percorre o vetor _resultados_por_instancia, processa os dados e cria um arquivo .csv (tabela).
     * @param caminho_saida O caminho completo do arquivo .csv a ser criado (ex: "results/relatorio.csv").
     */
    void gerarRelatorioCSV(const std::string& arquivo_saida) const;

private:
    std::vector<Algoritmo*> _algoritmos;

    std::vector<ResultadoInstancia> _resultados_por_instancia;

    /**
     * @brief (Privado) Lê e processa (parse) um único arquivo de instância.
     * @param caminho_arquivo O caminho para o arquivo .txt.
     * @return Um std::pair contendo a capacidade da mochila e o vetor de ativos.
     * @throws std::runtime_error Se o arquivo não puder ser aberto ou estiver mal formatado.
     */
    std::pair<int, std::vector<Ativo>> lerInstancia(const std::string& caminho_arquivo);
};

#endif // MAINCONTROLLER_H