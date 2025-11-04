#include "algorithms/ForcaBruta.hpp" 
#include "core/Ativo.hpp"           
#include "core/ResultadoUnitario.hpp" 

#include <vector>                                  
#include <iostream>                                

// Função para encontrar a melhor combinação de ativos usando recursão, onde testamos todas as combinações possíveis de ativos.

// Pense nesta função como um clone[0], que é o primeiro nó de uma grande árvore de decisões, e que está olhando para um ativo (ex: Ativo A).
// Ele tem duas tarefas (Decisões A e B), que criam os dois "galhos" que saem deste nó:
// 1. (Decisão A) Criar um clone[1] para explorar TODA a sub-árvore de caminhos IGNORANDO o Ativo A.
// 2. (Decisão B) Criar um clone[2] para explorar TODA a sub-árvore de caminhos PEGANDO o Ativo A (se couber).
// O clone[0] espera os clones[1] e [2] (e todos os filhos deles) terminarem seu trabalho e "morrerem" (retornarem). Só então o clone[0] morre também.
void encontrarMelhorCombinacao(
    int indice_atual, 
    int capacidade, 
    const std::vector<Ativo>& todos_ativos,
    std::vector<Ativo>& mochila_temporaria, // É a mesma mochila para todos os clones
    int peso_atual,
    int beneficio_atual,
    ResultadoUnitario& melhor_resultado_geral // É a mesma referência para todos os clones
) {

    // Toda vez que a função recursiva é chamada, verificamos se chegamos ao fim da lista de ativos.
    // Condiação de parada da função: Checa se todos os ativos foram considerados.
    if (indice_atual == todos_ativos.size()) { // Quando chegamos aqui, significa que um caminho foi completamente explorado.

        // Compara o beneficio_atual da mochila que foi montada (mochila_temporaria) com o benefício da melhor mochila já encontrada (melhor_resultado_geral).
        if (beneficio_atual > melhor_resultado_geral.valor_total) { // Se o benefício atual for melhor, atualiza a melhor solução encontrada.
            melhor_resultado_geral.valor_total = beneficio_atual;
            melhor_resultado_geral.peso_total = peso_atual;
            melhor_resultado_geral.ativos_selecionados = mochila_temporaria;
        }
        return; // Paramos a recursão aqui e voltamos para a chamada anterior, ou seja, o "clone morre".
    }
    
    // Decisão A: NÃO PEGAR o ativo 'indice_atual'.
    // A função encontrarMelhorCombinacao chama a si mesma recursivamente, passando (indice_atual + 1) para ir olhar o próximo ativo. 
    // Ela explora o caminho onde NÃO seleciona o ativo indice_atual.
    encontrarMelhorCombinacao(
        indice_atual + 1, 
        capacidade, todos_ativos, 
        mochila_temporaria, 
        peso_atual, beneficio_atual, 
        melhor_resultado_geral
    ); // O programa PAUSA aqui e executa essa nova chamada (e todas as sub-chamadas dela) completamente até que ela chegue ao return da condição de parada imposta.
    /* 
     Basicamente, aqui geramos um clone[1] (esta chamada acima) da função atual (clone[0]), onde avançamos para o próximo índice sem alterar a mochila_temporaria, peso_atual ou beneficio_atual. 
     Esse clone[1] segue seu próprio caminho, ele vai chamando/gerando outros clones[1.1], [1.2]...[1.x] (para o próximo ativo, e o próximo...) até que, uma hora, um dos seus clones[1.x]
     é chamado com indice_atual == todos_ativos.size(). Nesse momento, a condição de parada é atingida e o clone[1.x] morre (retorna), então volta para o clone [1.x-1], e isso acontece uma 
     cadeia de vezes, até chegar no clone[1] novamente. Quando o clone[1] morre (retorna), a execução do clone[0] continua para a Decisão B.
    */
    


    // Decisão B: Tentar pegar o ativo 'indice_atual'.
    // Esta decisão só é executada depois que a chamada da "Decisão A" (clone[1] e todos os seus descendentes) terminou.
    const Ativo& ativo_atual = todos_ativos[indice_atual]; // Esse é o ativo atual que estamos testando, baseado no indice_atual. Pegamos ele para acessar seu peso.

    // Se couber na mochila, adicionamos o ativo na mochila temporária
    if (peso_atual + ativo_atual.peso <= capacidade) {

        // Se coube, adicionamos o ativo atual na mochila.
        // A mochila_temporaria (que estava [] no clone[0]) agora fica [Ativo 0].
        mochila_temporaria.push_back(ativo_atual);
        
        // Agora que o ativo está na mochila, chamamos a função recursiva novamente e vamos analisar o próximo item.
        // Esta chamada é o clone[2] (o segundo filho do clone[0]), este clone vai explorar todos os caminhos possíveis com o 'ativo_atual' já dentro.
        // Ele também vai passar pela sua própria Decisão A e B novamente.
        // Aqui, estamos levando esta mochila com o novo item ([Ativo 0]) e com o peso e benefício atualizados.
        encontrarMelhorCombinacao(
            indice_atual + 1, 
            capacidade, todos_ativos, 
            mochila_temporaria, 
            peso_atual + ativo_atual.peso,
            beneficio_atual + ativo_atual.valor, 
            melhor_resultado_geral
        );
        
        // Removemos o ativo adicionado para testar outras combinações 
        // Esta linha só é executada depois que a chamada da "Decisão B" terminou e retornou. Ou seja, o clone[2] (e todos os seus descendentes) morreram (retornaram).
        // A mochila_temporaria é uma referência (&). Quando a chamada da "Decisão B" (clone[2]) retornou, ela deixou o ativo_atual dentro da mochila.
        
        // Removemos o ativo adicionado para testar outras combinações 
        // Esta linha só é executada depois que a chamada da "Decisão B" terminou e retornou. Ou seja, o clone[2] (e todos os seus descendentes) morreram (retornaram).
        // A mochila_temporaria é uma referência (&). Quando a chamada da "Decisão B" (clone[2]) retornou, ela deixou o ativo_atual dentro da mochila.
        // O pop_back() remove o último item que foi adicionado, para "limpar" a mochila e devolvê-la ao estado em que estava antes da "Decisão B" ter começado.
        // Isso é crucial para que, quando esta função (clone[0]) terminar e retornar para quem a chamou (a função 'resolver'),
        // a 'mochila_temporaria' esteja limpa e vazia, como 'resolver' a criou.
        mochila_temporaria.pop_back();
    }
}

ResultadoUnitario ForcaBruta::resolver(int capacidade, const std::vector<Ativo>& ativos) {
    
    ResultadoUnitario melhor_resultado; 
    melhor_resultado.nome_algoritmo = "Forca Bruta"; 
    melhor_resultado.valor_total = 0; 
    melhor_resultado.peso_total = 0;

    std::vector<Ativo> mochila_temporaria; 
    
    // Chama a função auxiliar recursiva para explorar todas as combinações possíveis
    // Esa primeira chamada é o clone[0] que inicia todo o processo.
    encontrarMelhorCombinacao(
        0, // Indice atual, começa do primeiro ativo
        capacidade, // Capacidade da mochila
        ativos, // Lista de todos os ativos
        mochila_temporaria, // Mochila para testar cada combinação
        0, 0, // Estes são o 'peso_atual' e 'beneficio_atual' iniciais.
        melhor_resultado // Valor passado por referência para armazenar o melhor resultado encontrado
    );

    return melhor_resultado; 
}