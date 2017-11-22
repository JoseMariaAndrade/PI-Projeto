#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#define MAX_VEICULOS 10
#define MAX_ENCOMENDAS 100
#define MATRICULA 9
#define DESTINO 50
#define OBSERVACOES 100

/*enum estadoVeiculo {
    "Disponivel",
    "A Transportar",
    "De Regresso",
    "Avariado"
};

enum estadoEncomenda {
    registada = "Registada",
    "Carregada",
    "Entregue",
    "Devolvida"
};
*/
typedef struct{
    int dia, mes, ano;
}tipoData;

/*typedef enum {
    "Registada",
    "Carregada",
    "Entregue",
    "Devolvida"
}estadoEncomenda;*/

typedef struct{
    int carga, viagens, encomendas;
    char matricula[MATRICULA];
    tipoData dataFabrico;
    //enum estadoVeiculo estado;
}tipoVeiculo;

typedef struct{
    int numero, peso;
    tipoData dataRegisto, dataEntrega, dataDevolucao;
    char destino[DESTINO], observacoes[OBSERVACOES];
    //estadoEncomenda estado;
}tipoEncomenda;

#endif // ESTRUTURAS_H_INCLUDED
