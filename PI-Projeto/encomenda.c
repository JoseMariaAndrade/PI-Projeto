#include <stdio.h>

#include "encomenda.h"
#include "estruturas.h"
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
                encomenda[i].estado = lerEstado('E');
            }
        }
    }
}
