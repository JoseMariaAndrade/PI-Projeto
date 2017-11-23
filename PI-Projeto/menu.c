#include <stdio.h>
#include <ctype.h>

#include "funcoesAuxiliares.h"
#include "menu.h"

char menuPrincipal(int nVeiculos, int nEcomendasRegistadas, int nEcomendasDevolvidas, float percEcomendasEntregues){
char opcao;

    do{
        printf("\n \t Menu Principal");
        printf("\n Numero de veiculos registados: %d \t Numero de ecomendas registadas: %d", nVeiculos, nEcomendasRegistadas);
        printf("\n Percentagem de ecomendas enmtregues(%%): %f \t Numero de ecomendas devolvidas: %d", percEcomendasEntregues, nEcomendasDevolvidas);
        printf("\n");
        printf("\n V - veiculos");
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
