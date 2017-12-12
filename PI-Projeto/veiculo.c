#include <stdio.h>
#include <string.h>

#include "veiculo.h"
#include "estruturas.h"
#include "funcoesAuxiliares.h"
#include "encomenda.h"

void adicionarVeiculos(tipoVeiculo veiculo[], int *nVeiculos)
{
    //tipoVeiculo veiculo;
    int restanteVeiculos, numero, i;
    restanteVeiculos = MAX_VEICULOS - *nVeiculos;

    if (restanteVeiculos==0)
    {
        printf("\nNao pode inserir mais veiculos");
    }
    else
    {
        numero = lerInteiro("\nQuantos veiculos pretende inserir",0,restanteVeiculos);

        if(numero!=0)
        {
            for (i=*nVeiculos; i<numero; i++)
            {
                printf("\nInserir dados do veiculo:");
                veiculo[i].carga=lerInteiro("\nCarga",10, 10000);
                veiculo[i].viagens=0;
                veiculo[i].encomendas=0;
                veiculo[i].dataFabrico=lerData("\nInserir Data de Fabrico do veiculo:");
                //do
                //{
                lerString("\nInserir Matricula do veiculo:", veiculo[i].matricula, MATRICULA);
                //posicao=procurarVeiculo(veiculo,&nVeiculos, veiculo[i].matricula);
                //}
                //while(posicao!=-1);
                veiculo[i].estado = lerEstado('V');
                (*nVeiculos)++;
            }
        }
        else
        {
            printf("\nOperacao Cancelada.");
        }
    }
}

void mostrarVeiculos(tipoVeiculo veiculo[], int nVeiculos)
{
    int i;

    if(nVeiculos>0)
    {
        printf("\nVeiculos:");
        printf("\nMatricula \t Estado \t Carga \t Viagens \t Encomendas \t Data Fabrico");

        for(i=0; i<nVeiculos; i++)
        {
            printf("\n%s ", veiculo[i].matricula);
            switch(veiculo[i].estado)
            {
            case 0:
                printf("\t\t Disponivel ");
                break;
            case 1:
                printf("\t\t A Transportar ");
                break;
            case 2:
                printf("\t\t Regresso ");
                break;
            case 3:
                printf("\t\t Avariado ");
                break;
            }
            printf("\t %d \t %d \t\t %d \t\t %2d-%2d-%4d", veiculo[i].carga, veiculo[i].viagens, veiculo[i].encomendas, veiculo[i].dataFabrico.dia, veiculo[i].dataFabrico.mes, veiculo[i].dataFabrico.ano);
        }
    }
    else
    {
        printf("\nNao existem veiculos.");
    }
}

int procurarVeiculo(tipoVeiculo veiculos[], int nVeiculos, char matricula[])
{
    int posicao=-1, i;
    char s[MATRICULA];
    if(nVeiculos==0)
    {
        printf("\nNao existem veiculos.");
    }
    else
    {
        for(i=0; i<nVeiculos; i++)
        {
            strcpy(s,veiculos[i].matricula);
            if(strcmp(s,matricula)==0)
            {
                posicao=i;
                i=nVeiculos;
            }
        }
    }
    return posicao;
}

void mostarVeiculoEncomenda (tipoVeiculo veiculos[], tipoEncomenda encomendas[], int nVeiculos, int nEncomendas)
{

    int posicao, numeroEncomenda;
    char matricula[MATRICULA];

    if(nVeiculos!=0 || nEncomendas!=0)
    {
        do
        {
            numeroEncomenda = lerInteiro("Numero de Encomenda:",0,100);
            posicao = procurarEncomendas(encomendas, nEncomendas, numeroEncomenda);

            if(posicao==-1)
            {
                printf("\nO numero da encomenda %d nao existe", numeroEncomenda);
            }
        }
        while (posicao==-1);

        strcpy(matricula, encomendas[posicao].matricula);

        posicao = procurarVeiculo(veiculos, nVeiculos, matricula);

        printf("\nVeiculo %s:", veiculos[posicao].matricula);
        printf("\nMatricula \t Estado \t Carga \t Viagens \t Encomendas \t Data Fabrico");

        printf("\n%s ", veiculos[posicao].matricula);

        switch(veiculos[posicao].estado)
        {
        case 0:
            printf("\t\t Disponivel ");
            break;
        case 1:
            printf("\t\t A Transportar ");
            break;
        case 2:
            printf("\t\t Regresso ");
            break;
        case 3:
            printf("\t\t Avariado ");
            break;
        }

        printf("\t %d \t %d \t\t %d \t\t %2d-%2d-%4d", veiculos[posicao].carga, veiculos[posicao].viagens, veiculos[posicao].encomendas, veiculos[posicao].dataFabrico.dia, veiculos[posicao].dataFabrico.mes, veiculos[posicao].dataFabrico.ano);


    }
    else
    {
        printf("\nNao existem Veiculos ou Encomendas");
    }
}
