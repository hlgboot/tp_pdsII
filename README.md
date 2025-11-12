# Trabalho de conclusão da disciplina Programação e Desenvolvimento de Software II

## Sobre o Projeto

Este é o repositório oficial para o desenvolvimento do Trabalho de Conclusão da Disciplina de **Programação e Desenvolvimento de Software II**.

[Vídeo de compilação](https://youtu.be/xkRTN783ESs)

## Integrantes do Grupo

* Matheus Henriques
* Pedro Costa
* Gabriel Sette
* Mayara Guedes Leão

---

## Tecnologias Utilizadas

* **Linguagem:** C++
* **Controle de versão** Git
---

## **Contexto: Otimização de Portfólio**

O projeto aborda a Otimização de Portfólio de Investimentos. Este problema consiste em selecionar, dentro de um conjunto de ativos disponíveis, a combinação que deve compor uma carteira para maximizar o retorno esperado e, simultaneamente, respeitar as restrições de capital (orçamento). O foco é buscar o melhor equilíbrio possível entre o risco assumido e o retorno obtido.


 **Modelagem: Analogia da Mochila (Knapsack Problem)**

Para simplificar a complexidade e modelar o problema computacionalmente, utilizamos uma analogia com o Problema da Mochila.
Neste modelo, os elementos do investimento são mapeados da seguinte forma:
- O Capital Total Disponível representa a Capacidade Máxima da Mochila.
- Cada Ativo de investimento representa um Item.
- O Custo do Investimento em cada ativo representa o Peso do item.
- O Benefício de cada item é o Retorno Ajustado ao Risco (o ganho que compensa a exposição ao risco).
Assim, o objetivo principal é determinar a composição do portfólio que maximize o Retorno Ajustado ao Risco total sem ultrapassar o orçamento disponível.

## **Objetivos do Projeto**

O projeto visa atingir três metas principais:
Implementar e Comparar diferentes algoritmos para resolver o problema da mochila aplicado à otimização de portfólio de investimentos.
- Avaliar o Desempenho de cada abordagem, analisando o tempo de execução e a qualidade da solução obtida.
- Determinar qual dos algoritmos fornece o melhor equilíbrio entre qualidade da solução e eficiência computacional.
- Algoritmos Implementados
- O sistema conta com quatro estratégias de solução:
- Algoritmo Exato (Força Bruta): Testa todas as combinações possíveis de ativos, garantindo a solução ótima (a melhor possível), mas com alto custo computacional.
- Algoritmo Aleatório: Gera um grande número de subconjuntos aleatórios que respeitam o limite de capital e seleciona o melhor encontrado. Serve como base de comparação de velocidade.
- Algoritmos Gulosos:
- Guloso 1 (por Benefício): Seleciona os ativos que oferecem o maior benefício individual (retorno) primeiro.
- Guloso 2 (por Razão): Seleciona os ativos com a melhor relação benefício/peso (retorno/custo), sendo mais eficaz na alocação de capital.

## **Metodologia**

Os algoritmos foram aplicados a um conjunto de aproximadamente 100 ativos simulados, cada um com valores de custo e retorno definidos.
Foram coletadas e comparadas as seguintes métricas:
- Tempo de execução de cada algoritmo.
- Valor total de retorno obtido por cada solução.
- Grau de proximidade da solução em relação ao resultado ótimo (sempre que o Força Bruta puder ser executado).

Os resultados foram organizados em uma tabela comparativa, permitindo a análise aprofundada da eficácia e eficiência de cada metodologia.



---

## Documentação (Doxygen)

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





---

**Como Compilar e Executar o Projeto**
O projeto utiliza um Makefile para automatizar a compilação de todos os módulos (.cpp) e a geração do executável final. O comando deve ser executado a partir da pasta raiz do projeto (tp_pdsII).
1. Compilar o Projeto (Geração do Executável)
Use o comando make para compilar todo o código e gerar o executável na pasta build/.
make
O que acontece: O Makefile executa o g++ com a flag -I./include para compilar todos os arquivos (.cpp) e cria o executável principal, geralmente nomeado como main ou tp_pdsII.
2. Executar o Projeto (Rodar a Análise)
Após a compilação, execute o binário gerado, que está na pasta build/.
./build/main
O que acontece: O programa irá iniciar o fluxo de análise:
Geração de Instâncias: Cria 50 arquivos .txt de teste (instâncias pequenas e grandes).
Processamento: Executa sequencialmente os 4 algoritmos (Força Bruta, Aleatório, Gulosos) em todas as instâncias.
Saída: Exibe as informações de processamento no terminal e gera um arquivo de relatório (resultados.csv ou similar) com as métricas comparativas.

---




