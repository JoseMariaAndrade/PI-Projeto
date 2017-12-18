#include <stdio.h>
#include <string.h>

#include "veiculo.h"
#include "estruturas.h"
#include "funcoesAuxiliares.h"
#include "encomenda.h"

void adicionarVeiculos(tipoVeiculo veiculo[], int *nVeiculos)
{
    int restanteVeiculos, numero, i;
    restanteVeiculos = MAX_VEICULOS - *nVeiculos;
    char str[MATRICULA] = {'\0'} ;

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
                strcpy(veiculo[i].matricula,lerMatricula("Matricula:", str));
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
            printf("\n%s", veiculo[i].matricula);

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

void consultaVeiculos(tipoVeiculo veiculos[], int nVeiculos, char tipoPesquisa)
{
    int carga, contador=-1, index[MAX_VEICULOS], i, maximo, estado;

    if(nVeiculos!=0)
    {
        switch (tipoPesquisa)
        {
        case 'C':
            maximo = maximoCarga(veiculos, nVeiculos);
            carga = lerInteiro("",0,maximo);

            for(i=0; i<nVeiculos; i++)
            {
                if(veiculos[i].carga==carga)
                {
                    contador++;
                    index[contador]=i;
                }
            }

            if(contador!=-1)
            {
                printf("\nVeiculos:");
                printf("\nMatricula \t Estado \t Carga \t Viagens \t Encomendas \t Data Fabrico");

                for(i=0; i<=contador; i++)
                {
                    printf("\n%s ", veiculos[index[i]].matricula);

                    switch(veiculos[index[i]].estado)
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

                    printf("\t %d \t %d \t\t %d \t\t %2d-%2d-%4d", veiculos[index[i]].carga, veiculos[index[i]].viagens, veiculos[index[i]].encomendas, veiculos[index[i]].dataFabrico.dia, veiculos[index[i]].dataFabrico.mes, veiculos[index[i]].dataFabrico.ano);
                }
            }
            else
            {
                printf("\nNao existem veiculos com carga %d", carga);
            }

            break;
        case 'E':

            estado = lerEstado('V');

            for(i=0; i<nVeiculos; i++)
            {
                if(veiculos[i].estado==estado)
                {
                    contador++;
                    index[contador]=i;
                }
            }

            if(contador!=-1)
            {
                printf("\nVeiculos:");
                printf("\nMatricula \t Estado \t Carga \t Viagens \t Encomendas \t Data Fabrico");

                for(i=0; i<=contador; i++)
                {
                    printf("\n%s ", veiculos[index[i]].matricula);

                    switch(veiculos[index[i]].estado)
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

                    printf("\t %d \t %d \t\t %d \t\t %2d-%2d-%4d", veiculos[index[i]].carga, veiculos[index[i]].viagens, veiculos[index[i]].encomendas, veiculos[index[i]].dataFabrico.dia, veiculos[index[i]].dataFabrico.mes, veiculos[index[i]].dataFabrico.ano);
                }
            }
            else
            {
                printf("\nNao existem veiculos com estado ");
                switch(estado)
                {
                case 0:
                    printf(" Disponivel ");
                    break;
                case 1:
                    printf(" A Transportar ");
                    break;
                case 2:
                    printf(" Regresso ");
                    break;
                case 3:
                    printf(" Avariado ");
                    break;
                }

            }
            break;
        case 'M':
            estado = lerEstado('V');

            for(i=0; i<nVeiculos; i++)
            {
                if(veiculos[i].estado==estado)
                {
                    contador++;
                    index[contador]=i;
                }
            }

            if(contador!=-1)
            {
                printf("\nVeiculos:");
                printf("\nMatricula \t Estado \t Carga \t Viagens \t Encomendas \t Data Fabrico");

                for(i=0; i<=contador; i++)
                {
                    printf("\n%s ", veiculos[index[i]].matricula);

                    switch(veiculos[index[i]].estado)
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

                    printf("\t %d \t %d \t\t %d \t\t %2d-%2d-%4d", veiculos[index[i]].carga, veiculos[index[i]].viagens, veiculos[index[i]].encomendas, veiculos[index[i]].dataFabrico.dia, veiculos[index[i]].dataFabrico.mes, veiculos[index[i]].dataFabrico.ano);
                }
            }
            else
            {
                printf("\nNao existem veiculos com estado ");
                switch(estado)
                {
                case 0:
                    printf(" Disponivel ");
                    break;
                case 1:
                    printf(" A Transportar ");
                    break;
                case 2:
                    printf(" Regresso ");
                    break;
                case 3:
                    printf(" Avariado ");
                    break;
                }

            }
            break;
        };
    }
    else
    {
        printf("\nNao existem veiculos.");
    }

}

int maximoCarga(tipoVeiculo veiculos[], int nVeiculos)
{
    int maximo=0, i;

    for(i=0; i<nVeiculos; i++)
    {
        if(veiculos[i].carga>maximo)
        {
            maximo=veiculos[i].carga;
        }
    }
    return maximo;
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

void ordenarVeiculosEncomendasDecrescente(tipoVeiculo veiculos[], int nVeiculos)
{
    int i, j, hatrocas;
    tipoVeiculo aux;
    hatrocas=1;

    for(i=0; i<nVeiculos-1 && hatrocas!=0; i++)
    {
        hatrocas=0;
        for(j=0; j<nVeiculos-i-1; j++)
        {
            if(veiculos[j+1].encomendas > veiculos[j].encomendas)
            {
                hatrocas=1;
                aux=veiculos[j];
                veiculos[j]=veiculos[j+1];
                veiculos[j+1]=aux;
            }
        }
    }
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
