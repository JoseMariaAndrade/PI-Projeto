#ifndef FUNCOESAUXILIARES_H_INCLUDED
#define FUNCOESAUXILIARES_H_INCLUDED

#include "estruturas.h"

#define MAX_CHARS 50
#define ANO_MINIMO 2016
#define ANO_MAXIMO 2018

void limparBufferStdin();
int lerInteiro(char mensagem[MAX_CHARS], int numeroMinimo, int numeroMaximo);
tipoData lerData(char mensagem[MAX_CHARS]);
char* lerMatricula(char Mensagem[MAX_CHARS], char* r);
float lerFloat(char mensagem[MAX_CHARS], int minimo, int maximo);
void lerString(char mensagem[MAX_CHARS], char vetorChars[50], int maximoCaracteres);
int lerEstado(char tipoEstado);
void gravarFicheiroTexto(tipoVeiculo veiculos[], tipoEncomenda encomendas[], int nVeiculos, int nEncomendas);
void gravarFicheiroBinario(tipoVeiculo veiculos[], tipoEncomenda encomendas[], int nVeiculos, int nEncomendas);
void escreverFicheiroLog(tipoEncomenda encomenda);
void lerFicheiroBinario(tipoVeiculo veiculos[], tipoEncomenda encomendas[], int *nVeiculos, int *nEncomendas);

#endif // FUNCOESAUXILIARES_H_INCLUDED
