#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#define MAX_VEICULOS 10
#define MAX_ENCOMENDAS 100
#define MATRICULA 9
#define DESTINO 50
#define OBSERVACOES 100
#define MAX_PESO 1000000
#define MIN_PESO 1
#define MAX_CARGA 1000000
#define MIN_CARGA 1
#define MIN_ENCOMENDA 1
#define MAX_ENCOMENDA 9999

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
    int viagens, encomendas;
    float carga;
    char matricula[MATRICULA];
    tipoData dataFabrico;
    estadoVeiculo estado;
} tipoVeiculo;

typedef struct
{
    int numero;
    float peso;
    tipoData dataRegisto, dataEntrega, dataDevolucao;
    char destino[DESTINO], observacoes[OBSERVACOES], matricula[MATRICULA];
    estadoEncomenda estado;
} tipoEncomenda;

#endif // ESTRUTURAS_H_INCLUDED
