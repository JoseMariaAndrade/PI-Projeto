#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#define MAX_VEICULOS 10
#define MAX_ENCOMENDAS 100
#define MATRICULA 9
#define DESTINO 50
#define OBSERVACOES 100

 typedef enum
{
    disponivel,
    transportar,
    regresso,
    avariado
} estadoVeiculo;

typedef enum
{
    registada,
    carregada,
    entregue,
    devolvida
} estadoEncomenda;

typedef struct
{
    int dia, mes, ano;
} tipoData;

typedef struct
{
    int carga, viagens, encomendas;
    char matricula[MATRICULA];
    tipoData dataFabrico;
    estadoVeiculo estado;
} tipoVeiculo;

typedef struct
{
    int numero, peso;
    tipoData dataRegisto, dataEntrega, dataDevolucao;
    char destino[DESTINO], observacoes[OBSERVACOES];
    estadoEncomenda estado;
} tipoEncomenda;

#endif // ESTRUTURAS_H_INCLUDED
