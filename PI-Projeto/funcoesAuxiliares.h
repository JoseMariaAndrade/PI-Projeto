#ifndef FUNCOESAUXILIARES_H_INCLUDED
#define FUNCOESAUXILIARES_H_INCLUDED

#include "estruturas.h"

#define MAX_CHARS 50
#define ANO_MINIMO 2016
#define ANO_MAXIMO 2018

void limparBufferStdin();
int lerInteiro(char mensagem[MAX_CHARS], int numeroMinimo, int numeroMaximo);
tipoData lerData(char mensagem[MAX_CHARS]);
void lerMatricula(char Mensagem[MAX_CHARS], tipoVeiculo veiculo);
void lerString(char mensagem[MAX_CHARS], char vetorChars[50], int maximoCaracteres);
int lerEstado(char tipoEstado);
void gravarFicheiroTexto(tipoVeiculo veiculos[], tipoEncomenda encomendas[], int nVeiculos, int nEncomendas);
void gravarFicheiroBinario(tipoVeiculo veiculos[], tipoEncomenda encomendas[], int nVeiculos, int nEncomendas);

#endif // FUNCOESAUXILIARES_H_INCLUDED
