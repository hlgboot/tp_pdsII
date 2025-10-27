#include "managers/MainController.hpp" 
#include "utils/Utils.hpp"
#include "algorithms/ForcaBruta.hpp" // Necessário para o dynamic_cast
#include "core/Ativo.hpp"

#include <fstream>   // Para ler arquivos (ifstream)
#include <sstream>   // Para ler linhas de arquivos (istringstream)
#include <iostream>  // Para saída de erro (std::cerr)
#include <stdexcept> // Para std::runtime_error (exceções)
#include <chrono>    // Para medir o tempo (high_resolution_clock)
#include <iomanip>   // Para formatar o CSV (setprecision)
#include <typeinfo>  // Para dynamic_cast (identificar a Força Bruta)

// Define o número máximo de itens para o qual a Força Bruta será executada.
// 20-22 é um limite seguro. Acima de 25 vai levar muito tempo.
const int LIMITE_ITENS_FORCA_BRUTA = 20;

/**
 * @brief Construtor: Apenas armazena a lista de algoritmos.
 */
MainController::MainController(const std::vector<Algoritmo*>& algoritmos)
    : _algoritmos(algoritmos) {
    // O construtor inicializa a lista de membros.
}

/**
 * @brief (Privado) Lê e processa um único arquivo de instância.
 */
std::pair<int, std::vector<Ativo>> MainController::lerInstancia(const std::string& caminho_arquivo) {
    std::ifstream arquivo(caminho_arquivo);

    // Checagem se o arquivo de instância existe.
    if (!arquivo.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir o arquivo de instancia: " + caminho_arquivo);
    }

    int numero_de_ativos;
    int capacidade_mochila;

    // Lê a Linha 1, que tem o número de ativos e a capacidade da mochila.
    // Checagem se a primeira linha está no formato correto.
    if (!(arquivo >> numero_de_ativos >> capacidade_mochila)) {
        arquivo.close();
        throw std::runtime_error("Arquivo de instancia mal formatado (linha 1): " + caminho_arquivo);
    }

    std::vector<Ativo> ativos;
    ativos.reserve(numero_de_ativos); 

    std::string nome;
    int valor, peso;

    // Lê as linhas de ativos.
    for (int i = 0; i < numero_de_ativos; ++i) {
        // Checagem se a linha do ativo está no formato correto.
        if (!(arquivo >> nome >> valor >> peso)) {
            arquivo.close();
            throw std::runtime_error("Arquivo de instancia corrompido (linha " + std::to_string(i + 2) + "): " + caminho_arquivo);
        }
        ativos.push_back({nome, valor, peso});
    }

    arquivo.close();
    return {capacidade_mochila, ativos};
}

/**
 * @brief Executa todas as instâncias em todos algoritmos.
 */
void MainController::executar(const std::vector<std::string>& arquivos_instancias) {
    
    // Loop principal: processa um arquivo de instância por vez.
    for (const std::string& arquivo_path : arquivos_instancias) {
        
        // Captura erros de um arquivo sem travar o programa
        try {
            // Extrai o ID do nome do arquivo
            int id_instancia = Utils::extrairIdDoNomeArquivo(arquivo_path);
            if (id_instancia == -1) {
                std::cerr << "Aviso: Nao foi possivel extrair o ID do arquivo: " 
                          << arquivo_path << ". Pulando arquivo." << std::endl;
                continue; 
            }

            // Lê os dados da instância 
            auto dados_instancia = lerInstancia(arquivo_path);
            int capacidade = dados_instancia.first;
            const std::vector<Ativo>& ativos = dados_instancia.second;

            // Decide se a Força Bruta deve ser executada
            bool executarForcaBruta = (ativos.size() <= LIMITE_ITENS_FORCA_BRUTA);

            ResultadoInstancia res_instancia;
            res_instancia.id_instancia = id_instancia;

            std::cout << "Processando instancia " << id_instancia << " (" << ativos.size() << " itens)..." << std::endl;

            // Loop dos Algoritmos a serem executados usando polimorfismo
            for (Algoritmo* alg : _algoritmos) {
                
                // Lógica para pular a Força Bruta (se necessário)
                // Usamos dynamic_cast para checar o tipo do algoritmo
                if (dynamic_cast<ForcaBruta*>(alg) && !executarForcaBruta) {
                    continue; 
                }

                // Medição de Tempo (std::chrono)
                auto start_time = std::chrono::high_resolution_clock::now();
                
                // Executa o algoritmo
                ResultadoUnitario res_unit = alg->resolver(capacidade, ativos);
                
                auto stop_time = std::chrono::high_resolution_clock::now();

                // Calcula a duração em milissegundos
                std::chrono::duration<double, std::milli> duracao = stop_time - start_time;
                res_unit.tempo_execucao_ms = duracao.count();

                // Armazena o resultado unitário
                res_instancia.resultados_dos_algoritmos.push_back(res_unit);
            }
            
            // Armazena o resultado da instância inteira
            _resultados_por_instancia.push_back(res_instancia);

        } catch (const std::exception& e) {
            // Captura erros de 'lerInstancia' ou 'extrairId'
            std::cerr << "Erro ao processar " << arquivo_path << ": " << e.what() 
                      << " Pulando esta instancia." << std::endl;
            continue; // Pula para o próximo arquivo
        }
    } // Fim do loop de arquivos
}

/**
 * @brief Gera o relatório CSV final com todos os resultados coletados.
 */
void MainController::gerarRelatorioCSV(const std::string& caminho_saida) const {
    
    std::ofstream arquivo_saida(caminho_saida);

    // Checa se é possível escrever o relatório.
    if (!arquivo_saida.is_open()) {
        throw std::runtime_error("Erro fatal: Nao foi possivel criar o arquivo de relatorio: " + caminho_saida);
    }

    // Configura a precisão de casas decimais para o CSV.
    arquivo_saida << std::fixed << std::setprecision(6);

    // Escreve o Cabeçalho do CSV
    arquivo_saida << "ID_Instancia,Algoritmo,Valor_Total,Peso_Total,Tempo_ms,Proximidade_Otimo_%\n";

    // Loop por cada Instância processada
    for (const auto& instancia : _resultados_por_instancia) {
        
        // Encontra o Valor Ótimo (se a Força Bruta rodou)
        int valor_otimo = 0;
        for (const auto& res : instancia.resultados_dos_algoritmos) {
            // (Assume que o nome_algoritmo foi definido em cada .cpp)
            if (res.nome_algoritmo == "Forca Bruta") { 
                valor_otimo = res.valor_total;
                break;
            }
        }

        // Loop por cada Resultado Unitário (linha do CSV)
        for (const auto& res_unit : instancia.resultados_dos_algoritmos) {
            
            // Calcula a proximidade (Utils já lida com valor_otimo == 0)
            double proximidade = Utils::calcularProximidade(res_unit.valor_total, valor_otimo);

            arquivo_saida << instancia.id_instancia << ","
                          << res_unit.nome_algoritmo << ","
                          << res_unit.valor_total << ","
                          << res_unit.peso_total << ","
                          << res_unit.tempo_execucao_ms << ","
                          << proximidade << "\n";
        }
    }

    arquivo_saida.close();
}