#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcoesAuxiliares.h"

int lerInteiro(char mensagem[MAX_CHARS], int numeroMinimo, int numeroMaximo)
{
    int numero, controlo;
    if(numeroMinimo==numeroMaximo)
    {
        printf("\n");
    }
    else
    {
        do
        {
            printf("%s (%d - %d):", mensagem, numeroMinimo, numeroMaximo);
            controlo = scanf("%d",&numero);

            limparBufferStdin();

            if (numero<numeroMinimo || numero>numeroMaximo || controlo == 0)
            {
                printf("\nNumero invalido.");
            }
        }
        while (numero<numeroMinimo || numero>numeroMaximo || controlo==0);
    }

    return numero;
}

void lerString(char mensagem[MAX_CHARS], char vetorChars[50], int maximoCaracteres)
{
    int tamanho;
    do
    {
        printf("%s", mensagem); //puts(mensagem)
        fgets(vetorChars, maximoCaracteres, stdin);

        tamanho = strlen(vetorChars);

        if (tamanho == 1)
        {
            printf("\n String Vazia.");
        }
        else
        {
            if(vetorChars[tamanho-1] == '\n')
            {
                vetorChars[tamanho-1] = '\0';
            }
            else
            {
                limparBufferStdin();
            }
        }
    }
    while (tamanho == 1);
}

int lerEstado(char tipoEstado)
{
    int opcao;
    tipoEstado=toupper(tipoEstado);

    switch(tipoEstado)
    {
    case 'E':
        printf("Insira o estado da encomenda:");
        printf("\n0 - Registada");
        printf("\n1 - Carregada");
        printf("\n2 - Entregue");
        printf("\n3 - Devolvida");
        opcao = lerInteiro("\nIndique o estado da encomenda:",0,3);
        break;
    case 'V':
        printf("Insira o estado do veiculo:");
        printf("\n0 - Disponivel");
        printf("\n1 - Transportar");
        printf("\n2 - Regresso");
        printf("\n3 - Avariado");
        opcao = lerInteiro("\nIndique o estado do veiculo:",0,3);
        break;
    }

    return opcao;
}

tipoData lerData(char mensagem[MAX_CHARS])
{
    tipoData data;
    int maxDiasMes;
    printf(mensagem);
    data.ano = lerInteiro("\nAno ", ANO_MINIMO, ANO_MAXIMO);
    data.mes = lerInteiro("\nMes ", 1, 12);
    switch(data.mes)
    {
    case 2:
        if((data.ano%400==0) || (data.ano%4==0 && data.ano%100!=0))
        {
            maxDiasMes=29;
        }
        else
        {
            maxDiasMes=28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes=30;
        break;
    default:
        maxDiasMes=31;
    }

    data.dia=lerInteiro("\nDia ", 1, maxDiasMes);

    return data;
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

/** \brief
 *
 * \param tipoVeiculo veiculos[]
 * \param tipoEncomenda encomendas[]
 * \param int nVeiculos
 * \param int nEncomendas
 * \return void
 *
 */

void gravarFicheiroTexto(tipoVeiculo veiculos[MAX_VEICULOS], tipoEncomenda encomendas[MAX_ENCOMENDAS], int nVeiculos, int nEncomendas)
{
    FILE *file;
    int i;
    file = fopen("dados.txt","w");
    if(file == NULL)
    {
        printf("\nErro ao abrir o ficheiro.");
    }
    else
    {
        for(i=0; i<nVeiculos; i++)
        {
            fprintf(file,"%s",veiculos[i].matricula);
            fprintf(file,"%d-%d-%d",veiculos[i].dataFabrico.dia,veiculos[i].dataFabrico.mes,veiculos[i].dataFabrico.ano);
            fprintf(file,"%d",veiculos[i].carga);
            fprintf(file,"%d",veiculos[i].viagens);
            fprintf(file,"%d",veiculos[i].encomendas);
        }
    }
}
