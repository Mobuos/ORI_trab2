#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "testes.h"
#include "arvoreB.h"

int main(int argc, char *argv[])
{
    // Determina se serão usados os testes automatizados
    int teste;
    teste = 0;
    FILE *inFile;
    if(argc == 2){
        teste = 1;
        
        // Abre arquivo
        inFile = fopen(argv[1], "r");
        if(inFile == NULL){
            printf("Falha na abertura do arquivo\n");
            exit(1);
        }
    }

    int t;
    if(teste){
        t = autoInOrdem(inFile);
    }else{
        t = inputOrdem(inFile);
    }

    //TODO: Criar árvore de ordem t
    printf("main: Criar arvore de ordem %d\n", t); //Debug
    

    int op;
    do{
        if(teste){
            op = autoInOperacao(inFile);
        }else{
            op = inputOperacao();
        }
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