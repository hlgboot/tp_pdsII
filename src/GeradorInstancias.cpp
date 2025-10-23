// --- Includes Necessários ---
#include "../../include/app/GeradorInstancias.hpp" // Define a classe GeradorInstancias
#include "../../include/utils/Utils.hpp"          // Para calcular Sharpe e nomes de arquivo
#include "../../include/core/Ativo.hpp"           // Define a struct Ativo

#include <fstream>   // Para ler e escrever arquivos (ifstream, ofstream)
#include <vector>    // Para usar listas (vetores)
#include <string>    // Para usar texto (strings)
#include <random>    // Para gerar números aleatórios (melhor que rand())
#include <numeric>   // Para somar pesos (std::accumulate)
#include <cmath>     // Para std::max (pegar o maior valor)
#include <iostream>  // Para mostrar mensagens (cout) e erros (cerr)
#include <filesystem>// Para criar e verificar pastas/diretórios (precisa de C++17)

// --- Função Auxiliar ---
// Fica escondida aqui dentro, só esse arquivo .cpp consegue usar ela.
// Lê nomes de um arquivo, um por linha.
namespace { // (Namespace anônimo ainda é útil para esconder esta função)
    std::vector<std::string> lerNomesDeAtivos(const std::string& caminhoArquivo) {
        std::vector<std::string> nomes;
        std::ifstream arquivo(caminhoArquivo); // Tenta abrir o arquivo para leitura

        if (!arquivo.is_open()) {
            std::cerr << "Erro Crítico: Não foi possível abrir o arquivo de nomes: " << caminhoArquivo << std::endl;
            return nomes; // Retorna lista vazia para indicar erro
        }
        std::string linha;
        while (std::getline(arquivo, linha)) {
            if (!linha.empty()) {
                nomes.push_back(linha);
            }
        }
        arquivo.close();
        return nomes;
    }
} // Fim do namespace anônimo

// --- Implementação da Função Principal da Classe ---
void GeradorInstancias::gerarEsalvar(
    int numeroDeInstancias,
    int itensPorInstancia,
    const std::string& arquivoNomes, // Arquivo .txt com um nome de ativo por linha
    const std::string& diretorioSaida // Espera-se que seja "data" ou "data/"
) {
    // --- 1. Checagens Iniciais (Programação Defensiva) ---
    if (numeroDeInstancias <= 0 || itensPorInstancia <= 0) {
        std::cerr << "Erro: Número de instâncias e itens devem ser positivos.\n";
        return;
    }
    if (diretorioSaida.empty()) {
        std::cerr << "Erro: Diretório de saída não pode ser vazio.\n";
        return;
    }
     if (arquivoNomes.empty()) {
         std::cerr << "Erro: Nome do arquivo de nomes de ativos não pode ser vazio.\n";
        return;
    }

    // Lê a lista de nomes que será usada para os ativos
    std::vector<std::string> nomes_base = lerNomesDeAtivos(arquivoNomes);
    if (nomes_base.empty()) {
        std::cerr << "Erro: Falha ao ler nomes de ativos do arquivo. Abortando geração.\n";
        return;
    }

    // --- 3. Preparação do Gerador Aleatório ---
    std::random_device rd;
    std::mt19937 gerador(rd());

    // Intervalos para gerar valores aleatórios
    std::uniform_int_distribution<> dist_peso(10, 1000);
    std::uniform_real_distribution<> dist_retorno(0.01, 0.35);
    std::uniform_real_distribution<> dist_volatilidade(0.05, 0.6);
    std::uniform_int_distribution<> dist_nomes(0, nomes_base.size() - 1);

    const double TAXA_LIVRE_RISCO = 0.05; // 5%
    const double FATOR_CAPACIDADE = 0.5; // 50%

    // Pega a lista de nomes de arquivos formatados que vamos criar
    std::vector<std::string> nomesArquivosSaida = Utils::gerarNomesArquivosInstancias(numeroDeInstancias, diretorioSaida);

    std::cout << "Iniciando geração de " << numeroDeInstancias << " instâncias em '" << diretorioSaida << "'...\n";

    // --- 4. Loop Principal (Para cada instância) ---
    for (int i = 0; i < numeroDeInstancias; ++i) {

        long long soma_pesos_total = 0;
        std::vector<core::Ativo> ativos_da_instancia;
        ativos_da_instancia.reserve(itensPorInstancia);

        // --- 5. Loop Interno (Para cada ativo da instância) ---
        for (int j = 0; j < itensPorInstancia; ++j) {
            std::string nome_ativo = nomes_base[dist_nomes(gerador)];
            int peso = dist_peso(gerador);
            double retorno_esperado = dist_retorno(gerador);
            double volatilidade = dist_volatilidade(gerador);

            // Calcula o benefício (Sharpe)
            double sharpe = Utils::calcularIndiceSharpe(retorno_esperado, volatilidade, TAXA_LIVRE_RISCO);
            int beneficio = std::max(1, static_cast<int>(sharpe * 1000.0));

            soma_pesos_total += peso;
            // Adiciona o ativo na lista da instância
            ativos_da_instancia.push_back({nome_ativo, beneficio, peso});
        }

        // --- 6. Calcula a capacidade da mochila ---
        int capacidade_mochila = static_cast<int>(soma_pesos_total * FATOR_CAPACIDADE);

        // --- 7. Escreve no Arquivo .txt ---
        std::string nomeArquivoAtual = nomesArquivosSaida[i];
        std::ofstream arquivo_saida(nomeArquivoAtual);

        if (!arquivo_saida.is_open()) {
            std::cerr << "Erro: Não foi possível criar/abrir o arquivo '" << nomeArquivoAtual << "'. Pulando esta instância.\n";
            continue;
        }

        // Linha 1: Numero de Itens e Capacidade
        arquivo_saida << itensPorInstancia << " " << capacidade_mochila << "\n";

        // Linhas seguintes: Nome, Benefício e Peso de cada ativo
        for (const auto& ativo : ativos_da_instancia) {
             // Usa ativo.beneficio e ativo.peso
            arquivo_saida << ativo.nome << " " << ativo.beneficio << " " << ativo.peso << "\n";
        }

        arquivo_saida.close();

        if(arquivo_saida.fail()){
            std::cerr << "Aviso: Erro ao finalizar escrita no arquivo '" << nomeArquivoAtual << "'.\n";
        } else {
             std::cout << " -> Instância '" << nomeArquivoAtual << "' gerada.\n";
        }
    } // Fim do loop principal

    std::cout << "Geração de instâncias concluída.\n";
} // Fim da função gerarEsalvar

//