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
    char opcao;

    veiculos[0] = adicionarVeiculos();

    do{
        opcao = menuPrincipal(nVeiculos, nEcomendasRegistadas, percEcomendasEntregues, nEcomendasDevolvidas);
        switch(opcao){
            case 'V':
                //menu para controlo de ecomendas/veiculos(adicionar/remover/etc)
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
