#include "utils/Utils.h" // Inclui o cabeçalho correspondente
#include <stdexcept>      // Para std::invalid_argument (em std::stoi)
#include <sstream>        // Para std::ostringstream (formatação de strings)
#include <iomanip>        // Para std::setw e std::setfill (zeros à esquerda)
#include <string>         // Para std::string e std::stoi

namespace Utils {

    /**
     * @brief Gera uma lista de nomes de arquivos de instância formatados.
     */
    std::vector<std::string> gerarNomesArquivosInstancias(int numeroDeInstancias, const std::string& diretorio) {
        
        std::vector<std::string> nomes;
        if (numeroDeInstancias <= 0) {
            return nomes;
        }

        nomes.reserve(numeroDeInstancias); // Otimização de performance

        // Garante que 50 instâncias sejam formatadas como "01" e 100 como "001"
        int width = std::to_string(numeroDeInstancias).length();
        if (width < 2) {
            width = 2; // Garante pelo menos 2 dígitos (ex: 01, 02)
        }

        for (int i = 1; i <= numeroDeInstancias; ++i) {
            std::ostringstream oss;
            oss << diretorio << "instancia_" 
                << std::setw(width) << std::setfill('0') << i 
                << ".txt";
            
            nomes.push_back(oss.str());
        }

        return nomes;
    }


    /**
     * @brief Calcula o Índice de Sharpe.
     */
    double calcularIndiceSharpe(double retorno_esperado, double volatilidade, double taxa_livre_risco) {
        
        // Programação defensiva: evita divisão por zero.
        if (volatilidade == 0.0) {
            return 0.0;
        }

        return (retorno_esperado - taxa_livre_risco) / volatilidade;
    }


    /**
     * @brief Calcula a proximidade de uma solução em relação ao ótimo (em %).
     */
    double calcularProximidade(int valor_obtido, int valor_otimo) {
        
        if (valor_otimo == 0) {
            // Se o ótimo é 0 e o obtido também é 0, a solução é 100% precisa.
            return (valor_obtido == 0) ? 100.0 : 0.0;
        }

        // Força a divisão de ponto flutuante
        return (static_cast<double>(valor_obtido) / valor_otimo) * 100.0;
    }


    /**
     * @brief Extrai o ID numérico de um nome de arquivo de instância.
     */
    int extrairIdDoNomeArquivo(const std::string& nomeArquivo) {
        try {
            // Encontra a posição do último '_'
            size_t inicio = nomeArquivo.find_last_of('_');
            if (inicio == std::string::npos) return -1;

            // Encontra a posição do último '.' (extensão)
            size_t fim = nomeArquivo.find_last_of('.');
            if (fim == std::string::npos || fim < inicio) return -1;

            // Extrai a substring com o número (ex: "05")
            std::string numero_str = nomeArquivo.substr(inicio + 1, fim - inicio - 1);

            // Converte para inteiro (std::stoi lida com zeros à esquerda)
            return std::stoi(numero_str);

        } catch (...) {
            // Pega qualquer exceção do std::stoi ou std::substr
            return -1;
        }
    }

} // namespace Utils