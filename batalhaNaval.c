#include <stdio.h>

#define TAMANHO 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para aplicar habilidade Cruz
void aplicarCruz(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    tabuleiro[x][y] = 1;
    if (x > 0) tabuleiro[x - 1][y] = 1;
    if (x < TAMANHO - 1) tabuleiro[x + 1][y] = 1;
    if (y > 0) tabuleiro[x][y - 1] = 1;
    if (y < TAMANHO - 1) tabuleiro[x][y + 1] = 1;
}

// Função para aplicar habilidade Octaedro
void aplicarOctaedro(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    tabuleiro[x][y] = 1;
    if (x > 0) tabuleiro[x - 1][y] = 1;
    if (x < TAMANHO - 1) tabuleiro[x + 1][y] = 1;
    if (y > 0) tabuleiro[x][y - 1] = 1;
    if (y < TAMANHO - 1) tabuleiro[x][y + 1] = 1;
    if (x > 1) tabuleiro[x - 2][y] = 1;
    if (x < TAMANHO - 2) tabuleiro[x + 2][y] = 1;
    if (y > 1) tabuleiro[x][y - 2] = 1;
    if (y < TAMANHO - 2) tabuleiro[x][y + 2] = 1;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa tabuleiro com 0

    // Posicionamento de navios
    tabuleiro[2][2] = 3; // Navio vertical
    tabuleiro[3][2] = 3;
    tabuleiro[4][2] = 3;
    
    tabuleiro[6][4] = 3; // Navio horizontal
    tabuleiro[6][5] = 3;
    tabuleiro[6][6] = 3;
    
    tabuleiro[1][1] = 3; // Navio diagonal
    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;
    
    tabuleiro[7][3] = 3; // Outro navio diagonal
    tabuleiro[8][4] = 3;
    tabuleiro[9][5] = 3;

    printf("Tabuleiro com navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    // Aplicação da habilidade Cone (posicionada na linha 5, coluna 5)
    int x = 5, y = 5;
    tabuleiro[x][y] = 1;
    tabuleiro[x - 1][y] = 1;
    tabuleiro[x - 1][y - 1] = 1;
    tabuleiro[x - 1][y + 1] = 1;
    tabuleiro[x - 2][y] = 1;
    
    printf("Tabuleiro com habilidade Cone aplicada:\n");
    exibirTabuleiro(tabuleiro);
    
    // Aplicação da habilidade Cruz (posicionada na linha 3, coluna 3)
    aplicarCruz(tabuleiro, 3, 3);
    printf("Tabuleiro com habilidade Cruz aplicada:\n");
    exibirTabuleiro(tabuleiro);
    
    // Aplicação da habilidade Octaedro (posicionada na linha 7, coluna 7)
    aplicarOctaedro(tabuleiro, 7, 7);
    printf("Tabuleiro com habilidade Octaedro aplicada:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
