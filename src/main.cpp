#include <iostream>
#include <vector>

// Import dos managers
#include "managers/MainController.hpp"
#include "managers/GeradorInstancias.hpp"

// Import das utils
#include "utils/Utils.hpp"

// Import dos algoritmos
#include "algorithms/ForcaBruta.hpp"
#include "algorithms/Aleatorio.hpp"
#include "algorithms/GulosoBeneficio.hpp"
#include "algorithms/GulosoRazao.hpp"

int main() {
    const int NUM_INSTANCIAS = 50;
    const std::string DIR_INSTANCIAS = "data/";

    // 1. Gerar os arquivos de instância (se necessário)
    GeradorInstancias gerador;
    gerador.gerarEsalvar(NUM_INSTANCIAS, 10, "data/ativos.csv", DIR_INSTANCIAS);
    std::cout << "Instâncias geradas com sucesso!" << std::endl;

    // 2. Criar os algoritmos
    ForcaBruta          fb;
    Aleatorio           al;
    GulosoBeneficio     gb;
    GulosoRazao         gr;

    std::vector<Algoritmo*> algoritmos = {&fb, &al, &gb, &gr};

    // 3. Criar o controlador principal
    MainController controlador(algoritmos);

    // 4. Gerar a lista de arquivos a serem processados
    std::vector<std::string> arquivos = Utils::gerarNomesArquivosInstancias(NUM_INSTANCIAS, DIR_INSTANCIAS);

    // 5. Executar a análise
    controlador.executar(arquivos);
    std::cout << "Análise concluída!" << std::endl;

    // 6. Gerar o relatório final
    controlador.gerarRelatorioCSV("results/relatorio.csv");
    std::cout << "Relatório salvo em results/relatorio.csv" << std::endl;

    return 0;
}