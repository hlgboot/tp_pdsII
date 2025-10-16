#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <string>
#include <vector>
#include "algorithms/Algoritmo.hpp" 
#include "core/ResultadoInstancia.hpp"

class MainController {
public:
    // Construtor recebe os 4 algoritmos como parâmetro e armazerna em _algoritmos
    MainController(const std::vector<Algoritmo*>& algoritmos);

    // Para cada instância a função chama a função lerInstancia passando o caminho da instância
    // Executa cada um dos 4 algoritmos passando os dados da instância
    // Cria um vetor ResultadoInstancia com os 4 ResultadosUnitarios e o numero da instância e armazena em _resultados_por_instancia
    void executar(const std::vector<std::string>& arquivos_instancias);

    // Percorre o vetor _resultados_por_instancia, processa os dados e cria um arquivo .csv (tabela)
    void gerarRelatorioCSV(const std::string& arquivo_saida) const;

private:
    std::vector<Algoritmo*> _algoritmos;

    std::vector<ResultadoInstancia> _resultados_por_instancia;

    std::pair<int, std::vector<Ativo>> lerInstancia(const std::string& caminho_arquivo);
};

#endif // MAINCONTROLLER_H