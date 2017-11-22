#include <stdio.h>
#include <stdlib.h>

#include "estruturas.h"
#include "menu.h"
#include"veiculo.h"

int main()
{
    tipoVeiculo veiculos[MAX_VEICULOS];
    tipoEncomenda encomendas[MAX_ENCOMENDAS];

    veiculos[0] = adicionarVeiculos();

    return 0;
}
