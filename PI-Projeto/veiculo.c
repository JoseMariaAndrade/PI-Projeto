#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        printf("\nMatricula \t Estado \t Carga \t\t Viagens \t Encomendas \t Data Fabrico");

        for(i=0; i<nVeiculos; i++)
        {
            printf("\n%s", veiculo[i].matricula);

            switch(veiculo[i].estado)
            {
            case 0:
                printf("\t Disponivel ");
                break;
            case 1:
                printf("\t A Transportar ");
                break;
            case 2:
                printf("\t Regresso ");
                break;
            case 3:
                printf("\t Avariado ");
                break;
            }
            printf("\t %.2f \t %d \t\t %d \t\t %2d-%2d-%4d", veiculo[i].carga, veiculo[i].viagens, veiculo[i].encomendas, veiculo[i].dataFabrico.dia, veiculo[i].dataFabrico.mes, veiculo[i].dataFabrico.ano);
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
            consultaVeiculosEstado(veiculos, nVeiculos, -1);
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

void calculosVeiculos(tipoVeiculo veiculos[], int nVeiculos, float *mediaCarga)
{
    int i;
    float somaPesos = 0;
    if(nVeiculos == 0)
    {
        printf("\nNao existem veiculos registados");
        *mediaCarga = 0;
    }
    else
    {
        for(i=0; i<nVeiculos; i++)
        {
            if(veiculos[i].estado == 1)
            {
                somaPesos = somaPesos + veiculos[i].carga;
            }
            *mediaCarga = somaPesos / nVeiculos;
        }
    }
}

void mostrarVeiculosMenosViagens(tipoVeiculo veiculos[], int nVeiculos)
{
    int i;
    int menosViagens = veiculos[0].viagens;
    for(i=1; i < nVeiculos; i++)
    {
        if(menosViagens > veiculos[i].viagens)
        {
            menosViagens = veiculos[i].viagens;
        }
    }
    printf("\nVeiculo(s) com meno(s) viagens efetuadas");
    for(i=0; i<nVeiculos; i++)
    {
        if(veiculos[i].viagens = menosViagens)
        {
            printf("\n Matricula - %s Viagens - %d", veiculos[i].matricula, menosViagens);
        }
    }
}

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
        if(menor==0 && veiculos[i].estado==0)
        {
            menor=veiculos[i].viagens;
            posicao=i;
        }
        else
        {
            if(veiculos[i].viagens<menor && veiculos[i].estado==0)
            {
                menor=veiculos[i].viagens;
                posicao=i;
            }
        }
    }

    return posicao;
}

float PercentagemCargaVeiculo(float cargaVeiculo, float cargaTotal)
{
    float percentagemCarga=0;

    percentagemCarga = cargaTotal/cargaVeiculo;

    return percentagemCarga;
}

void carregarVeiculo(tipoVeiculo veiculos[], int nVeiculos, tipoEncomenda encomendas[], int nEncomendas)
{
    int posicaoVeiculo, posicaoEncomendas, contadorEncomendas=0, i, index[MAX_ENCOMENDAS], contadorVeiculos=-1, numero, contador=-1;;
    float somaCarga=0, percentagemCarga=0;
    char matricula[MATRICULA], opcao;
    char str[MATRICULA] = {'\0'};

    if(nVeiculos!=0 && nEncomendas!=0)
    {
        for(i=0; i<nVeiculos; i++)
        {
            if(veiculos[i].estado==0)
            {
                contadorVeiculos++;
            }
        }

        if(contadorVeiculos!=-1)
        {
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

            if(opcao=='S')
            {
                posicaoVeiculo = escolhaAutomatica(veiculos, nVeiculos);
            }
            else
            {
                consultaVeiculosEstado(veiculos, nVeiculos, 0);

                do
                {
                    strcpy(matricula,lerMatricula("\nIndique o veiculo pela Matricula:", str));
                    posicaoVeiculo = procurarVeiculo(veiculos, nVeiculos, matricula);

                    if(posicaoVeiculo==-1)
                    {
                        printf("\nO veiculo com a matricula %s nao existe.", matricula);
                    }

                }
                while (posicaoVeiculo==-1);
            }

            contadorEncomendas = contagemEncomendasEstado(encomendas, nEncomendas, 0);
            contadorEncomendas = contadorEncomendas + contagemEncomendasEstado(encomendas, nEncomendas, 3);

            if(contadorEncomendas!=0)
            {

                for(i=0; i<nEncomendas; i++)
                {
                    if(encomendas[i].estado == 0 || encomendas[i].estado == 3)
                    {
                        contador++;
                        index[contador]=i;
                    }
                }

                printf("\n------------- Encomendas -------------");
                printf("\n Numero de Registo \t Data de registo \t Peso(Kg) \t Destino \t Estado \t Data de Entrega(Ou devolucao) \t Conjunto de Obrevacoes");

                for(i=0; i<contadorEncomendas; i++)
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

                do
                {
                    numero = lerInteiro("\nInsira o numero da encomenda", 0, 0);

                    posicaoEncomendas = procurarEncomendas(encomendas, nEncomendas, numero);

                    if(posicaoEncomendas==-1 && numero!=0)
                    {
                        printf("\nO numero da encomenda indicado nao existem.");
                    }
                    else
                    {
                        if(encomendas[posicaoEncomendas].estado==1 || encomendas[posicaoEncomendas].estado==2)
                        {
                            printf("\nA encomenda com o numero %d ja se encontra carregada ou entregue.", numero);
                        }
                    }

                    somaCarga = somaCarga + encomendas[posicaoEncomendas].peso;
                    percentagemCarga = PercentagemCargaVeiculo(veiculos[posicaoVeiculo].carga, somaCarga);

                    if(percentagemCarga>=0.8)
                    {
                        if(percentagemCarga>=1)
                        {
                            printf("\nA encomenda com o numero %d e demasido pesada para transportada pelo veiculo com a matricula %s", encomendas[posicaoVeiculo].numero, veiculos[posicaoEncomendas].matricula);

                            somaCarga = somaCarga - encomendas[posicaoEncomendas].peso;
                            percentagemCarga = PercentagemCargaVeiculo(veiculos[posicaoVeiculo].carga, somaCarga);
                            contadorEncomendas++;
                        }
                        else
                        {
                            do
                            {
                                printf("\n Deseja que o veiculo com a matricula %s inicie viagem:", veiculos[posicaoVeiculo].matricula);
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

                            switch(opcao)
                            {
                            case 'S':
                                numero=0;
                                veiculos[posicaoEncomendas].estado=1;
                                printf("\nO veiculo com a matricula %s vai inicar viagem.", veiculos[posicaoVeiculo].matricula);
                                break;
                            case 'N':
                                encomendas[posicaoEncomendas].estado=1;
                                strcpy(encomendas[posicaoEncomendas].matricula, veiculos[posicaoVeiculo].matricula);
                                break;
                            }
                        }

                    }
                    else
                    {
                        encomendas[posicaoEncomendas].estado=1;
                        strcpy(encomendas[posicaoEncomendas].matricula, veiculos[posicaoVeiculo].matricula);
                    }

                    contadorEncomendas--;

                    if(contadorEncomendas==0)
                    {
                        numero=0;
                        printf("\nRegistou a ultima encomenda.");
                    }
                }
                while(numero!=0);
            }
            else
            {
                printf("\nNao existem encomendas registadas ou devolvidas");
            }
        }
        else
        {
            printf("\nNao existem veiculos disponiveis");
        }
    }
    else
    {
        printf("\nNao existem veiculos ou encomendas.");
    }
}

void consultaVeiculosEstado(tipoVeiculo veiculos[], int nVeiculos, int estado)
{
    int contador=-1, index[MAX_VEICULOS], i;

    if(estado==-1)
    {
        estado = lerEstado('V');
    }

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
}
