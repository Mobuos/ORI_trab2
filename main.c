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

    // Recebe a variável t (Seja do usuário ou do arquivo de testes)
    int t;
    if(teste){
        t = autoInOrdem(inFile);
    }else{
        t = inputOrdem(inFile);
    }

    //TODO: Criar árvore de ordem t
    printf("main: Criar arvore de ordem %d\n", t); //Debug
    
    // Loop principal de operações sobre a árvore B
    struct Operacao op = {Finalizar, -1};
    do{
        if(teste){
            op = autoInOperacao(inFile);
        }else{
            op = inputOperacao();
        }
        switch (op.tipo)
        {
        case Insercao:
            printf("main: Insercao de %d\n", op.param);
            break;
        case Busca:
            printf("main: Busca de %d\n", op.param);
            break;
        case Finalizar:
            printf("main: Finalizando...\n");
            break;
        default:
            printf("Erro: Operacao recebida da interface inválida\n");
            return 1;
            break;
        }
    }while(op.tipo != Finalizar);

    // Fecha o arquivo de testes caso necessário
    if(teste){
        fclose(inFile);
    }

    return 0;
}