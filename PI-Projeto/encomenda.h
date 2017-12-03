#ifndef ENCOMENDA_H_INCLUDED
#define ENCOMENDA_H_INCLUDED

#include "estruturas.h"

void adicionarEncomendas(tipoEncomenda encomenda[], int nEncomendas);
int procurarEncomendas(tipoEncomenda encomendas[], int nEncomendas, int numeroEncomenda);
void eliminarEncomeda(tipoEncomenda encomendas[], int nEncomendas, int numeroEncomenda);

#endif // ENCOMENDA_H_INCLUDED
