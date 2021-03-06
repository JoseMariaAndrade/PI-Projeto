#include <stdio.h>
#include <string.h>
#include <time.h>


#include "encomenda.h"
#include "funcoesAuxiliares.h"

void adicionarEncomendas(tipoEncomenda encomenda[], int *nEncomendas)
{
    int restanteEncomendas, numero, i;
    restanteEncomendas = MAX_ENCOMENDAS - *nEncomendas;

    if (restanteEncomendas==0)
    {
        printf("\nNao pode inserir mais encomendas");
    }
    else
    {
        numero = lerInteiro("\nQuantas encomendas pretende inserir",0,restanteEncomendas);

        if(numero!=0)
        {
            for (i=*nEncomendas; i<numero; i++)
            {
                printf("\nInserir dados da encomenda:");
                encomenda[i].numero = lerInteiro("\nNumero encomenda", MIN_ENCOMENDA, MAX_ENCOMENDA);
                encomenda[i].peso = lerFloat("\nPeso da encomenda:", MIN_CARGA, MAX_CARGA);
                encomenda[i].estado = lerEstado('E');
                encomenda[i].dataRegisto = lerData("\nData de registo: ");
                lerString("Indique o destino:", encomenda[i].destino, DESTINO);
                encomenda[i].dataEntrega.ano=0;
                encomenda[i].dataEntrega.mes=0;
                encomenda[i].dataEntrega.dia=0;
                encomenda[i].dataDevolucao.ano=0;
                encomenda[i].dataDevolucao.mes=0;
                encomenda[i].dataDevolucao.dia=0;
                (*nEncomendas)++;
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
            numeroEncomenda = lerInteiro("Numero de Encomenda:", MIN_ENCOMENDA, MAX_ENCOMENDA);
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
            numeroEncomenda = lerInteiro("Numero de Encomenda:", MIN_ENCOMENDA, MAX_ENCOMENDA);
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
            printf("Nao pode alterar o destino da encomenda %d", numeroEncomenda);
        }

    }
    else
    {
        printf("\nNao existem encomendas");
    }
}


void calculos(tipoEncomenda encomendas[MAX_ENCOMENDAS], int nEncomendasRegistadas, float *mediaPesos, float *perEncomendasEntregues)
{
    int contPositivas, i;
    float somaPesos;
    somaPesos = 0;
    contPositivas = 0;
    if(nEncomendasRegistadas == 0)
    {
        printf("\nNao existem encomendas registadas");
        *mediaPesos = 0.0;
        *perEncomendasEntregues = 0.0;
    }
    else
    {
        for(i=0; i<nEncomendasRegistadas; i++)
        {
            somaPesos = somaPesos + encomendas[i].peso;
            if(encomendas[i].estado == 2)
            {
                contPositivas++;
            }
        }
        *mediaPesos = (float) somaPesos / nEncomendasRegistadas;
        *perEncomendasEntregues = contPositivas * 100.0 / nEncomendasRegistadas;
    }

}

void mostrarEncomendas(tipoEncomenda encomendas[MAX_ENCOMENDAS], int nEncomendasRegistadas)
{
    int i;
    if(nEncomendasRegistadas > 0)
    {
        printf("\n------------- Encomendas -------------");
        printf("\n Numero de Registo \t Data de registo \tPeso(Kg) \tDestino \t Estado \t Data de Entrega(Ou devolucao) \t Conjunto de observacoes");
        for(i=0; i<nEncomendasRegistadas; i++)
        {
<<<<<<< HEAD
            printf("\n%d \t\t\t %2d/%2d/%4d \t\t%.1f  \t\t%s \t", encomendas[i].numero, encomendas[i].dataRegisto.dia, encomendas[i].dataRegisto.mes, encomendas[i].dataRegisto.ano, encomendas[i].peso, encomendas[i].destino);
=======
            printf("\n%d \t %2d/%2d/%4d \t %.2f \t %s \t", encomendas[i].numero, encomendas[i].dataRegisto.dia, encomendas[i].dataRegisto.mes, encomendas[i].dataRegisto.ano, encomendas[i].peso, encomendas[i].destino);
>>>>>>> b6a9adec1906296dae923179942e06c4249d33d5
            switch(encomendas[i].estado)
            {
            case 0:
                printf("\t Registada");
                break;
            case 1:
                printf("\t Carregada");
                break;
            case 2:
                printf("\t Entregue");
                break;
            case 3:
                printf("\t Devolvida");
                break;
            }
            printf("\t %d/%d/%d \t %s", encomendas[i].dataEntrega.dia, encomendas[i].dataEntrega.mes, encomendas[i].dataEntrega.ano, encomendas[i].observacoes);
        }
    }
    else
    {
        printf("\n Nao exitem encomendas registadas");
    }
}

void consultaEncomendas(tipoEncomenda encomendas[], int nEncomendas)
{
    int contador=-1, index[MAX_ENCOMENDAS], i, estado, numero;
    char destino[DESTINO], tipoPesquisa;

    if(nEncomendas!=0)
    {
        switch(tipoPesquisa)
        {
        case 'N':
            numero = lerInteiro("Indique o numero da encomeda:", MIN_ENCOMENDA, MAX_ENCOMENDA);

            for(i=0; i<nEncomendas; i++)
            {
                if(encomendas[i].numero==numero)
                {
                    contador++;
                    index[contador]=i;
                }
            }

            if(contador!=-1)
            {
                printf("\n------------- Encomendas -------------");
                printf("\n Numero de Registo \t Data de registo \t Peso(Kg) \t Destino \t Estado \t Data de Entrega(Ou devolu�ao) \t Conjunto de Obreva�oes");


                for(i=0; i<contador; i++)
                {
                    for(i=0; i<contador; i++)
                    {
                        printf("\n%d \t %2d/%2d/%4d \t %.2f \t %s \t", encomendas[index[i]].numero, encomendas[index[i]].dataRegisto.dia, encomendas[index[i]].dataRegisto.mes, encomendas[index[i]].dataRegisto.ano, encomendas[index[i]].peso, encomendas[index[i]].destino);
                        switch(encomendas[index[i]].estado)
                        {
                        case 0:
                            printf("Registada");
                            break;
                        case 1:
                            printf("Carregada");
                            break;
                        case 2:
                            printf("Entregue");
                            break;
                        case 3:
                            printf("Devolvida");
                            break;
                        }
                        printf("\t %d/%d/%d \t %s", encomendas[index[i]].dataEntrega.dia, encomendas[index[i]].dataEntrega.mes, encomendas[index[i]].dataEntrega.ano, encomendas[index[i]].observacoes);
                    }
                }
            }
            else
            {
                printf("\nNao existem encomendas com o numero %d", numero);
            }


            break;
        case 'E':
            estado = lerEstado('E');

            for(i=0; i<nEncomendas; i++)
            {
                if(encomendas[i].estado==estado)
                {
                    contador++;
                    index[contador]=i;
                }
            }

            if(contador!=-1)
            {
                printf("\n------------- Encomendas -------------");
                printf("\n Numero de Registo \t Data de registo \t Peso(Kg) \t Destino \t Estado \t Data de Entrega(Ou devolu�ao) \t Conjunto de Obreva�oes");


                for(i=0; i<contador; i++)
                {
                    for(i=0; i<contador; i++)
                    {
                        printf("\n%d \t %2d/%2d/%4d \t %.2f \t %s \t", encomendas[i].numero, encomendas[i].dataRegisto.dia, encomendas[i].dataRegisto.mes, encomendas[i].dataRegisto.ano, encomendas[i].peso, encomendas[i].destino);
                        switch(encomendas[i].estado)
                        {
                        case 0:
                            printf("Registada");
                            break;
                        case 1:
                            printf("Carregada");
                            break;
                        case 2:
                            printf("Entregue");
                            break;
                        case 3:
                            printf("Devolvida");
                            break;
                        }
                        printf("\t %d/%d/%d \t %s", encomendas[i].dataEntrega.dia, encomendas[i].dataEntrega.mes, encomendas[i].dataEntrega.ano, encomendas[i].observacoes);
                    }
                }
            }
            else
            {
                printf("\nNao existem encomendas com estado ");
                switch(estado)
                {
                case 0:
                    printf(" Registada ");
                    break;
                case 1:
                    printf(" Carregada ");
                    break;
                case 2:
                    printf(" Entregue ");
                    break;
                case 3:
                    printf(" Devolvida ");
                    break;
                }
            }

            break;
        case 'D':

            lerString("Insira um destino:", destino, DESTINO);

            for(i=0; i<nEncomendas; i++)
            {
                if(strcmp(encomendas[i].destino, destino)==0)
                {
                    contador++;
                    index[contador]=i;
                }
            }

            if(contador!=-1)
            {
                printf("\n------------- Encomendas -------------");
                printf("\n Numero de Registo \t Data de registo \t Peso(Kg) \t Destino \t Estado \t Data de Entrega(Ou devolucao) \t Conjunto de Obrevacoes");


                for(i=0; i<contador; i++)
                {
                    printf("\n------------- Encomendas -------------");
                    printf("\n Numero de Registo \t Data de registo \t Peso(Kg) \t Destino \t Estado(0 - Registada,1 - Carregada,2 - Entregue,3 - Devolvida) \t Data de Entrega(Ou devolu�ao) \t Conjunto de Obreva�oes");
                    for(i=0; i<contador; i++)
                    {
                        printf("\n%d \t %2d/%2d/%4d \t %.2f \t %s \t", encomendas[i].numero, encomendas[i].dataRegisto.dia, encomendas[i].dataRegisto.mes, encomendas[i].dataRegisto.ano, encomendas[i].peso, encomendas[i].destino);
                        switch(encomendas[i].estado)
                        {
                        case 0:
                            printf("Registada");
                            break;
                        case 1:
                            printf("Carregada");
                            break;
                        case 2:
                            printf("Entregue");
                            break;
                        case 3:
                            printf("Devolvida");
                            break;
                        }
                        printf("\t %d/%d/%d \t %s", encomendas[i].dataEntrega.dia, encomendas[i].dataEntrega.mes, encomendas[i].dataEntrega.ano, encomendas[i].observacoes);
                    }
                }
            }
            else
            {
                printf("\nNao existem encomendas com o destino indicado.");
            }

            break;
        }
    }
    else
    {
        printf("\nNao existem encomendas.");
    }
}

int contagemEncomendasEstado(tipoEncomenda encomendas[], int nEncomendas, int estado)
{
    int contadorEncomendas=0, i;

    for(i=0; i<nEncomendas; i++)
    {
        if(encomendas[i].estado == estado)
        {
            contadorEncomendas++;
        }
    }

    return contadorEncomendas;
}

int contagemEncomendasEstadoMatricula(tipoEncomenda encomendas[], int nEncomendas, int estado, char matricula[MATRICULA])
{
    int contadorEncomendas=0, i;

    for(i=0; i<nEncomendas; i++)
    {
        if(encomendas[i].estado == estado && strcmp(encomendas[i].matricula,matricula)==0)
        {
            contadorEncomendas++;
        }
    }

    return contadorEncomendas;
}

void mostrarQuantidadeEncomendasData(tipoEncomenda encomendas[], int nEncomendas)
{
    int i, invariavel;
    tipoData data = lerData("\n Data: ");
    for(i=0; i<nEncomendas; i++)
    {
        if(data.dia == encomendas[i].dataEntrega.dia && data.mes == encomendas[i].dataEntrega.mes && data.ano == encomendas[i].dataEntrega.ano)
        {
            invariavel++;
        }
    }
    printf("\n Na data %d/%d/%d houve %d encomendas entregues", encomendas[i].dataEntrega.dia, encomendas[i].dataEntrega.mes, encomendas[i].dataEntrega.ano, invariavel);
}

void maiorDestino(tipoEncomenda encomendas[], int nEncomendas)
{
    int maxDestino = 0, i, j, contDestinos = 0, cont;
    char destinos[100][DESTINO];
    for(i = 0; i<nEncomendas; i++)
    {
        cont = 0;
        for(j = 0; j<nEncomendas; j++)
        {
            if(strcmp(encomendas[i].destino, encomendas[j].destino) == 0)
            {
                cont++;
            }
        }
        if(cont > maxDestino)
        {
            maxDestino = cont;
        }
    }
    for(i = 0; i<nEncomendas; i++)
    {
        cont = 0;
        for(j = 0; j<nEncomendas; j++)
        {
            if(strcmp(encomendas[i].destino, encomendas[j].destino) == 0)
            {
                cont++;
            }
        }
        if(cont == maxDestino)
        {
            int existeDestino = 1;
            for(j=0; j<contDestinos; j++)
            {
                if(strcmp(encomendas[i].destino, encomendas[j].destino) == 0)
                {
                    existeDestino = 0;
                    break;
                }
            }
            if(existeDestino)
            {
                strcpy(destinos[contDestinos], encomendas[i].destino);
            }
        }
    }
    printf("\nO(s) destino(s) com maior encomendas entregues e: ");
    for(j=0; j<contDestinos; j++)
    {
        printf("\n %s", destinos[j]);
    }
}
