#include <stdio.h>

#include "veiculo.h"
#include "estruturas.h"
#include "funcoesAuxiliares.h"

tipoVeiculo adicionarVeiculos(void)
{
    tipoVeiculo veiculo;
    printf("\n Inserir dados do veiculo");
    veiculo.carga=lerInteiro("\nCarga:");

    return veiculo;
}
