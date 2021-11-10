#include "interface.h"
#include <stdio.h>

// Retorna a ordem (t) requisitada
int inputOrdem(){
    //TODO Verificações aqui, deixar mais bunitu
    int t = 0;
    printf("Ordem: ");
    scanf("%d", &t);
    return t;
}

/// Retorna um struct da operação requisitada
struct Operacao inputOperacao(){
    //TODO Verificações aqui, deixar mais bunitu
    int opCode = 0;
    int param = -1;
    struct Operacao op;
    printf(" (1) - Busca\n (2) - Insercao\n (3) - Sair\n");
    scanf("%d", &opCode);
    switch (opCode)
    {
    case 1:
        // Busca
        printf("Digite a chave a ser buscada: ");
        scanf("%d", &param);
        op.tipo = Busca;
        op.param = param;
        break;
    case 2:
        // Inserção
        printf("Digite a chave a ser inserida: ");
        scanf("%d", &param);
        op.tipo = Insercao;
        op.param = param;
        break;
    case 3:
        // Finalizar
        op.tipo = Finalizar;
        break;
    default:
        //TODO Verificar input
        printf("interface: Valor inválido, finalizando...\n");
        break;
    }
    return op;
}