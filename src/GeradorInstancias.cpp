#include "managers/GeradorInstancias.hpp"
#include "utils/Utils.hpp"
#include "core/Ativo.hpp"

#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <algorithm> // Para std::shuffle
#include <numeric>   // Para std::iota
#include <cmath>     // Para std::max
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

// Função Auxiliar para ler o arquivo ativos.csv
namespace {
    std::vector<std::string> lerNomesDeAtivos(const std::string& caminhoArquivo) {
        std::ifstream arquivo(caminhoArquivo);
        if (!arquivo.is_open()) {
            throw std::runtime_error("Erro Crítico: Não foi possível abrir o arquivo de nomes: " + caminhoArquivo);
        }
        std::vector<std::string> nomes;
        std::string linha;
        while (std::getline(arquivo, linha)) {
            if (!linha.empty()) {
                nomes.push_back(linha);
            }
        }
        arquivo.close();
        if (nomes.empty()) {
            throw std::runtime_error("Erro Crítico: Arquivo de nomes de ativos está vazio: " + caminhoArquivo);
        }
        return nomes;
    }
}

// Implementação da função gerarEsalvar
void GeradorInstancias::gerarEsalvar(
    int numeroDeInstancias,
    int itensPorInstancia,
    const std::string& arquivoNomes,
    const std::string& diretorioSaida
) {
    // 1. Checagens Iniciais
    if (numeroDeInstancias <= 0 || itensPorInstancia <= 0) {
        std::cerr << "Aviso: Número de instâncias e itens devem ser positivos. Geração pulada.\n";
        return;
    }
    if (diretorioSaida.empty() || arquivoNomes.empty()) {
        std::cerr << "Aviso: Diretório de saída ou arquivo de nomes não pode ser vazio. Geração pulada.\n";
        return;
    }

    // 2. Leitura dos Nomes Base
    std::vector<std::string> nomes_base = lerNomesDeAtivos(arquivoNomes);
    
    // 3. Preparação do Gerador Aleatório
    std::random_device rd;
    std::mt19937 gerador(rd());

    std::uniform_int_distribution<> dist_preco(50, 500);
    std::uniform_real_distribution<> dist_retorno(0.05, 0.30);
    std::uniform_real_distribution<> dist_volat(0.1, 1.0);

    const double TAXA_LIVRE_RISCO = 0.05; // 5%
    const double FATOR_CAPACIDADE = 0.5; // 50%

    std::cout << "Iniciando geração de " << numeroDeInstancias 
              << " instâncias com " << itensPorInstancia << " itens cada...\n";

    // 4. Preparação dos Índices para Nomes Únicos
    std::vector<int> indices(nomes_base.size());
    std::iota(indices.begin(), indices.end(), 0); // Preenche com 0, 1, 2...

    // 5. Loop Principal (Para cada instância) 
    for (int i = 0; i < numeroDeInstancias; ++i) {

        // Embaralha os índices para garantir uma seleção aleatória e única
        std::shuffle(indices.begin(), indices.end(), gerador);

        long long soma_precos_total = 0;
        std::vector<Ativo> ativos_da_instancia;
        ativos_da_instancia.reserve(itensPorInstancia);

        // 6. Loop Interno (Para cada ativo da instância)
        for (int j = 0; j < itensPorInstancia; ++j) {
            
            // Pega o índice embaralhado, garantindo que é único
            int indice_ativo_unico = indices[j]; 
            std::string nome_ativo = nomes_base[indice_ativo_unico]; 
            
            int preco = dist_preco(gerador);
            double retorno_esperado = dist_retorno(gerador);
            double volatilidade = dist_volat(gerador);

            double sharpe = Utils::calcularIndiceSharpe(retorno_esperado, volatilidade, TAXA_LIVRE_RISCO);
            int beneficio = std::max(1, static_cast<int>(sharpe * 1000.0));

            soma_precos_total += preco;
            ativos_da_instancia.push_back({nome_ativo, beneficio, preco});
        }

        // 7. Calcula a capacidade da mochila 
        int capacidade_mochila = static_cast<int>(soma_precos_total * FATOR_CAPACIDADE);

        // 8. Gera o Nome do arquivo usando o Contador Interno 
        int id_atual = _proximoId;
        _proximoId++;

        std::ostringstream oss;
        oss << diretorioSaida << "instancia_" 
            << std::setw(2) << std::setfill('0') << id_atual << ".txt";
        std::string nomeArquivoAtual = oss.str();
        
        // 9. Escreve no arquivo .txt
        std::ofstream arquivo_saida(nomeArquivoAtual);

        if (!arquivo_saida.is_open()) {
            std::cerr << "Erro: Não foi possível criar/abrir o arquivo '" << nomeArquivoAtual << "'. Pulando esta instância.\n";
            continue;
        }

        arquivo_saida << itensPorInstancia << " " << capacidade_mochila << "\n";
        for (const auto& ativo : ativos_da_instancia) {
            arquivo_saida << ativo.nome << " " << ativo.valor << " " << ativo.peso << "\n";
        }
        arquivo_saida.close();

        // Checagem de segurança pós-escrita
        if (arquivo_saida.fail()) {
            std::cerr << "Aviso: Erro ao finalizar escrita no arquivo '" << nomeArquivoAtual << "'.\n";
        } else {
            std::cout << " -> Instância '" << nomeArquivoAtual << "' gerada.\n";
        }
    }
}