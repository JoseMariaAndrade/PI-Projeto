#include <stdio.h>
#include <stdlib.h>

#include "encomenda.h"
#include "menu.h"
#include "veiculo.h"
#include "funcoesAuxiliares.h"

int main(void)
{
    tipoVeiculo veiculos[MAX_VEICULOS];
    tipoEncomenda encomendas[MAX_ENCOMENDAS];
    int nVeiculos=0, nEncomendasRegistadas=0, nEcomendasDevolvidas=0, contSave=0;
    float percEcomendasEntregues=0.0, mediaPesos = 0;
    char opcao, opcao1;

    do
    {
        opcao = menuPrincipal(nVeiculos, nEncomendasRegistadas, percEcomendasEntregues, nEcomendasDevolvidas);
        switch(opcao){
        case 'V':
            do{
                opcao = menuVeiculos();
                switch(opcao){
                    case 'I':
                        adicionarVeiculos(veiculos, &nVeiculos);
                        break;
                    case 'C':
                        consultaVeiculos(veiculos, nVeiculos, 'V');
                        break;
                    case 'L':
                        mostrarVeiculos(veiculos, nVeiculos);
                        break;
                    case 'E':
                        ordenarVeiculosEncomendasDecrescente(veiculos, nVeiculos);
                        mostrarVeiculos(veiculos, nVeiculos);
                        break;
                    case 'U':
                        break;
                    case 'V':
                        break;
                }
            }while(opcao != 'V');
            break;
        case 'E':
            do{
                opcao = menuEcomendas();
                switch(opcao){
                    case 'I':
                        adicionarEncomendas(encomendas, &nEncomendasRegistadas);
                        break;
                    case 'C':
                        break;
                    case 'L':
                        mostrarEncomendas(encomendas,nEncomendasRegistadas);
                        break;
                    case 'E':
                        eliminarEncomeda(encomendas, &nEncomendasRegistadas);
                        break;
                    case 'A':
                        alterarDestino(encomendas, &nEncomendasRegistadas);
                        break;
                    case 'V':
                        break;
                }
            }while(opcao != 'V');
            break;
        case 'R':
            do{
                opcao = menuRegisto();
                switch(opcao){
                    case 'C':
                        carregarVeiculo(veiculos, nVeiculos, encomendas, nEncomendasRegistadas);
                        break;
                    case 'D':
                        break;
                    case 'I':
                        registarInicioViagemVeiculo(veiculos, nVeiculos);
                        break;
                    case 'R':
                        registarRegressoVeiculo(veiculos, nVeiculos);
                        break;
                    case 'V':
                        break;
                }
            }while(opcao != 'V');
            break;
        case 'S':
             calculos(encomendas, nEncomendasRegistadas, &mediaPesos, &percEcomendasEntregues);
             printf("\n Peso medio das encomendas: %.2f", mediaPesos);
             printf("\n Percentagem de encomendas entregues: %.2f", percEcomendasEntregues);
            break;
        case 'G':
             //funcao save;
             contSave++;
            break;
        case 'L':
            //lerFicheiroTexto
            break;
        case 'F':
            if(contSave == 0){
                opcao1 = menuSave();
                switch(opcao1){
                    case 'S':
                        //funcao save
                        break;
                    case 'N':
                        break;
                }
            }
            printf("\n Terminou o programa");
            break;
        }
    }
    while(opcao != 'F');
    return 0;
}
