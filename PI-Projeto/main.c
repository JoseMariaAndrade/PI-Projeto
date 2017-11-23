#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"
#include "menu.h"
#include "veiculo.h"

int main()
{
    tipoVeiculo veiculos[MAX_VEICULOS];
    tipoEncomenda encomendas[MAX_ENCOMENDAS];
    int nVeiculos, nEcomendasRegistadas, nEcomendasDevolvidas;
    float percEcomendasEntregues;
    char opcao, opcao1;

    veiculos[0] = adicionarVeiculos();

    do{
        opcao = menuPrincipal(nVeiculos, nEcomendasRegistadas, percEcomendasEntregues, nEcomendasDevolvidas);
        switch(opcao){
            case 'V':
                //menu admin que dá acesso ao registo
                do{
                    opcao1 = menuAdmin();
                    switch(opcao1){

                        //faltam alguns cases mas ainda nao sei se vou fazer dois menus (um de registo e outro de leitura)

                        case 'C':
                            break;
                        case 'I':
                            break;
                        case 'R':
                            break;
                        case 'D':
                            break;
                        case 'V':
                            break;
                    }
                }while(opcao1 != 'V');
                break;
            case 'S':
                //stats sobre a empresa(ecomendas/veiculos)
                break;
            case 'F':
                printf("\n Terminou o programa");
                break;
                }
    }while(opcao != 'F');
    return 0;
}
