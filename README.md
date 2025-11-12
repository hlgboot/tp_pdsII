# Trabalho de conclusão da disciplina Programação e Desenvolvimento de Software II

## 📖 Sobre o Projeto

Este é o repositório oficial para o desenvolvimento do Trabalho de Conclusão da Disciplina de **Programação e Desenvolvimento de Software II**.

[Vídeo de compilação](https://youtu.be/xkRTN783ESs)

**Descrição do Problema:**
O problema de otimização de portfólio de investimento consiste em selecionar, entre um conjunto de ativos disponíveis, aqueles que devem compor uma carteira de investimentos de forma a maximizar o retorno esperado e, ao mesmo tempo, respeitar restrições de recursos (como o capital disponível, por exemplo). Essa seleção deve buscar o melhor equilíbrio possível entre risco e retorno, levando em conta que nem sempre é possível investir em todos os ativos desejados.
Para simplificar e modelar o problema computacionalmente, o grupo fará uma analogia com o Problema da Mochila (Knapsack Problem), onde:

* Cada ativo representa um item;
* O custo do investimento em cada ativo representa o peso;
* O benefício de cada item será o Índice de Sharpe do ativo (calculado previamente com base em seu retorno esperado e risco, representando o retorno ajustado ao risco);
* E o capital total disponível para investir representa a capacidade máxima da mochila.

Assim, o objetivo é determinar quais ativos devem compor o portfólio de forma que o retorno total seja maximizado sem ultrapassar o orçamento disponível.

**Objetivos do Projeto:**
1. Implementar e comparar diferentes algoritmos para resolver o problema da mochila aplicado à otimização de portfólio de investimentos.
2. Avaliar o desempenho, o tempo de execução e a qualidade da solução de cada abordagem.
3. Determinar qual dos algoritmos fornece o melhor equilíbrio entre qualidade da solução e eficiência computacional.


**Algoritmos a Serem Implementados:**
1. Algoritmo Exato (Força Bruta):
Testa todas as combinações possíveis de ativos e retorna o subconjunto ótimo (a melhor solução).
Garante a solução ideal, mas tem alto custo computacional.

2. Algoritmo Aleatório:
Gera subconjuntos aleatórios de ativos que respeitam o limite de capital e seleciona o melhor encontrado em várias iterações.
Serve como base de comparação com as demais abordagens.

3. Algoritmos Gulosos:

Guloso 1: Seleciona sempre os ativos com maior benefício individual (retorno).

Guloso 2: Seleciona os ativos com o melhor relação benefício/peso (retorno/custo).

São algoritmos rápidos e simples, que nem sempre chegam à solução ótima, mas fornecem bons resultados em pouco tempo.


**Metodologia:**
Os algoritmos serão aplicados a um conjunto de aproximadamente 100 ativos simulados, cada um com valores de custo e retorno definidos.
Serão coletadas as seguintes métricas:
* Tempo de execução de cada algoritmo;
* Valor total de retorno obtido;
* Grau de proximidade da solução em relação ao ótimo (quando possível).

Os resultados serão organizados em uma tabela comparativa, permitindo discutir qual algoritmo apresenta o melhor desempenho para o problema proposto.

---

## 👥 Integrantes do Grupo

* Matheus Henriques
* Pedro Costa
* Gabriel Sette
* Mayara Guedes Leão

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++
* **Controle de versão** Git
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

Arquitetura e Organização do Sistema
O projeto é estruturado para separar claramente a interface pública (o que uma classe faz) da implementação da lógica (como ela faz).
1. Pasta include/ (Interfaces e Contratos)
Esta pasta contém todos os arquivos de cabeçalho (.hpp) e define as estruturas de dados e as interfaces que compõem o sistema.
include/algorithms/ (Estratégias):
Algoritmo.hpp: A Interface Abstrata. Define o contrato comum (resolver()) para Polimorfismo, permitindo que o controlador trate todos os algoritmos de forma uniforme.
Classes Concretas (ForcaBruta.hpp, Aleatorio.hpp, etc.): Declararam a implementação da lógica específica de resolver().
include/core/ (Estruturas de Dados):
Ativo.hpp: Define o objeto que representa o item financeiro (Peso/Custo e Valor/Retorno Ajustado ao Risco).
ResultadoUnitario.hpp: Define o objeto que armazena a solução de um algoritmo para uma única instância (valor total, tempo, etc.).
include/managers/ e include/utils/:
Define o contrato para o MainController (Orquestração) e funções auxiliares.
2. Pasta src/ (Implementação da Lógica)
Esta pasta contém o código-fonte (.cpp) que implementa o comportamento das classes declaradas no include/.
src/MainController.cpp: O Orquestrador Central. Sua responsabilidade é medir o tempo (std::chrono), ler instâncias, executar todos os algoritmos e gerar o relatório final .csv.
src/GeradorInstancias.cpp: Implementa a lógica para gerar os cenários de teste (instancia_xx.txt), calculando os atributos aleatórios e o Retorno Ajustado ao Risco de cada ativo.
src/Aleatorio.cpp, src/ForcaBruta.cpp, src/Gulosos...: Implementam a lógica específica do método resolver() para cada uma das quatro estratégias de otimização.
src/main.cpp: O ponto de partida do programa, que inicia o fluxo chamando o MainController.
Outras Pastas Chave
data/: Contém o arquivo de entrada inicial (ativos.csv) e os arquivos de instância gerados (instancia_xx.txt).
build/: Diretório de destino para o executável gerado durante a compilação.



