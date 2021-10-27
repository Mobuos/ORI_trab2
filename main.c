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
        switch (op)
        {
        case Insercao:
            printf("main: Insercao\n");
            break;
        case Busca:
            printf("main: Busca\n");
            break;
        case Finalizar:
            printf("main: Finalizando...\n");
            break;
        default:
            printf("Erro: Operacao recebida da interface inválida\n");
            return 1;
            break;
        }
    }while(op != Finalizar);

    return 0;
}