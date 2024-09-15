# Push_swap

### 42 Luanda - Escola de Programação

## Descrição do Projeto

O projeto **Push_swap** consiste em desenvolver um conjunto de algoritmos que ordenam uma pilha de números inteiros com o menor número possível de operações. O objetivo é criar um programa que receba uma sequência de números inteiros como argumento e, através de um conjunto específico de operações, ordene essa sequência em uma das pilhas.

Esse projeto é uma excelente oportunidade para praticar a implementação de algoritmos de ordenação, manipulação de estruturas de dados como pilhas e otimização de operações.

## Regras

- Você tem duas pilhas à sua disposição: `a` e `b`.
- A pilha `a` contém números inteiros desordenados no início e a pilha `b` começa vazia.
- Seu objetivo é ordenar todos os números na pilha `a` usando o menor número de operações possível.
- As operações permitidas são as seguintes:
  
  - **sa (swap a)**: Troca os dois primeiros elementos no topo da pilha `a`. Não faz nada se houver apenas um ou nenhum elemento.
  - **sb (swap b)**: Troca os dois primeiros elementos no topo da pilha `b`. Não faz nada se houver apenas um ou nenhum elemento.
  - **ss**: Executa `sa` e `sb` simultaneamente.
  - **pa (push a)**: Move o primeiro elemento do topo da pilha `b` para o topo da pilha `a`. Não faz nada se a pilha `b` estiver vazia.
  - **pb (push b)**: Move o primeiro elemento do topo da pilha `a` para o topo da pilha `b`. Não faz nada se a pilha `a` estiver vazia.
  - **ra (rotate a)**: Move todos os elementos da pilha `a` uma posição para cima. O primeiro elemento se torna o último.
  - **rb (rotate b)**: Move todos os elementos da pilha `b` uma posição para cima. O primeiro elemento se torna o último.
  - **rr**: Executa `ra` e `rb` simultaneamente.
  - **rra (reverse rotate a)**: Move todos os elementos da pilha `a` uma posição para baixo. O último elemento se torna o primeiro.
  - **rrb (reverse rotate b)**: Move todos os elementos da pilha `b` uma posição para baixo. O último elemento se torna o primeiro.
  - **rrr**: Executa `rra` e `rrb` simultaneamente.

## Objetivo

O objetivo principal é minimizar o número de operações necessárias para ordenar a pilha `a`. O número máximo de operações permitidas varia de acordo com o número de elementos na pilha:
- **100 números**: Máximo de 700 operações.
- **500 números**: Máximo de 5500 operações.

## Como Executar

### Compilação
Para compilar o projeto, execute o comando:

```bash
make
