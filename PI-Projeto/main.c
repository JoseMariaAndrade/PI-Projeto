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
    float percEcomendasEntregues=0.0, mediaPesos = 0, mediaCarga = 0;
    char opcao, opcao1;
/*
    veiculos[0].carga=1000;
    veiculos[0].encomendas=2;
    veiculos[0].viagens=1;
    veiculos[0].estado=0;
    strcpy(veiculos[0].matricula,"22-22-DD");

    veiculos[1].carga=100;
    veiculos[1].encomendas=50;
    veiculos[1].viagens=1;
    veiculos[1].estado=0;
strcpy(veiculos[1].matricula,"22-22-DS");
    veiculos[2].carga=1000;
    veiculos[2].encomendas=3;
    veiculos[2].viagens=1;
    veiculos[2].estado=1;
    strcpy(veiculos[2].matricula,"23-22-DD");
    veiculos[3].carga=1000;
    veiculos[3].encomendas=250;
    veiculos[3].viagens=1;
    veiculos[3].estado=1;
strcpy(veiculos[3].matricula,"22-23-DD");
    encomendas[0].numero=1;
    encomendas[0].estado=0;
    encomendas[1].numero=13;
    encomendas[1].estado=0;

    encomendas[2].numero=132;
    encomendas[2].estado=0;*/


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
                        mostrarEncomendas(encomendas, nEncomendasRegistadas);
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
                        descarregarVeiculo(veiculos, nVeiculos, encomendas, nEncomendasRegistadas);
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
             printf("\nPeso medio das encomendas: %.2f", mediaPesos);
             printf("\nPercentagem de encomendas entregues: %.2f", percEcomendasEntregues);
             calculosVeiculos(veiculos, nVeiculos, &mediaCarga);
             printf("\nCarga media dos veiculos: %.2f", mediaCarga);
             maiorDestino(encomendas, nEncomendasRegistadas);
             mostrarVeiculosMenosViagens(veiculos, nVeiculos);
            break;
        case 'G':
             gravarFicheiroBinario(veiculos, encomendas, nVeiculos, nEncomendasRegistadas);
             gravarFicheiroTexto(veiculos, encomendas, nVeiculos, nEncomendasRegistadas);
             contSave++;
            break;
        case 'L':
            lerFicheiroBinario(veiculos, encomendas, &nVeiculos, &nEncomendasRegistadas);
            break;
        case 'F':
            if(contSave == 0){
                opcao1 = menuSave();
                switch(opcao1){
                    case 'S':
                        gravarFicheiroBinario(veiculos, encomendas, nVeiculos, nEncomendasRegistadas);
                        gravarFicheiroTexto(veiculos, encomendas, nVeiculos, nEncomendasRegistadas);
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
