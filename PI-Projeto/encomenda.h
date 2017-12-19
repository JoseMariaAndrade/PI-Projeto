#ifndef ENCOMENDA_H_INCLUDED
#define ENCOMENDA_H_INCLUDED

#include "estruturas.h"
#include "funcoesAuxiliares.h"

void adicionarEncomendas(tipoEncomenda encomenda[], int *nEncomendas);
int procurarEncomendas(tipoEncomenda encomendas[], int nEncomendas, int numeroEncomenda);
void eliminarEncomeda(tipoEncomenda encomendas[], int *nEncomendas);
void alterarDestino(tipoEncomenda encomendas[], int *nEncomendas);
void calculos(tipoEncomenda encomendas[MAX_ENCOMENDAS], int nEncomendasRegistadas, float *mediaPesos, float * perEncomendasEntregues);
void mostrarEncomendas(tipoEncomenda encomenda[MAX_ENCOMENDAS], int nEncomendasRegistadas);

#endif // ENCOMENDA_H_INCLUDED
