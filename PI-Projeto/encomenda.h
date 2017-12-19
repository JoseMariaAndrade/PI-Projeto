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
<<<<<<< HEAD
=======

int contagemEncomendasEstadoMatricula(tipoEncomenda encomendas[], int nEncomendas, int estado, char matricula[MATRICULA]);
>>>>>>> 117ed468500114d2d01759998c004c719bb43f4b
int contagemEncomendasEstado(tipoEncomenda encomendas[], int nEncomendas, int estado);
void maiorDestino(tipoEncomenda encomendas[], int nEncomendas);
void mostrarQuantidadeEncomendasData(tipoEncomenda encomendas[], int nEncomendas);

#endif // ENCOMENDA_H_INCLUDED
