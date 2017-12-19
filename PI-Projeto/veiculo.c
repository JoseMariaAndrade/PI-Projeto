#include <stdio.h>
#include <string.h>

#include "veiculo.h"
#include "estruturas.h"
#include "funcoesAuxiliares.h"
#include "encomenda.h"

void adicionarVeiculos(tipoVeiculo veiculo[], int *nVeiculos)
{
    int restanteVeiculos, numero, posicao, i;
    restanteVeiculos = MAX_VEICULOS - *nVeiculos;
    char str[MATRICULA] = {'\0'};

    if (restanteVeiculos==0)
    {
        printf("\nNao pode inserir mais veiculos");
    }
    else
    {
        numero = lerInteiro("\nQuantos veiculos pretende inserir",0,restanteVeiculos);

        if(numero!=0)
        {
            for (i=0; i<numero; i++)
            {
                printf("\nInserir dados do veiculo:");
                veiculo[*nVeiculos].carga=lerInteiro("\nCarga",10, 10000);
                veiculo[*nVeiculos].viagens=0;
                veiculo[*nVeiculos].encomendas=0;
                veiculo[*nVeiculos].dataFabrico=lerData("\nInserir Data de Fabrico do veiculo:");

                do
                {
                    strcpy(veiculo[*nVeiculos].matricula, lerMatricula("Matricula:", str));
                    //printf("%s", veiculo[*nVeiculos].matricula);
                    posicao = procurarVeiculo(veiculo, *nVeiculos, veiculo[*nVeiculos].matricula);

                    if(posicao!=-1)
                    {
                        printf("\nA matricula %s ja existe.", veiculo[*nVeiculos].matricula);
                    }
                }
                while(posicao!=-1);

                veiculo[*nVeiculos].estado = lerEstado('V');
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
            printf("\t %f \t %d \t\t %d \t\t %2d-%2d-%4d", veiculo[i].carga, veiculo[i].viagens, veiculo[i].encomendas, veiculo[i].dataFabrico.dia, veiculo[i].dataFabrico.mes, veiculo[i].dataFabrico.ano);
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

                    printf("\t %f \t %d \t\t %d \t\t %2d-%2d-%4d", veiculos[index[i]].carga, veiculos[index[i]].viagens, veiculos[index[i]].encomendas, veiculos[index[i]].dataFabrico.dia, veiculos[index[i]].dataFabrico.mes, veiculos[index[i]].dataFabrico.ano);
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

                    printf("\t %f \t %d \t\t %d \t\t %2d-%2d-%4d", veiculos[index[i]].carga, veiculos[index[i]].viagens, veiculos[index[i]].encomendas, veiculos[index[i]].dataFabrico.dia, veiculos[index[i]].dataFabrico.mes, veiculos[index[i]].dataFabrico.ano);
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

                    printf("\t %f \t %d \t\t %d \t\t %2d-%2d-%4d", veiculos[index[i]].carga, veiculos[index[i]].viagens, veiculos[index[i]].encomendas, veiculos[index[i]].dataFabrico.dia, veiculos[index[i]].dataFabrico.mes, veiculos[index[i]].dataFabrico.ano);
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

    for(i=0; i<nVeiculos; i++)
    {
        strcpy(s,veiculos[i].matricula);
        if(strcmp(s,matricula)==0)
        {
            posicao=i;
            i=nVeiculos;
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

        printf("\t %f \t %d \t\t %d \t\t %2d-%2d-%4d", veiculos[posicao].carga, veiculos[posicao].viagens, veiculos[posicao].encomendas, veiculos[posicao].dataFabrico.dia, veiculos[posicao].dataFabrico.mes, veiculos[posicao].dataFabrico.ano);
    }
    else
    {
        printf("\nNao existem Veiculos ou Encomendas");
    }
}

<<<<<<< HEAD
void calculosVeiculos(tipoVeiculo veiculos[], int nVeiculos, float *mediaCarga){
    int i;
    float somaPesos = 0;
    if(nVeiculos == 0){
        printf("\nNao existem veiculos registados");
        *mediaCarga = 0;
    }else{
        for(i=0; i<nVeiculos; i++){
            if(veiculos[i].estado == 1);
            somaPesos = somaPesos + veiculos[i].carga;
        }
        *mediaCarga = somaPesos / nVeiculos;
    }
}

void mostrarVeiculosMenosViagens(tipoVeiculo veiculos[], int nVeiculos){
    int i;
    int menosViagens = veiculos[0].viagens;
    for(i=1;i < nVeiculos;i++){
        if(menosViagens > veiculos[i].viagens){
            menosViagens = veiculos[i].viagens;
        }
    }
    printf("Veiculo(s) com meno(s) viagens efetuadas");
    for(i=0;i<nVeiculos;i++){
        if(veiculos[i].viagens = menosViagens){
            printf("\n Matricula - %s Viagens - %d", veiculos[i].matricula, menosViagens);
        }
    }
=======
void registarInicioViagemVeiculo(tipoVeiculo veiculos[], int nVeiculos)
{
    int posicao;
    char matricula[MATRICULA];
    char str[MATRICULA] = {'\0'};

    printf("\nIndique o veiculo pela Matricula:");
    do
    {
        strcpy(matricula,lerMatricula("\nIndique o veiculo pela Matricula:", str));
        posicao = procurarVeiculo(veiculos, nVeiculos, matricula);

        if(posicao==-1)
        {
            printf("\nO veiculo com a matricula %s nao existe.", matricula);
        }

    }
    while (posicao==-1);

    if(veiculos[posicao].estado==0)
    {
        veiculos[posicao].estado = 1;
    }
    else
    {
        printf("\nO veiculo com a matricula %s nao esta disponivel", veiculos[posicao].matricula);
    }
}

void registarRegressoVeiculo(tipoVeiculo veiculos[], int nVeiculos)
{
    int posicao;
    char matricula[MATRICULA];
    char str[MATRICULA] = {'\0'};
    do
    {
        strcpy(matricula,lerMatricula("\nIndique o veiculo pela Matricula:", str));
        posicao = procurarVeiculo(veiculos, nVeiculos, matricula);

        if(posicao==-1)
        {
            printf("\nO veiculo com a matricula %s nao existe.", matricula);
        }

    }
    while (posicao==-1);

    if(veiculos[posicao].estado==1)
    {
        veiculos[posicao].estado = 2;
    }
    else
    {
        printf("\nO veiculo com a matricula %s nao esta disponivel", veiculos[posicao].matricula);
    }
}

int escolhaAutomatica(tipoVeiculo veiculos[], int nVeiculos)
{
    int posicao, i, menor=0;

    for(i=0; i<nVeiculos; i++)
    {
        if(menor==0)
        {
            menor=veiculos[i].viagens;
            posicao=i;
        }
        else
        {
            if(veiculos[i].viagens<menor)
            {
                menor=veiculos[i].viagens;
                posicao=i;
            }
        }
    }

    return posicao;
}

float cargaVeiculo(tipoVeiculo veiculo, float cargaTotal)
{
    float carga=0;

    carga = veiculo.carga/cargaTotal;

    return carga;
}

void carregarVeiculo(tipoVeiculo veiculos[], int nVeiculos, tipoEncomenda encomendas[], int nEncomendas)
{
    int posicao;
    char matricula[MATRICULA], opcao;
    char str[MATRICULA] = {'\0'};

    do
    {
        printf("\nSelecionar Veiculo Automaticamente:");
        printf("\n S - Sim");
        printf("\n N - Nao");
        printf("\n Opcao: ");

        scanf("%c", &opcao);
        limparBufferStdin();
        opcao = toupper(opcao);

        if(opcao != 'S' && opcao != 'N')
        {
            printf("\n Opcao invalida");
        }
    }
    while(opcao != 'S' && opcao != 'N');

    if(opcao='S')
    {
        posicao = escolhaAutomatica(veiculos, nVeiculos);
    }
    else
    {
        do
        {
            strcpy(matricula,lerMatricula("\nIndique o veiculo pela Matricula:", str));
            posicao = procurarVeiculo(veiculos, nVeiculos, matricula);

            if(posicao==-1)
            {
                printf("\nO veiculo com a matricula %s nao existe.", matricula);
            }

        }
        while (posicao==-1);
    }

    printf("MA: %s", veiculos[posicao].matricula);
>>>>>>> 11895a032f979bcc9c4ea88e2dfb49233fcbbd81
}
