#include <stdio.h>
#include <ctype.h>

#include "funcoesAuxiliares.h"
#include "menu.h"

char menuPrincipal(int nVeiculos, int nEcomendasRegistadas, int nEcomendasDevolvidas, float percEcomendasEntregues){
char opcao;

    do{
        printf("\n \t\t\t\t\t\t Menu Principal");
        printf("\n Numero de veiculos registados: %d \t\t\t\t Numero de ecomendas registadas: %d", nVeiculos, nEcomendasRegistadas);
        printf("\n Percentagem de ecomendas entregues(%%): %.2f \t\t\t Numero de ecomendas devolvidas: %d", percEcomendasEntregues, nEcomendasDevolvidas);
        printf("\n");
        printf("\n V - Veiculos");
        printf("\n E - Ecomendas");
        printf("\n R - Registo");
        printf("\n S - Stats");
        printf("\n G - Gravar Ficheiros");
        printf("\n L - Ler Ficheiro");
        printf("\n F - Fechar programa");
        printf("\n Opcao: ");

        scanf("%c", &opcao);
        limparBufferStdin();
        opcao = toupper(opcao);
        if(opcao != 'V' && opcao != 'E' && opcao != 'R' && opcao != 'S'&& opcao != 'G' && opcao != 'L' && opcao != 'F'){
            printf("\n Opcao invalida");
        }
    }while(opcao != 'V' && opcao != 'E' && opcao != 'R' && opcao != 'S'&& opcao != 'G' && opcao != 'L' && opcao != 'F');
    return opcao;
}

char menuRegisto(void){
char opcao;

    do{
        printf("\n \t\t\t\t\t\t Menu Registo");
        printf("\n C - Registar carregamento de ecomendas");
        printf("\n D - Registo o descarregamento da ecomenda");
        printf("\n I - Registar inicio da viagem");
        printf("\n R - Registar regresso ao centro de distribuicao");
        printf("\n V - Voltar ao menu principal");
        printf("\n Opcao: ");

        scanf("%c", &opcao);
        limparBufferStdin();
        opcao = toupper(opcao);

        if(opcao != 'C' && opcao != 'D' && opcao != 'I' && opcao != 'R' && opcao != 'V'){
            printf("\n Opcao invalida");
        }
    }while(opcao != 'C' && opcao != 'D' && opcao != 'I' && opcao != 'R' && opcao != 'V');
    return opcao;
}

char menuVeiculos(void){
char opcao;

    do{
        printf("\n \t\t\t\t\t\t Menu Veiculos");
        printf("\n I - Inserir dados do veiculo");
        printf("\n C - Consultar dados do veiculo");
        printf("\n L - Listar dados dos veiculos");
        printf("\n E - Listar veiculos por ordem decrescente da quantidade de ecomendas transportadas");
        printf("\n U - Listar os dados do veiculo que efetuou o ultimo transporte da ecomenda(indique uma encomenda)");
        printf("\n V - Voltar ao menu principal");
        printf("\n Opcao: ");

        scanf("%c", &opcao);
        limparBufferStdin();
        opcao = toupper(opcao);

        if(opcao != 'I' && opcao != 'C' && opcao != 'L' && opcao != 'E' && opcao != 'U' && opcao != 'V'){
            printf("\n Opcao invalida");
        }
    }while(opcao != 'I' && opcao != 'C' && opcao != 'L' && opcao != 'E' && opcao != 'U' && opcao != 'V');
    return opcao;
}

char menuEcomendas(void){
char opcao;

    do{
        printf("\n \t\t\t\t\t\t Menu Ecomendas");
        printf("\n I - Inserir dados da ecomenda");
        printf("\n C - Consultar dados da ecomenda");
        printf("\n L - Listar dados das ecomendas");
        printf("\n E - Eliminnar ecomenda");
        printf("\n A - Alterar destino de ecomenda devolvida");
        printf("\n V - Voltar ao menu principal");
        printf("\n Opcao: ");

        scanf("%c", &opcao);
        limparBufferStdin();
        opcao = toupper(opcao);

        if(opcao != 'I' && opcao != 'C' && opcao != 'L' && opcao != 'E'&& opcao != 'A' && opcao != 'V'){
            printf("\n Opcao invalida");
        }
    }while(opcao != 'I' && opcao != 'C' && opcao != 'L' && opcao != 'E'&& opcao != 'A' && opcao != 'V');
    return opcao;
}

char menuSave(void){
char opcao;
    do{
        printf("\n Deseja gravas os dados inseridos?(Os dados serao perdidos se nao guardar)");
        printf("\n S - Sim");
        printf("\n N - Nao");
        printf("\n Opcao: ");

        scanf("%c", &opcao);
        limparBufferStdin();
        opcao = toupper(opcao);

        if(opcao != 'S' && opcao != 'N'){
            printf("\n Opcao invalida");
        }
    }while(opcao != 'S' && opcao != 'N');
    return opcao;
}
