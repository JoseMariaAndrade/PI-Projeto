#include <stdio.h>

#include "encomenda.h"
#include "funcoesAuxiliares.h"

void adicionarEncomendas(tipoEncomenda encomenda[], int nEncomendas)
{
    int restanteEncomendas, numero, i;
    restanteEncomendas = MAX_ENCOMENDAS - nEncomendas;

    if (restanteEncomendas==0)
    {
        printf("\nNao pode inserir mais encomendas");
    }
    else
    {
        numero = lerInteiro("\nQuantas encomendas pretende inserir",0,restanteEncomendas);

        if(numero!=0)
        {
            for (i=nEncomendas; i<numero; i++)
            {
                printf("\n Inserir dados da encomenda:");
                encomenda[i].numero = lerInteiro("Numero encomenda:",0,0);
                encomenda[i].estado = lerEstado('E');
            }
        }
    }
}

int procurarEncomendas(tipoEncomenda encomendas[], int nEncomendas, int numeroEncomenda)
{
    int posicao=-1,i;

    if(nEncomendas==0)
    {
        printf("\nNao existem encomendas.");
    }
    else
    {
        for(i=0; i<nEncomendas; i++)
        {
            if(encomendas[i].numero==numeroEncomenda)
            {
                posicao=i;
                i=nEncomendas;
            }
            else
            {

            }
        }
    }
    return posicao;
}

void eliminarEncomeda(tipoEncomenda encomendas[], int nEncomendas, int numeroEncomenda)
{
    int posicao;

    posicao = porcurarEncomendas(encomendas, nEncomendas, numeroEncomenda);

    if(posicao!=1)
    {
        encomendas[posicao]=NULL;
    }
}
