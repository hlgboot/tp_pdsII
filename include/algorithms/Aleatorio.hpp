#ifndef ALEATORIO_H
#define ALEATORIO_H

#include "Algoritmo.hpp"

class Aleatorio : public Algoritmo {
public:

    //Resolve o problema da mochila por meio de tentartivas aleatórias.
    //O maior valor dentro das soluções encontradas é retornado
    //O parametro capacidade apronta a capacidade máxima da mochila seja peso ou orçamento
    //O parametro ativos é um vetor contendo todos os ativos disponíveis para seleção.
    //O resultado é o ResultadoUnitario com uma solução aleatória contendo:
    //o nome do algorítmo, o valor total obtido, o peso total utilizado e o conjunto de ativos escolhidos.
     
    ResultadoUnitario resolver(int capacidade, const std::vector<Ativo>& ativos) override;
};

#endif // ALEATORIO_H