#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED

#include "estruturas.h"

void adicionarVeiculos(tipoVeiculo veiculo[], int *nVeiculos);
void mostrarVeiculos(tipoVeiculo[], int nVeiculos);
void consultaVeiculos(tipoVeiculo veiculos[], int nVeiculos, char tipoPesquisa);
int maximoCarga(tipoVeiculo veiculos[], int nVeiculos);
int procurarVeiculo(tipoVeiculo veiculos[], int nVeiculos, char matricula[]);
void ordenarVeiculosEncomendasDecrescente(tipoVeiculo veiculos[], int nVeiculos);
void mostarVeiculoEncomenda (tipoVeiculo veiculos[], tipoEncomenda encomendas[], int nVeiculos, int nEncomendas);
void calculosVeiculos(tipoVeiculo veiculos[], int nVeiculos, float *mediaCarga);
void mostrarVeiculosMenosViagens(tipoVeiculo veiculos[], int nVeiculos);
#endif // VEICULO_H_INCLUDED
