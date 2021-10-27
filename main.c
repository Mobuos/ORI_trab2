#include <stdio.h>
#include "interface.h"
#include "arvoreB.h"

int main()
{
    int t = inputOrdem();
    // Criar árvore de ordem t

    printf("%d\n", t); //Debug

    int op;
    do{
        op = inputOperacao();
    }while(op != Finalizar);

    return 0;
}