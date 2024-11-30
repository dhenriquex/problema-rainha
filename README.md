# Problema das N-Rainhas

O **Problema das N-Rainhas** é um problema clássico de otimização e backtracking, onde o objetivo é posicionar N rainhas em um tabuleiro de xadrez de \( N \times N \) de forma que nenhuma rainha ataque outra. Isso significa que nenhuma rainha pode estar na mesma linha, coluna ou diagonal que outra.

Este repositório contém uma solução implementada em C utilizando **backtracking** para resolver o problema das N-Rainhas.

## Objetivo

O objetivo do programa é encontrar uma solução para o problema das N-Rainhas para um valor de \( N \) especificado pelo usuário. O programa usa recursão e backtracking para tentar colocar uma rainha em cada linha, garantindo que as regras do problema sejam atendidas.

## Algoritmo

A solução utiliza a técnica de **backtracking**, que tenta construir a solução de forma incremental. Para cada linha do tabuleiro, o algoritmo tenta colocar uma rainha em uma das colunas, verificando se a posição é segura. Se for seguro, ele tenta colocar a rainha na linha seguinte. Caso contrário, ele faz um **backtrack** e tenta uma nova posição.

### Passos:
1. Começar pela primeira linha e tentar colocar uma rainha em cada coluna.
2. Para cada tentativa, verificar se a posição é segura (não há outra rainha na mesma coluna ou diagonais).
3. Recursivamente tentar posicionar as rainhas nas linhas seguintes.
4. Se uma solução for encontrada, imprimir o tabuleiro.
5. Se uma solução não for encontrada, retornar e tentar outras possibilidades.

## Solução em C

### Estrutura do Código:

1. **Função `movQueen`**: Verifica se é seguro colocar uma rainha em uma posição específica, levando em consideração as restrições de linha, coluna e diagonais.
2. **Função `InputQueens`**: Função recursiva que tenta colocar uma rainha em cada linha e verifica se uma solução pode ser encontrada. Se uma solução for encontrada, ela retorna `1`, caso contrário, retorna `0`.
3. **Função `main`**: Inicializa a matriz do tabuleiro e chama as funções para resolver o problema. Também cuida da alocação dinâmica da matriz e da liberação de memória após a execução.

### Código Completo:

```c
#include <stdio.h>
#include <stdlib.h>

// Função para verificar se é seguro colocar uma rainha em uma posição
int movQueen(int col, int linha, int n, int **m) {
    // Verificar a mesma coluna acima
    for (int i = 0; i < linha; i++) {
        if (m[i][col] == 1)
            return 0;
    }

    // Verificar a diagonal superior esquerda
    for (int i = linha, j = col; i >= 0 && j >= 0; i--, j--) {
        if (m[i][j] == 1)
            return 0;
    }

    // Verificar a diagonal superior direita
    for (int i = linha, j = col; i >= 0 && j < n; i--, j++) {
        if (m[i][j] == 1)
            return 0;
    }

    return 1; // Seguro colocar a rainha
}

// Função recursiva para resolver o problema das N-Rainhas
int InputQueens(int linha, int n, int **mat) {
    if (linha >= n) {
        return 1; // Solução encontrada
    }

    // Tentar posicionar uma rainha em cada coluna da linha atual
    for (int col = 0; col < n; col++) {
        if (movQueen(col, linha, n, mat)) {
            mat[linha][col] = 1; // Colocar a rainha

            // Resolver para a próxima linha
            if (InputQueens(linha + 1, n, mat)) {
                return 1; // Solução válida encontrada
            }

            // Backtracking: remover a rainha
            mat[linha][col] = 0;
        }
    }

    return 0; // Nenhuma solução encontrada
}

int main() {
    int n = 4;

    // Alocar memória dinamicamente para a matriz
    int **mat = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)calloc(n, sizeof(int)); // Inicializar com zeros
    }

    // Resolver o problema
    if (InputQueens(0, n, mat)) {
        // Imprimir a solução encontrada
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Nenhuma solução encontrada.\n");
    }

    // Liberar a memória alocada
    for (int i = 0; i < n; i++) {
        free(mat[i]);  // Liberar cada linha
    }
    free(mat);  // Liberar a matriz

    return 0;
}
