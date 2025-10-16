#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

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

} // namespace Utils

#endif // UTILS_H