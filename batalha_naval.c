#include <stdio.h>
#include <stdlib.h>

#define TAB_TAM 10      // Tamanho do tabuleiro (10x10)
#define HAB_TAM 3       // Tamanho das habilidades (3x3)
#define AGUA 0          // Valor 0 representa água
#define NAVIO 3         // Valor 3 representa navio
#define HABILIDADE 5    // Valor 5 representa habilidade aplicada

// Inicializa o tabuleiro com água e coloca alguns navios
void inicializarTabuleiro(int tabuleiro[TAB_TAM][TAB_TAM]) {
    for (int i = 0; i < TAB_TAM; i++) {
        for (int j = 0; j < TAB_TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Colocando alguns navios fixos (valor 3)
    tabuleiro[2][2] = NAVIO;
    tabuleiro[4][4] = NAVIO;
    tabuleiro[6][6] = NAVIO;
    tabuleiro[2][6] = NAVIO;
    tabuleiro[6][2] = NAVIO;
}

// Imprime o tabuleiro no console
void imprimirTabuleiro(int tabuleiro[TAB_TAM][TAB_TAM]) {
    for (int i = 0; i < TAB_TAM; i++) {
        for (int j = 0; j < TAB_TAM; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf("0 ");
            else if (tabuleiro[i][j] == NAVIO)
                printf("3 ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("5 ");
        }
        printf("\n");
    }
}

// Constrói matriz de habilidade em forma de cone
void construirCone(int matriz[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (j >= HAB_TAM / 2 - i && j <= HAB_TAM / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Constrói matriz de habilidade em forma de cruz
void construirCruz(int matriz[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (i == HAB_TAM / 2 || j == HAB_TAM / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Constrói matriz de habilidade em forma de losango (octaedro)
void construirOctaedro(int matriz[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (abs(i - 1) + abs(j - 1) <= 1)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAB_TAM][TAB_TAM], int habilidade[HAB_TAM][HAB_TAM], int origemX, int origemY) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            int posX = origemX + i - HAB_TAM / 2;
            int posY = origemY + j - HAB_TAM / 2;

            if (posX >= 0 && posX < TAB_TAM && posY >= 0 && posY < TAB_TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[posX][posY] == AGUA) {
                    tabuleiro[posX][posY] = HABILIDADE;
                }
            }
        }
    }
}

// Função principal
int main() {
    int tabuleiro[TAB_TAM][TAB_TAM];
    int cone[HAB_TAM][HAB_TAM];
    int cruz[HAB_TAM][HAB_TAM];
    int octaedro[HAB_TAM][HAB_TAM];

    inicializarTabuleiro(tabuleiro);
    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 4, 4);
    aplicarHabilidade(tabuleiro, octaedro, 6, 6);

    printf("Tabuleiro final com habilidades:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
