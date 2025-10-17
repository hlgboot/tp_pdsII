#ifndef GERADOR_INSTANCIAS_H
#define GERADOR_INSTANCIAS_H

#include <string>
#include <vector>

class GeradorInstancias {
public:
    // Gera e salva um número especificado de instâncias em arquivos .txt
    void gerarEsalvar(
        int numeroDeInstancias, 
        int itensPorInstancia,
        const std::string& arquivoEntrada,
        const std::string& diretorioSaida
    );
};

#endif // GERADOR_INSTANCIAS_H