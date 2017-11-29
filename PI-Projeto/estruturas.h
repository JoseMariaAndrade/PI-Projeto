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

enum estadoEncomenda
{
    registada,
    carregada,
    entregue,
    devolvida
};

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
    enum estadoEncomenda estado;
} tipoEncomenda;

#endif // ESTRUTURAS_H_INCLUDED
