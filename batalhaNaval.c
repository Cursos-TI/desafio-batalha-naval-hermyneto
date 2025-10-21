#include <stdio.h>

int main(){

    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10] = {0};
    int navio = 3;     // Valor que representa o navio
    int tam_navio = 3; // Tamanho do navio

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 6;
    int coluna_vertical = 3;

    // Posiciona navio horizontal
    for (int i = 0; i < tam_navio; i++)
    {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio;
    }

    // Posiciona navio vertical
    for (int i = 0; i < tam_navio; i++)
    {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio;
    }

    printf("## Tabuleiro Batalha Naval ##\n");
    // Exibe o cabeçalho com letras A-J
    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++)
    {
        printf("%c ", letra);
    }
    printf("\n");

    // Exibe o tabuleiro
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i); // Número da linha
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}