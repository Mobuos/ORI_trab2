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

/// Retorna a operação requisitada
enum Operacao inputOperacao(){
    //TODO Verificações aqui, deixar mais bunitu
    int op = 0;
    printf(" (1) - Busca\n (2) - Insercao\n (3) - Sair\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        return Busca;
        break;
    case 2:
        return Insercao;
        break;
    case 3:
        return Finalizar;
        break;
    default:
        //TODO Verificar input
        printf("interface: Valor inválido, finalizando...\n");
        return Finalizar;
        break;
    }
}