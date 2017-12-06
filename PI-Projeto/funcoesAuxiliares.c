#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcoesAuxiliares.h"

int lerInteiro(char mensagem[MAX_CHARS], int numeroMinimo, int numeroMaximo)
{
    int numero, controlo;
    if(numeroMinimo==numeroMaximo)
    {
        do
        {
            printf("%s:", mensagem);
            controlo = scanf("%d",&numero);

            limparBufferStdin();

            if (controlo == 0)
            {
                printf("\nNumero invalido.");
            }
        }
        while (controlo==0);
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

void gravarFicheiroTexto(tipoVeiculo veiculos[], tipoEncomenda encomendas[], int nVeiculos, int nEncomendas)
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
        fprintf(file,"%d\n",nVeiculos);
        fprintf(file,"%d\n",nEncomendas);
        for(i=0; i<nVeiculos; i++)
        {
            fprintf(file,"%s\n",veiculos[i].matricula);
            fprintf(file,"%d-%d-%d\n",veiculos[i].dataFabrico.dia,veiculos[i].dataFabrico.mes,veiculos[i].dataFabrico.ano);
            fprintf(file,"%d\n",veiculos[i].carga);
            fprintf(file,"%d\n",veiculos[i].viagens);
            fprintf(file,"%d\n",veiculos[i].encomendas);
        }

        for(i=0; i<nEncomendas; i++)
        {
            fprintf(file,"%d\n",encomendas[i].numero);
            fprintf(file,"%d\n",encomendas[i].peso);
            fprintf(file,"%d\n",encomendas[i].estado);
            fprintf(file,"%s\n",encomendas[i].destino);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataRegisto.dia,encomendas[i].dataRegisto.mes,encomendas[i].dataRegisto.ano);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataEntrega.dia,encomendas[i].dataEntrega.mes,encomendas[i].dataEntrega.ano);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataDevolucao.dia,encomendas[i].dataEntrega.mes,encomendas[i].dataEntrega.ano);
            fprintf(file,"%s\n",encomendas[i].observacoes);
        }
    }
    fclose(file);
}

void gravarFicheiroBinario(tipoVeiculo veiculos[], tipoEncomenda encomendas[], int nVeiculos, int nEncomendas)
{
    FILE *file;
    int i;
    file = fopen("dados.dat","wb");
    if(file == NULL)
    {
        printf("\nErro ao abrir o ficheiro.");
    }
    else
    {
        fprintf(file,"%d\n",nVeiculos);
        fprintf(file,"%d\n",nEncomendas);
        for(i=0; i<nVeiculos; i++)
        {
            fprintf(file,"%s\n",veiculos[i].matricula);
            fprintf(file,"%d-%d-%d\n",veiculos[i].dataFabrico.dia,veiculos[i].dataFabrico.mes,veiculos[i].dataFabrico.ano);
            fprintf(file,"%d\n",veiculos[i].carga);
            fprintf(file,"%d\n",veiculos[i].viagens);
            fprintf(file,"%d\n",veiculos[i].encomendas);
        }

        for(i=0; i<nEncomendas; i++)
        {
            fprintf(file,"%d\n",encomendas[i].numero);
            fprintf(file,"%d\n",encomendas[i].peso);
            fprintf(file,"%d\n",encomendas[i].estado);
            fprintf(file,"%s\n",encomendas[i].destino);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataRegisto.dia,encomendas[i].dataRegisto.mes,encomendas[i].dataRegisto.ano);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataEntrega.dia,encomendas[i].dataEntrega.mes,encomendas[i].dataEntrega.ano);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataDevolucao.dia,encomendas[i].dataEntrega.mes,encomendas[i].dataEntrega.ano);
            fprintf(file,"%s\n",encomendas[i].observacoes);
        }
    }
    fclose(file);
}
