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

