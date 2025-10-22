#include <stdio.h>

#define TAM_TABULEIRO 10 // Tamanho do tabuleiro (10x10)
#define TAM_HABILIDADE 5 // Tamanho matrizes de habilidades (5x5)

int main()
{
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE]; // Matrizes principais
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    int i, j; // contadores de loop

    // Inicializar tabuleiro com água (valor 0)
    // Zerar matriz
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }

    // Posição central de uma matriz 5x5 (linha/coluna do meio)
    int meio = TAM_HABILIDADE / 2;

    // matriz da habilidade Cone
    for (i = 0; i < TAM_HABILIDADE; i++)
    {
        for (j = 0; j < TAM_HABILIDADE; j++)
        {
            cone[i][j] = 0;
        }
    }

    // Preencher o cone: forma de pirâmide
    for (i = 0; i < 3; i++)
    { // só nas 3 primeiras linhas
        for (j = 0; j < TAM_HABILIDADE; j++)
        {
            if (j >= meio - i && j <= meio + i)
            {
                cone[i][j] = 1; // define área de efeito da habilidade
            }
        }
    }

    // Criar matriz da habilidade Cruz
    for (i = 0; i < TAM_HABILIDADE; i++)
    {
        for (j = 0; j < TAM_HABILIDADE; j++)
        {
            // Coloca 1 nas linhas e colunas centrais (formando cruz)
            if (i == meio || j == meio)
            {
                cruz[i][j] = 1;
            }
            else
            {
                cruz[i][j] = 0;
            }
        }
    }

    // Criar matriz da habilidade Octaedro (losango)
    // Zerar matriz
    for (i = 0; i < TAM_HABILIDADE; i++)
    {
        for (j = 0; j < TAM_HABILIDADE; j++)
        {
            octaedro[i][j] = 0;
        }
    }

    // Preencher o losango com 1's, simulando vista frontal de um octaedro
    for (i = 0; i < TAM_HABILIDADE; i++)
    {
        int start, end;
        if (i <= meio)
        {
            start = meio - i;
            end = meio + i;
        }
        else
        {
            start = i - meio;
            end = TAM_HABILIDADE - 1 - (i - meio);
        }

        for (j = start; j <= end; j++)
        {
            octaedro[i][j] = 1; // marca área de efeito
        }
    }

    // Aplicar HABILIDADE CONE no tabuleiro
    int offset = TAM_HABILIDADE / 2; // usado para centralizar a matriz

    // Define posição central da habilidade Cone no tabuleiro
    int origemLinha = 7;
    int origemColuna = 2;

    // Sobrepor a matriz "cone" no tabuleiro
    for (i = 0; i < TAM_HABILIDADE; i++)
    {
        for (j = 0; j < TAM_HABILIDADE; j++)
        {
            // Calcular posição real no tabuleiro
            int li = origemLinha - offset + i;
            int co = origemColuna - offset + j;

            // Verifica se está dentro do tabuleiro
            if (li >= 0 && li < TAM_TABULEIRO && co >= 0 && co < TAM_TABULEIRO)
            {
                if (cone[i][j] == 1)
                {
                    tabuleiro[li][co] = 5; // 5 representa habilidade
                }
            }
        }
    }

    // Aplicar HABILIDADE CRUZ no tabuleiro
    origemLinha = 2;
    origemColuna = 3;

    for (i = 0; i < TAM_HABILIDADE; i++)
    {
        for (j = 0; j < TAM_HABILIDADE; j++)
        {
            int li = origemLinha - offset + i;
            int co = origemColuna - offset + j;

            if (li >= 0 && li < TAM_TABULEIRO && co >= 0 && co < TAM_TABULEIRO)
            {
                if (cruz[i][j] == 1)
                {
                    tabuleiro[li][co] = 5;
                }
            }
        }
    }

    // Aplicar HABILIDADE OCTAEDRO no tabuleiro
    origemLinha = 5;
    origemColuna = 7;

    for (i = 0; i < TAM_HABILIDADE; i++)
    {
        for (j = 0; j < TAM_HABILIDADE; j++)
        {
            int li = origemLinha - offset + i;
            int co = origemColuna - offset + j;

            if (li >= 0 && li < TAM_TABULEIRO && co >= 0 && co < TAM_TABULEIRO)
            {

                if (octaedro[i][j] == 1)

                {
                    tabuleiro[li][co] = 5;
                }
            }
        }
    }

    printf("## Tabuleiro Batalha Naval ##\n");

    // Imprimir cabeçalho de colunas (letras A a J)
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAM_TABULEIRO; letra++)
    {
        printf("%c ", letra);
    }
    printf("\n");

    // Imprimir cada linha com o número e os elementos
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("%2d ", i); // número da linha à esquerda
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            if (tabuleiro[i][j] == 5)
            {
                printf("X "); // X = área de habilidade
            }
            else
            {
                printf("0 "); // 0 = água
            }
        }
        printf("\n");
    }

    return 0;
}