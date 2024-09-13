
//Kaua Cordeiro Cavalheiro
//jogo da velha atualizado

#include <stdio.h>
#include <stdlib.h>

#define DIM 3
#define ESPACO ' '

void limpaTela()
{
    system("@cls||clear");
}

void inic(char s [ ][DIM])
{
    int i, j;
    for(i=0; i<DIM; i++)
        for(j=0; j<DIM; j++)
            s[i][j]=ESPACO;
}

void mostra(char s[DIM][DIM])
{
    int i, j;
    for(i=0; i<DIM; i++)
    {
        for(j=0; j<DIM; j++)
            printf("%c %c", s[i][j], j==DIM-1?' ':'|');
        if(i!=DIM-1)
            printf("\n--------");
        putchar('\n');
    }
}

int verificarVitoria(char s[][DIM], char jogador) {
    int i, j;
    // Verificando linhas
    for (i = 0; i < DIM; i++) {
        if (s[i][0] == jogador && s[i][1] == jogador && s[i][2] == jogador)
            return 1;
    }
    // Verificando colunas
    for (j = 0; j < DIM; j++) {
        if (s[0][j] == jogador && s[1][j] == jogador && s[2][j] == jogador)
            return 1;
    }
    // Verificando diagonais
    if ((s[0][0] == jogador && s[1][1] == jogador && s[2][2] == jogador) ||
        (s[0][2] == jogador && s[1][1] == jogador && s[2][0] == jogador))
        return 1;
    
    return 0;
}

main()
{
    char Velha[DIM][DIM];
    int posX, posY;
    char ch = 'X';
    int n_jogadas = 0;
    inic(Velha);

    while(1)
    {
        limpaTela();
        mostra(Velha);
        printf("\nIntroduza a Posicao de jogo Linha Coluna: ");
        scanf("%d %d", &posX, &posY);
        posX--; posY--;

        if (posX >= 0 && posX < DIM && posY >= 0 && posY < DIM) 
        {
            if (Velha[posX][posY] == ESPACO) 
            {
                Velha[posX][posY] = ch;
                n_jogadas++;
    
                if (verificarVitoria(Velha, ch)) 
                    {  
                    limpaTela();
                    mostra(Velha);
                    printf("\nO jogador %c venceu!\n", ch);
                    break;
                    } 
                else if (n_jogadas == DIM * DIM) 
                    {
                    limpaTela();
                    mostra(Velha);
                    printf("\nO jogo terminou em empate!\n");
                    break;
                    }    
                else 
                    {
                    ch = (ch == '0') ? 'X' : '0';
                    }
            }   
            
            else 
                {
                printf("\nPosicao ja ocupada! Jogue novamente!\n");
                }
        } 
        
        else 
            {
            printf("\nPosicao invalida! Jogue novamente!\n");
            }
    }
    
    return 0;
}
