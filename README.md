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

## 🚀 Como Começar (Guia para o grupo)

Este guia vai te ensinar a baixar o projeto para sua máquina, fazer alterações e enviá-las de volta para o repositório de forma organizada.

### Passo 0: Pré-requisitos

Antes de tudo, você precisa ter o **Git** instalado no seu computador.
* **Para instalar o Git:** Acesse [git-scm.com/downloads](https://git-scm.com/downloads) e baixe a versão para o seu sistema operacional. A instalação é simples, basta seguir o padrão "next, next, finish".

### Passo 1: Clonar o Repositório

"Clonar" significa fazer uma cópia do projeto que está no GitHub para o seu computador. Você só precisa fazer isso **uma vez**.

1.  Abra o terminal (ou Git Bash no Windows).
2.  Navegue até a pasta onde você quer salvar o projeto. Ex: `cd Documentos/ProjetosFaculdade`.
3.  Execute o comando abaixo (copie a URL do botão verde "<> Code" no topo desta página):

```bash
git clone https://github.com/hlgboot/tp_pdsII/
```

Pronto! Agora você tem uma pasta com o nome do projeto no seu computador.

### Passo 2: O Fluxo de Trabalho

Para evitar conflitos e manter nosso trabalho organizado, vamos seguir este fluxo sempre que formos fazer uma nova alteração (uma nova funcionalidade, uma correção de bug, etc.).

#### 1. Sincronize com o Repositório Principal

Antes de começar a codificar, sempre puxe as últimas atualizações que alguém possa ter enviado. Isso evita conflitos.

```bash
# Entre na pasta do projeto
cd tp_pdsII
# Puxe as atualizações da branch principal (geralmente 'main' ou 'master')
git pull origin main
```

#### 2. Crie uma Nova "Branch" (um Ramo) para sua Tarefa

Nunca trabalhe diretamente na branch `main`. A `main` é o nosso código estável. Crie uma branch para a sua tarefa específica.

Dê um nome descritivo para sua branch. Por exemplo:
* Se for criar a tela de login: `feature/tela-login`
* Se for corrigir um bug no cadastro: `fix/bug-cadastro`

Use o comando:
```bash
# O comando -b já cria a branch e muda para ela
git checkout -b nome-da-sua-branch
```

#### 3. Faça suas Alterações

Agora sim! Abra o projeto no seu editor de código e faça toda a programação necessária para a sua tarefa. Salve os arquivos normalmente.

#### 4. "Comite" suas Alterações

Quando terminar (ou atingir um ponto importante), você precisa "salvar" suas alterações no Git. Isso é feito em dois passos:

```bash
# 1. Adiciona TODOS os arquivos que você modificou para a "área de preparação"
git add .

# 2. "Comita" os arquivos, adicionando uma mensagem clara sobre o que você fez
git commit -m "feat: implementa funcionalidade de login de usuário"
```
> **Dica de mensagem de commit:** Seja claro e objetivo. Bons exemplos: `fix: corrige erro no cálculo do total`, `docs: atualiza o README com instruções`.

#### 5. Envie sua Branch para o GitHub

Agora que as alterações estão salvas localmente, envie sua branch para o repositório na nuvem (GitHub).

```bash
# A primeira vez que você envia a branch, pode precisar usar o comando mais longo
git push --set-upstream origin nome-da-sua-branch

# Nas próximas vezes na MESMA branch, pode usar apenas:
git push
```

#### 6. Abra um "Pull Request" (PR)

A última etapa! Vá para a página do nosso repositório no GitHub. Você verá uma notificação amarela com o nome da sua branch e um botão **"Compare & pull request"**.

1.  Clique nesse botão.
2.  Adicione um título e uma breve descrição do que você fez.
3.  Na direita, em "Reviewers", marque os outros integrantes do grupo.
4.  Clique em **"Create pull request"**.

O "Pull Request" é um pedido para juntar (fazer o "merge") o seu código da sua branch na branch principal (`main`). Ele permite que o resto do grupo revise suas alterações antes que elas entrem na versão final do projeto.

---

 ### 7: Finalizando uma Tarefa e Começando a Próxima
    
  Depois que seu "Pull Request" for aprovado e o código for incorporado à branch `main`, sua branch de funcionalidade (ex: `feature/tela-login`) já cumpriu seu papel. Você pode removê-la e começar uma nova tarefa.
    
  1.  **Volte para a branch principal (`main`):**
    
        ```bash
        git checkout main
        ```
    
  2.  **Sincronize novamente com o repositório:**
        Isso garante que você tenha a versão mais atualizada do projeto, incluindo as alterações que você acabou de adicionar.
    
        ```bash
        git pull origin main
        ```
    
  3.  **(Opcional, mas recomendado) Apague a branch antiga:**
        Para manter o repositório local limpo, você pode apagar a branch que não será mais usada.
    
        ```bash
        git branch -d nome-da-sua-branch-antiga
        ```
    
  4.  **Comece o ciclo novamente:**
        Agora você está pronto para criar uma nova branch para sua próxima tarefa, a partir da `main` atualizada.
    
        ```bash
        git checkout -b nome-da-nova-branch
        ```
    
