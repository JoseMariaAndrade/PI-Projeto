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

typedef struct{
    char destino[DESTINO];
    int contador;
} tipoClone;

#endif // ESTRUTURAS_H_INCLUDED
