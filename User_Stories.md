# E5a: Histórias de Usuário (User Stories)

Este documento descreve as principais funcionalidades e requisitos do sistema sob a perspectiva do usuário (o "Analista").

---

### HU1: Geração de Cenários Realistas
* **Como um** Analista,
* **eu quero** que o sistema gere cenários de teste onde o benefício de cada ativo é calculado usando o Índice de Sharpe,
* **para que** a métrica de valor seja financeiramente realista e represente o retorno ajustado ao risco de cada ativo.

### HU2: Geração de Cenários Balanceados
* **Como um** Analista,
* **eu quero** que o sistema gere 25 instâncias pequenas (para o teste de solução ótima) e 25 instâncias grandes (para o teste de performance),
* **para que** eu possa avaliar tanto a *qualidade* quanto a *escalabilidade* dos algoritmos.

### HU3: Execução da Análise
* **Como um** Analista,
* **eu quero** executar todos os 4 algoritmos nas instâncias pequenas e os 3 algoritmos rápidos nas instâncias grandes,
* **para que** o sistema colete automaticamente o tempo de execução e o retorno obtido por cada estratégia em cada cenário.

### HU4: Obtenção de Relatório Consolidado
* **Como um** Analista,
* **eu quero** que o sistema gere um único arquivo `resultados.csv` formatado,
* **para que** eu possa facilmente analisar e comparar as métricas de todos os testes (tempo, retorno, proximidade do ótimo).

### HU5: Tratamento de Erros de Arquivo
* **Como um** Analista,
* **eu quero** ser informado com uma mensagem de erro clara se um arquivo de entrada (como `ativos.csv` ou uma instância) não for encontrado,
* **para que** o programa não trave inesperadamente e eu saiba o que corrigir.
