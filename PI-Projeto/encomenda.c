#include <stdio.h>
#include <string.h>

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
                encomenda[i].numero = lerInteiro("\nNumero encomenda",0,0);
                encomenda[i].peso = lerFloat("\nPeso da encomenda:",0,1000);
                encomenda[i].estado = lerEstado('E');
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

void calculos(tipoEncomenda encomendas[MAX_ENCOMENDAS], int nEncomendasRegistadas, float *mediaPesos, float * perEncomendasEntregues)
{
    int somaPesos, contPositivas, i;
    somaPesos = 0;
    contPositivas = 0;
    if(nEncomendasRegistadas == 0)
    {
        printf("\n Nao existem encomendas registadas");
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
        printf("\n Numero de Registo \t Data de registo \t Peso(Kg) \t Destino \t Estado \t Data de Entrega(Ou devolucao) \t Conjunto de Obrevacoes");
        for(i=0; i<nEncomendasRegistadas; i++)
        {
            printf("\n%d \t %2d/%2d/%4d \t %f \t %s \t", encomendas[i].numero, encomendas[i].dataRegisto.dia, encomendas[i].dataRegisto.mes, encomendas[i].dataRegisto.ano, encomendas[i].peso, encomendas[i].destino);
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
    else
    {
        printf("\n Nao exitem encomendas registadas");
    }
}

void consultaEncomendas(tipoEncomenda encomendas[], int nEncomendas, char tipoPesquisa)
{
    int contador=-1, index[MAX_ENCOMENDAS], i, estado, numero;
    char destino[DESTINO];

    if(nEncomendas!=0)
    {
        switch(tipoPesquisa)
        {
        case 'N':
            numero = lerInteiro("Indique o numero da encomeda:", 1, 10000);

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
                printf("\n Numero de Registo \t Data de registo \t Peso(Kg) \t Destino \t Estado \t Data de Entrega(Ou devoluçao) \t Conjunto de Obrevaçoes");


                for(i=0; i<contador; i++)
                {
                    for(i=0; i<contador; i++)
                    {
                        printf("\n%d \t %2d/%2d/%4d \t %f \t %s \t", encomendas[index[i]].numero, encomendas[index[i]].dataRegisto.dia, encomendas[index[i]].dataRegisto.mes, encomendas[index[i]].dataRegisto.ano, encomendas[index[i]].peso, encomendas[index[i]].destino);
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
                printf("\n Numero de Registo \t Data de registo \t Peso(Kg) \t Destino \t Estado \t Data de Entrega(Ou devoluçao) \t Conjunto de Obrevaçoes");


                for(i=0; i<contador; i++)
                {
                    for(i=0; i<contador; i++)
                    {
                        printf("\n%d \t %2d/%2d/%4d \t %f \t %s \t", encomendas[i].numero, encomendas[i].dataRegisto.dia, encomendas[i].dataRegisto.mes, encomendas[i].dataRegisto.ano, encomendas[i].peso, encomendas[i].destino);
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
                    printf("\n Numero de Registo \t Data de registo \t Peso(Kg) \t Destino \t Estado(0 - Registada,1 - Carregada,2 - Entregue,3 - Devolvida) \t Data de Entrega(Ou devoluçao) \t Conjunto de Obrevaçoes");
                    for(i=0; i<contador; i++)
                    {
                        printf("\n%d \t %2d/%2d/%4d \t %f \t %s \t", encomendas[i].numero, encomendas[i].dataRegisto.dia, encomendas[i].dataRegisto.mes, encomendas[i].dataRegisto.ano, encomendas[i].peso, encomendas[i].destino);
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
