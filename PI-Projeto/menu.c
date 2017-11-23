#include <stdio.h>
#include <ctype.h>

#include "funcoesAuxiliares.h"
#include "menu.h"

char menuPrincipal(int nVeiculos, int nEcomendasRegistadas, int nEcomendasDevolvidas, float percEcomendasEntregues){
char opcao;

    do{
        printf("\n \t\t\t\t\t\t Menu Principal");
        printf("\n Numero de veiculos registados: %d \t\t\t\t Numero de ecomendas registadas: %d", nVeiculos, nEcomendasRegistadas);
        printf("\n Percentagem de ecomendas enmtregues(%%): %f \t Numero de ecomendas devolvidas: %d", percEcomendasEntregues, nEcomendasDevolvidas);
        printf("\n");
        printf("\n V - Veiculos/Ecomendas");
        printf("\n S - Stats");
        printf("\n F - Fechar programa");
        printf("\n Opcao: ");

        scanf("%c", &opcao);
        limparBufferStdin();
        opcao = toupper(opcao);
        if(opcao != 'V' && opcao != 'S'&& opcao != 'F'){
            printf("\n Opcao invalida");
        }
    }while(opcao != 'V' && opcao != 'S'&& opcao != 'F');
    return opcao;
}

char menuAdmin(void){
char opcao;

    do{
        printf("\n \t\t\t\t\t\t Menu Admin");
        printf("\n  - Inserir dados do veiculo");
        printf("\n  - Consultar dados do veiculo");
        printf("\n  - Listar dados do veiculo");
        printf("\n  - Inserir dados da ecomenda");
        printf("\n  - Consultar dados da ecomenda");
        printf("\n  - Listar dados da ecomenda");
        printf("\n  - Eleminnar ecomenda");
        printf("\n  - Alterar destino de ecomenda devolvida");
        printf("\n  - Listar veiculos por ordem decrescente da quantidade de ecomendas transportadas");
        printf("\n  - Listar os dados do veiculo que efetuou o ultimo transporte da ecomenda(   )");
        printf("\n Registo:");
        printf("\n C - Registar carregamento de ecomendas");
        printf("\n I - Registar inicio da viagem");
        printf("\n R - Registar regresso ao centro de distribuicao");
        printf("\n D - Registo o descarregamento da ecomenda");
        printf("\n V - Voltar ao menu principal");
        printf("\n Opcao: ");

        scanf("%c", &opcao);
        limparBufferStdin();
        opcao = toupper(opcao);

        //Faltam as restantes opcoes

        if(opcao != 'C' && opcao != 'I' && opcao != 'R' && opcao != 'D' && opcao != 'V'){
            printf("\n Opcao invalida");
        }
    }while(opcao != 'C' && opcao != 'I' && opcao != 'R' && opcao != 'D' && opcao != 'V');
    return opcao;
}
