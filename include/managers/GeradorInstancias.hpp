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
private:
    // Membro de estado privado para rastrear o ID
    int _proximoId = 1;
};

#endif // GERADOR_INSTANCIAS_H