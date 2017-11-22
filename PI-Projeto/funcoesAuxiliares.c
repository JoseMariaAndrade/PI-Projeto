#include <stdio.h>

#include "funcoesAuxiliares.h"

int lerInteiro(char mensagem[MAX_CHARS])
{
    int numero, controlo;

    do
    {
        printf("%s", mensagem);
        controlo = scanf("%d",&numero);

        limparBufferStdin();
    }
    while (controlo==0);
    return numero;
}

void limparBufferStdin()
{
    char lixo;

    do
    {
        lixo = getchar();
    }
    while(lixo != '\n' && lixo != EOF);
}
