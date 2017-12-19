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

float lerFloat(char mensagem[MAX_CHARS], int minimo, int maximo){
    int controlo;
    float numero;

    do{
        printf("%s (%d - %d)", mensagem, minimo,maximo);
        controlo = scanf("%f", &numero);
        limparBufferStdin();
        if(numero<minimo || numero>maximo || controlo==0){
            printf("\n Numero invalido");
        }
    }while(numero<minimo || numero>maximo || controlo ==0);

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
    data.mes = lerInteiro("Mes ", 1, 12);
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

    data.dia=lerInteiro("Dia ", 1, maxDiasMes);

    return data;
}

char* lerMatricula(char Mensagem[MAX_CHARS], char* r)
{
    int contadorNumeros=0, contadorLetras=0, a, b, controlo=0, tamanho;
    char parteMatricula[3], matricula[MATRICULA] = "";
    memset(r, 0, 9);
    do
    {
        if((contadorNumeros==0 && contadorLetras==0) || (contadorNumeros==1 && contadorLetras==0))
        {
            printf("\nInsera dois numeros ou duas letras:");
            fgets(parteMatricula, sizeof(parteMatricula), stdin);
            a = (int)parteMatricula[0];
            b = (int)parteMatricula[1];
            if(isdigit(a) && isdigit(b))
            {
                contadorNumeros++;
                tamanho = strlen(parteMatricula);

                limparBufferStdin();

                strcat(matricula, parteMatricula);
                if(strlen(matricula)<8)
                {
                    strcat(matricula,"-");
                }
            }
            else
            {
                if(isalpha(a) && isalpha(b))
                {
                    contadorLetras++;

                    tamanho = strlen(parteMatricula);

                    if (tamanho == 1)
                    {
                        printf("\n String Vazia.");
                    }
                    else
                    {
                        if(parteMatricula[tamanho-1] == '\n')
                        {
                            parteMatricula[tamanho-1] = '\0';
                        }
                        else
                        {
                            limparBufferStdin();
                        }
                    }

                    strcat(matricula, parteMatricula);
                    if(strlen(matricula)<8)
                    {
                        strcat(matricula,"-");
                    }
                }
                else
                {
                    printf("\nErro");
                }
            }
        }
        else
        {
            if(contadorLetras==1)
            {
                printf("\nInsera dois numeros:");
                fgets(parteMatricula, sizeof(parteMatricula), stdin);
                a = (int)parteMatricula[0];
                b = (int)parteMatricula[1];
                if(isdigit(a) && isdigit(b))
                {
                    contadorNumeros++;
                    tamanho = strlen(parteMatricula);

                    limparBufferStdin();

                    strcat(matricula, parteMatricula);
                    if(strlen(matricula)<8)
                    {
                        strcat(matricula,"-");
                    }

                }
                else
                {
                    printf("\nErro");
                }

            }
            else
            {
                if(contadorNumeros==2)
                {
                    printf("\nInsera duas letras:");
                    fgets(parteMatricula, sizeof(parteMatricula), stdin);
                    a = (int)parteMatricula[0];
                    b = (int)parteMatricula[1];
                    if(isalpha(a) && isalpha(b))
                    {
                        contadorLetras++;
                        tamanho = strlen(parteMatricula);

                        if (tamanho == 1)
                        {
                            printf("\n String Vazia.");
                        }
                        else
                        {
                            if(parteMatricula[tamanho-1] == '\n')
                            {
                                parteMatricula[tamanho-1] = '\0';
                            }
                            else
                            {
                                limparBufferStdin();
                            }
                        }
                        strcat(matricula, parteMatricula);
                        if(strlen(matricula)<8)
                        {
                            strcat(matricula,"-");
                        }
                    }
                    else
                    {
                        printf("\nErro");
                    }
                }
            }
        }

        if(contadorNumeros==2 && contadorLetras==1)
        {
            controlo=1;
        }
    }
    while(controlo!=1);

    strcat(r, matricula);

    return r;
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
            fprintf(file,"%f\n",veiculos[i].carga);
            fprintf(file,"%d\n",veiculos[i].viagens);
            fprintf(file,"%d\n",veiculos[i].encomendas);
        }

        for(i=0; i<nEncomendas; i++)
        {
            fprintf(file,"%d\n",encomendas[i].numero);
            fprintf(file,"%f\n",encomendas[i].peso);
            fprintf(file,"%d\n",encomendas[i].estado);
            fprintf(file,"%s\n",encomendas[i].destino);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataRegisto.dia,encomendas[i].dataRegisto.mes,encomendas[i].dataRegisto.ano);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataEntrega.dia,encomendas[i].dataEntrega.mes,encomendas[i].dataEntrega.ano);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataDevolucao.dia,encomendas[i].dataEntrega.mes,encomendas[i].dataEntrega.ano);
            fprintf(file,"%s\n",encomendas[i].observacoes);
        }
    }
    if(fclose(file) == EOF){
            perror("\n Erro ao fechar ficheiro");
        }
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
            fprintf(file,"%f\n",veiculos[i].carga);
            fprintf(file,"%d\n",veiculos[i].viagens);
            fprintf(file,"%d\n",veiculos[i].encomendas);
        }

        for(i=0; i<nEncomendas; i++)
        {
            fprintf(file,"%d\n",encomendas[i].numero);
            fprintf(file,"%f\n",encomendas[i].peso);
            fprintf(file,"%d\n",encomendas[i].estado);
            fprintf(file,"%s\n",encomendas[i].destino);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataRegisto.dia,encomendas[i].dataRegisto.mes,encomendas[i].dataRegisto.ano);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataEntrega.dia,encomendas[i].dataEntrega.mes,encomendas[i].dataEntrega.ano);
            fprintf(file,"%d-%d-%d\n",encomendas[i].dataDevolucao.dia,encomendas[i].dataEntrega.mes,encomendas[i].dataEntrega.ano);
            fprintf(file,"%s\n",encomendas[i].observacoes);
        }
    }
    if(fclose(file) == EOF){
            perror("\n Erro ao fechar ficheiro");
        }
}

void escreverFicheiroLog(tipoEncomenda encomenda){
    FILE *file;
    file = fopen("log.txt", "a");
    if(file == NULL){
        perror("\n Erro ao abrir ficheiro log.");
    }else{
        fprintf(file, "\n\t%d\t%s\t %d/%d/%d\t%s", encomenda.numero, encomenda.destino, encomenda.dataDevolucao.dia, encomenda.dataDevolucao.mes, encomenda.dataDevolucao.ano, encomenda.matricula);
        fprintf(file, "\nCausa da devolução:%s", encomenda.observacoes);
    }if(fclose(file) == EOF){
            perror("\n Erro ao fechar ficheiro");
        }
}

void lerFicheiroBinario(tipoVeiculo veiculos[], tipoEncomenda encomendas[], int *nVeiculos, int *nEncomendas){
    int i;
    *nEncomendas = 0;
    *nVeiculos = 0;

    FILE* file;
    file = fopen("dados.dat","rb");
    if(file == NULL){
        perror("\n Erro ao abrir ficheiro para leitura");
    }
    else{
        fread(nVeiculos,sizeof(int),1,file);
        fread(nEncomendas,sizeof(int),1,file);
      /*  for(i=0; i<&(*nVeiculos); i++)
        {
            fread(veiculos,sizeof(tipoVeiculo),10,file);
            fread(veiculos[i].matricula,sizeof(tipoVeiculo),10,file);
            fread(veiculos[i].dataFabrico.dia,sizeof(tipoVeiculo),10,file);
            fread(veiculos[i].dataFabrico.mes,sizeof(tipoVeiculo),10,file);
            fread(veiculos[i].dataFabrico.ano,sizeof(tipoVeiculo),10,file);
            fread(veiculos[i].carga,sizeof(tipoVeiculo),10,file);
            fread(veiculos[i].viagens,sizeof(tipoVeiculo),10,file);
            fread(veiculos[i].encomendas,sizeof(tipoVeiculo),10,file);
        }

        for(i=0; i<nEncomendas; i++)
        {
            fread(encomendas,sizeof(tipoEncomenda),100,file);
            fread(encomendas[i].numero,sizeof(tipoEncomenda),100,file);
            fread(encomendas[i].peso,sizeof(tipoEncomenda),100,file);
            fread(encomendas[i].estado,sizeof(tipoEncomenda),100,file);
            fread(encomendas[i].destino,sizeof(tipoEncomenda),100,file);
            fread(encomendas[i].dataRegisto.dia,encomendas[i].dataRegisto.mes,encomendas[i].dataRegisto.ano,sizeof(tipoEncomenda),100,file);
            fread(encomendas[i].dataEntrega.dia,encomendas[i].dataEntrega.mes,encomendas[i].dataEntrega.ano,sizeof(tipoEncomenda),100,file);
            fread(encomendas[i].dataDevolucao.dia,encomendas[i].dataEntrega.mes,encomendas[i].dataEntrega.ano,sizeof(tipoEncomenda),100,file);
            fread(encomendas[i].observacoes,sizeof(tipoEncomenda),100,file);
        }*/
    }
    if(fclose(file) == EOF){
            perror("\n Erro ao fechar ficheiro ");
    }
}
