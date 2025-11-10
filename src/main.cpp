#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> // Para std::exception

#include "managers/MainController.hpp"
#include "managers/GeradorInstancias.hpp"
#include "utils/Utils.hpp"
#include "algorithms/ForcaBruta.hpp"
#include "algorithms/Aleatorio.hpp"
#include "algorithms/GulosoBeneficio.hpp"
#include "algorithms/GulosoRazao.hpp"

int main() {
    const int NUM_INSTANCIAS_PEQUENAS = 25;
    const int ITENS_POR_INSTANCIA_PEQUENA = 30; // Limite para rodar Força Bruta

    const int NUM_INSTANCIAS_GRANDES = 25;
    const int ITENS_POR_INSTANCIA_GRANDE = 100; // Teste de performance

    const int TOTAL_INSTANCIAS = NUM_INSTANCIAS_PEQUENAS + NUM_INSTANCIAS_GRANDES;

    const std::string DIR_DADOS = "data/";
    const std::string DIR_RESULTADOS = "results/";
    const std::string ARQUIVO_NOMES_BASE = "ativos.csv"; // Arquivo que o Gerador lê
    const std::string ARQUIVO_RELATORIO = "relatorio_final.csv";

    try {
        GeradorInstancias gerador;

        // Gera as 25 instâncias pequenas
        std::cout << "Gerando " << NUM_INSTANCIAS_PEQUENAS << " instancias pequenas..." << std::endl;
        gerador.gerarEsalvar(
            NUM_INSTANCIAS_PEQUENAS, 
            ITENS_POR_INSTANCIA_PEQUENA,
            DIR_DADOS + ARQUIVO_NOMES_BASE,
            DIR_DADOS
        );

        // Gera as 25 instâncias grandes
        std::cout << "Gerando " << NUM_INSTANCIAS_GRANDES << " instancias grandes..." << std::endl;
        gerador.gerarEsalvar(
            NUM_INSTANCIAS_GRANDES, 
            ITENS_POR_INSTANCIA_GRANDE,
            DIR_DADOS + ARQUIVO_NOMES_BASE,
            DIR_DADOS
        );
        std::cout << "Geracao de instancias concluida!" << std::endl;


        // Criação dos Algoritmos a serem usados
        ForcaBruta      fb;
        Aleatorio       al;
        GulosoBeneficio gb;
        GulosoRazao     gr;

        std::vector<Algoritmo*> algoritmos = {&fb, &al, &gb, &gr};

        // Criação do Controlador Principal 
        MainController controlador(algoritmos);

        // Geração da Lista de Arquivos 
        // Gera a lista completa: "instancia_01.txt" até "instancia_50.txt"
        std::vector<std::string> arquivos_para_processar = 
            Utils::gerarNomesArquivosInstancias(TOTAL_INSTANCIAS, DIR_DADOS);

        // Execução da Análise 
        std::cout << "\nIniciando analise de " << TOTAL_INSTANCIAS << " instancias..." << std::endl;
        controlador.executar(arquivos_para_processar);
        std::cout << "Analise concluida!" << std::endl;

        // Geração do Relatório Final
        const std::string caminho_saida_relatorio = DIR_RESULTADOS + ARQUIVO_RELATORIO;
        controlador.gerarRelatorioCSV(caminho_saida_relatorio);
        std::cout << "Relatorio salvo com sucesso em '" << caminho_saida_relatorio << "'!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "\nERRO FATAL: A execucao foi interrompida.\n";
        std::cerr << "Motivo: " << e.what() << std::endl;
        return 1; 
    }

    return 0; 
}