#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define TAM_NAVIO 3

int main()
{
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal em (7,7) até (7,9)
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[7][7 + i] = NAVIO;
    }

    // Navio vertical em (3,4) até (5,4)
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[3 + i][4] = NAVIO;
    }

    // Navio diagonal principal em (0,0) até (2,2)
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[i][i] = NAVIO;
    }

    // Navio diagonal inversa em (0,9) até (2,7)
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[i][9 - i] = NAVIO;
    }

    printf("## Tabuleiro Batalha Naval ##\n");
    // Exibe o cabeçalho com letras A-J
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO; letra++)
    {
        printf("%c ", letra);
    }
    printf("\n");

    // Exibe o tabuleiro com número da linha
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%2d ", i); // Número da linha
        for (int j = 0; j < TAMANHO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}