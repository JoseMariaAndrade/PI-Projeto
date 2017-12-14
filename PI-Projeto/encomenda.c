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

void eliminarEncomeda(tipoEncomenda encomendas[], int *nEncomendas)
{
    int posicao, numeroEncomenda, i;

    if(*nEncomendas!=0)
    {
        do
        {
            numeroEncomenda = lerInteiro("Numero de Encomenda:",0,100);
            posicao = procurarEncomendas(encomendas, *nEncomendas, numeroEncomenda);

            if(posicao==-1)
            {
                printf("\nO numero da encomenda %d nao existe", numeroEncomenda);
            }
        }
        while(posicao==-1);
    }
    else
    {
        printf("\nNao existem encomendas");
    }

    if(encomendas[posicao].estado==0)
    {
        for(i=posicao; i<*nEncomendas; i++)
        {
            encomendas[i]=encomendas[i+1];
        }
        (*nEncomendas)--;
    }
    else
    {
        printf("Nao pode eliminar a encomenda %d", numeroEncomenda);
    }

}

void alterarDestino(tipoEncomenda encomendas[], int *nEncomendas)
{
    int posicao, numeroEncomenda;

    if(*nEncomendas!=0)
    {
        do
        {
            numeroEncomenda = lerInteiro("Numero de Encomenda:",0,100);
            posicao = procurarEncomendas(encomendas, *nEncomendas, numeroEncomenda);

            if(posicao==-1)
            {
                printf("\nO numero da encomenda %d nao existe", numeroEncomenda);
            }
        }
        while(posicao==-1);

        if(encomendas[posicao].estado==3)
        {
            lerString("Novo Destino:", encomendas[posicao].destino, DESTINO);
        }
        else
        {
            printf("Nao pode eliminar a encomenda %d", numeroEncomenda);
        }

    }
    else
    {
        printf("\nNao existem encomendas");
    }
}

void calculos(tipoEncomenda encomendas[MAX_ENCOMENDAS], int nEncomendasRegistadas, float *mediaPesos, float * perEncomendasEntregues){
    int somaPesos, contPositivas, i;
    somaPesos = 0;
    contPositivas = 0;
    if(nEncomendasRegistadas == 0){
        printf("\n Nao existem encomendas registadas");
        *mediaPesos = 0.0;
        *perEncomendasEntregues = 0.0;
    }else{
        for(i=0; i<nEncomendasRegistadas; i++){
            somaPesos = somaPesos + encomendas[i].peso;
            if(encomendas[i].estado == 2){
                contPositivas++;
            }
        }
        *mediaPesos = (float) somaPesos / nEncomendasRegistadas;
        *perEncomendasEntregues = contPositivas * 100.0 / nEncomendasRegistadas;
    }
}
