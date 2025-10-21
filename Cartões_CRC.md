# E5b: Modelagem (Cartões CRC)

Este documento descreve a arquitetura do sistema usando a metodologia de Cartões Classe-Responsabilidade-Colaborador (CRC).

---

| Classe: **`GeradorInstancias`** | |
| :--- | :--- |
| **Responsabilidades** | **Colaboradores** |
| - Gerar atributos aleatórios (preço, retorno, volatilidade). | `Utils` |
| - Orquestrar o cálculo do benefício chamando `Utils::calcularIndiceSharpe`. | |
| - Calcular a capacidade da mochila (50% da soma dos pesos). | |
| - Salvar os arquivos `instancia_xx.txt` formatados. | |

| (Namespace): **`Utils`** | |
| :--- | :--- |
| **Responsabilidades** | **Colaboradores** |
| - Gerar a lista de nomes de arquivos de instância. | (Nenhum) |
| - Calcular a proximidade do ótimo (%). | |
| - Calcular o Índice de Sharpe a partir do retorno, volatilidade e taxa livre de risco. | |
| - Extrair o ID da instância do nome do arquivo. | |

| Classe: **`Algoritmo`** (Interface Abstrata) | |
| :--- | :--- |
| **Responsabilidades** | **Colaboradores** |
| - Definir a interface comum `resolver()` para todas as estratégias de otimização. | `Ativo` |
| | `ResultadoUnitario` |

| Classe: **`ForcaBruta`** (e `Aleatorio`, `GulosoBeneficio`, `GulosoRazao`) | |
| :--- | :--- |
| **Responsabilidades** | **Colaboradores** |
| - Implementar a lógica específica do `resolver()`. | `Algoritmo` |
| - Encontrar um subconjunto de ativos que respeite a capacidade. | `Ativo` |
| - Calcular o `valor_total` e `peso_total` da solução encontrada. | `ResultadoUnitario` |
| - Retornar um objeto `ResultadoUnitario` com a solução. | |

| Classe: **`MainController`** | |
| :--- | :--- |
| **Responsabilidades** | **Colaboradores** |
| - Armazenar o vetor de algoritmos a serem executados. | `Algoritmo` |
| - Orquestrar o fluxo de análise (`executar()`). | `ResultadoInstancia` |
| - Ler e processar (fazer o *parse*) de um arquivo de instância. | `Ativo` |
| - Medir o tempo de execução (`std::chrono`) de cada `resolver()`. | |
| - Armazenar os resultados de todas as instâncias. | |
| - Orquestrar a geração do relatório final CSV. | |
