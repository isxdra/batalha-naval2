# batalha-naval2
Batalha Naval - Isadora - Estácio de Sá  

---


- **Nome:** Isadora Sangi  
- **Faculdade:** Estácio de Sá  

---

## Descrição
Este projeto implementa uma versão simplificada de **Batalha Naval** em C, com habilidades especiais que atingem padrões diferentes no tabuleiro (cone, cruz e octaedro).  

O código foi desenvolvido como parte do desafio proposto pela faculdade, com foco em manipulação de matrizes e aplicação de lógica condicional.

---

## Estrutura do Código

### Funções

#### `inicializarTabuleiro(...)`
- Preenche o tabuleiro com **AGUA**.
- Coloca navios (**NAVIO**) em posições fixas para teste.

#### `imprimirTabuleiro(...)`
- Percorre todas as posições do tabuleiro.
- Exibe:
  - `0` para água  
  - `3` para navio  
  - `5` para célula atingida  

#### Construção das matrizes de habilidade
- **`construirCone`** → Cria padrão triangular (cone).  
- **`construirCruz`** → Marca linha e coluna central (cruz).  
- **`construirOctaedro`** → Cria padrão em forma de losango usando distância de Manhattan.  

#### `aplicarHabilidade(...)`
- Recebe **origem X/Y** e **matriz de habilidade**.  
- Centraliza o padrão no ponto de origem.  
- Marca como **HABILIDADE** somente se:
  1. Está dentro dos limites do tabuleiro.  
  2. A célula atual é **AGUA** (não sobrescreve navios).  

---

### `main`
1. Declara tabuleiro e matrizes de habilidades.  
2. Inicializa o tabuleiro.  
3. Constrói padrões de habilidade.  
4. Aplica habilidades em posições definidas.  
5. Imprime o tabuleiro final.  

---

## Exemplo de Execução
```plaintext
0 0 0 3 0 0 0 0 0 0
0 5 0 3 0 5 0 0 0 0
0 0 5 3 5 0 0 0 0 0
...

#include <stdio.h>   // Funções de entrada/saída (ex: printf)
#include <stdlib.h>  // Funções utilitárias (ex: abs)

#define TAB_TAM 10   // Tamanho do tabuleiro (10x10)
#define HAB_TAM 3    // Tamanho das matrizes de habilidade (3x3)

#define AGUA 0       // Célula vazia
#define NAVIO 3      // Célula com navio
#define HABILIDADE 5 // Célula atingida por habilidade

