#include <stdio.h>

#include "veiculo.h"
#include "estruturas.h"
#include "funcoesAuxiliares.h"

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
                lerString("\nInserir Matricula do veiculo:", veiculo[i].matricula, MATRICULA);
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
