# Trabalho de conclusão da disciplina Programação e Desenvolvimento de Software II

## 📖 Sobre o Projeto

Este é o repositório oficial para o desenvolvimento do Trabalho de Conclusão da Disciplina de **Programação e Desenvolvimento de Software II**.

---

## 👥 Integrantes do Grupo

* Matheus Henriques
* Pedro Costa
* Gabriel Sette

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++

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
git clone [URL_DO_REPOSITORIO_AQUI]
```

Pronto! Agora você tem uma pasta com o nome do projeto no seu computador.

### Passo 2: O Fluxo de Trabalho

Para evitar conflitos e manter nosso trabalho organizado, vamos seguir este fluxo sempre que formos fazer uma nova alteração (uma nova funcionalidade, uma correção de bug, etc.).

#### 1. Sincronize com o Repositório Principal

Antes de começar a codificar, sempre puxe as últimas atualizações que alguém possa ter enviado. Isso evita conflitos.

```bash
# Entre na pasta do projeto
cd [NOME-DO-SEU-REPOSITORIO]

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
    
