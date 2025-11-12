# Trabalho de conclusão da disciplina Programação e Desenvolvimento de Software II

## 📖 Sobre o Projeto

Este é o repositório oficial para o desenvolvimento do Trabalho de Conclusão da Disciplina de **Programação e Desenvolvimento de Software II**.

[Vídeo de compilação](https://youtu.be/xkRTN783ESs)

## 👥 Integrantes do Grupo

* Matheus Henriques
* Pedro Costa
* Gabriel Sette
* Mayara Guedes Leão

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++
* **Controle de versão** Git
* **Documentação** Doxygen
---

## **Contexto: Otimização de Portfólio**

O projeto aborda a Otimização de Portfólio de Investimentos. Este problema consiste em selecionar, dentro de um conjunto de ativos disponíveis, a combinação que deve compor uma carteira para maximizar o retorno esperado e, simultaneamente, respeitar as restrições de capital (orçamento). O foco é buscar o melhor equilíbrio possível entre o risco assumido e o retorno obtido.


 **Modelagem: Analogia da Mochila (Knapsack Problem)**

Para simplificar a complexidade e modelar o problema computacionalmente, utilizamos uma analogia com o Problema da Mochila.
Neste modelo, os elementos do investimento são mapeados da seguinte forma:
- O Capital Total Disponível representa a Capacidade Máxima da Mochila.
- Cada Ativo de investimento representa um Item.
- O Custo do Investimento em cada ativo representa o Peso do item.
- O Benefício de cada item é o Índice de Sharpe ou Retorno Ajustado ao Risco (o ganho que compensa a exposição ao risco).
Assim, o objetivo principal é determinar a composição do portfólio que maximize o Retorno Ajustado ao Risco total sem ultrapassar o orçamento disponível.

## **Objetivos do Projeto**

O projeto visa atingir três metas principais:
Implementar e comparar diferentes algoritmos para resolver o problema da mochila aplicado à otimização de portfólio de investimentos.
- Avaliar o Desempenho de cada abordagem, analisando o tempo de execução e a qualidade da solução obtida.
- Determinar qual dos algoritmos fornece o melhor equilíbrio entre qualidade da solução e eficiência computacional.

## **Metodologia**

Os algoritmos foram aplicados a conjuntos de 30 (Instâncias pequenas) e 100 (Instâncias grandes) ativos simulados, cada um com valores de custo e retorno definidos.
Foram coletadas e comparadas as seguintes métricas:
- Tempo de execução de cada algoritmo.
- Valor total de retorno obtido por cada solução.
- Grau de proximidade da solução em relação ao resultado ótimo (sempre que o Força Bruta puder ser executado).

Os resultados foram organizados em uma tabela comparativa, permitindo a análise aprofundada da eficácia e eficiência de cada metodologia.

### Funcionalidades Entregues
* **Geração de Instâncias:** Um sistema robusto (`GeradorInstancias`) que cria 50 cenários de teste (`.txt`), divididos em 25 instâncias pequenas (para análise de qualidade) e 25 grandes (para análise de performance). O benefício de cada ativo é calculado usando o Índice de Sharpe.
* **Implementação de 4 Algoritmos:**
    1.  **Força Bruta:** Solução ótima (recursiva) que testa todas as 2^n combinações.
    2.  **Aleatório (Monte Carlo):** Heurística que gera 10.000 soluções aleatórias e guarda a melhor.
    3.  **Guloso por Benefício:** Heurística que prioriza os ativos com maior Índice de Sharpe.
    4.  **Guloso por Razão:** Heurística avançada que prioriza a razão `Sharpe / Preço`.
* **Orquestrador de Análise:** Um `MainController` que gerencia o fluxo, executa os algoritmos (usando Polimorfismo), mede o tempo com `std::chrono` e gera o relatório.
* **Geração de Relatório:** Geração automática de um arquivo `relatorio_final.csv` com todas as métricas para análise.

### Itens Fora do Escopo
O projeto **não** implementa a Otimização de Portfólio de Markowitz (com correlação entre ativos). A analogia da mochila assume que o benefício de cada ativo é **independente**, o que é uma simplificação necessária para permitir a comparação dos algoritmos gulosos com a solução ótima.

---

## Compilação e Execução
O projeto utiliza um Makefile automático para gerenciar a compilação.

### Pré-requisitos

1. Um compilador C++14 ou superior (ex: `g++`).
2. `make`

### Compilação

1. Na raiz do projeto, para limpar compilações anteriores, execute o comando:
    ```bash
    make clean
    ```
2. Ainda na raiz, para compilar o programa, execute o comando:
    ```bash
    make
    ```

### Execução
1. Na raiz do projeto, para rodar a aplicação, execute o comando:
    ```bash
    make run
    ```
O programa:
1. Gera 50 arquivos .txt (25 pequenos, 25 grandes) em data/
2. Processa todas as instâncias, exibindo o progresso no console
3. Gera o relatório results/relatorio_final.csv
---

## 📖 Documentação (Doxygen)

Toda a documentação técnica da API do código-fonte é gerada automaticamente pelo Doxygen.

### Como Gerar

1.  Certifique-se de que você tem o [Doxygen](https://www.doxygen.nl/) instalado.
2.  Na raiz do projeto, execute o comando:
    ```bash
    doxygen
    ```
    (Ou, alternativamente, rode `make docs`).
3.  A documentação completa será gerada na pasta `docs/doxygen/html/`.
4.  Abra o arquivo `docs/doxygen/html/index.html` no seu navegador para consultar.

---

## **Resultados**

A análise do desempenho dos algoritmos foi realizada em 50 instâncias (25 pequenas para validar a qualidade e 25 grandes para medir a escalabilidade), comparando o Tempo de Execução e a Qualidade da Solução (Retorno Ajustado ao Risco obtido).

**I. Análise em Instâncias Pequenas (Teste de Qualidade)**
As instâncias pequenas permitiram que o Algoritmo Força Bruta calculasse o valor ótimo (100% de Proximidade).

A. Qualidade da Solução
- O Algoritmo Força Bruta alcançou 100% da solução ótima. O Guloso por Razão obteve o melhor desempenho entre as heurísticas, atingindo 99.79% da solução ótima.
- Força Bruta: 100.00%
- Guloso por Razão: 99.79%
- Guloso por Benefício: 97.20%
- Aleatório: 91.77%

B. Performance de Execução
- A diferença de eficiência entre o método exato e as heurísticas é evidente.
- O Força Bruta consumiu a maior parte do tempo, com uma média de 20.480,052 ms.
- Os algoritmos Gulosos e o Aleatório executaram em tempo insignificante para as instâncias pequenas (entre 0.009 ms e 22.621 ms).

**II. Análise em Instâncias Grandes (Teste de Escalabilidade)**
O Força Bruta foi desconsiderado na análise de instâncias grandes devido ao seu tempo de execução inviável. A comparação foca nas heurísticas mais rápidas.

A. Qualidade da Solução
- O Guloso por Razão manteve a liderança na qualidade da carteira.
- Guloso por Razão: Média de 91.781 no Valor Total (Melhor resultado).
- Guloso por Benefício: Média de 88.569.
- Aleatório: Média de 74.006.

B. Performance de Execução
- O algoritmo Aleatório foi o mais lento das heurísticas.
- Aleatório: Média de 66.912 ms.
- Gulosos (Razão e Benefício): Foram extremamente rápidos, executando em torno de 0.028 ms.


## **Conclusão dos Resultados**
O Algoritmo Guloso por Razão se destaca como a solução mais eficiente e de maior qualidade para o Problema da Mochila aplicado à otimização de portfólio. Ele oferece um resultado quase ótimo em tempo mínimo, provando ser o algoritmo ideal para cenários reais e de maior escala.


**Lições Chave Aprendidas**

O projeto de otimização em C++ reforçou lições fundamentais da disciplina, abrangendo desde a escolha da metodologia até a prática de codificação em equipe.

**1. Conclusão Metodológica**

- O Valor do Equilíbrio: Os resultados validaram que o Algoritmo Guloso por Razão é a solução ideal na prática. Ele oferece um resultado de alta qualidade em tempo insignificante, provando ser o     modelo mais eficiente para problemas de larga escala.
- Função do Força Bruta: O Força Bruta ($O(2^n)$) é inviável computacionalmente e deve ser usado apenas como ponto de referência para validar a precisão das heurísticas.

    
**2. Lições de Design e Código**

- Design Orientado a Objetos (POO): O planejamento prévio (via User Stories e Cartões CRC) foi essencial para mapear as responsabilidades das classes, resultando em uma arquitetura limpa e           extensível.
- Poder do Polimorfismo: A criação da classe abstrata Algoritmo permitiu que o controlador executasse as quatro estratégias de forma uniforme, garantindo flexibilidade e facilitando a adição de      novos métodos no futuro.
- C++ Moderno: A precisão do projeto dependeu do uso correto de recursos atuais do C++, como std::mt19937 para aleatoriedade de alta qualidade e std::chrono para medições de tempo exatas.

**3. Lições de Colaboração e Processo**
- Controle de Versão: O uso obrigatório de Pull Requests (PRs) e branches no Git foi crucial para manter a integridade do código, permitindo que a contribuição de cada membro fosse revisada e        integrada de forma controlada.
- Programação Defensiva: A implementação de checagens rigorosas (como a restrição de capacidade da mochila) garantiu que o sistema fosse estável e produzisse apenas soluções válidas.

---

## **Arquitetura e Organização do Sistema**








