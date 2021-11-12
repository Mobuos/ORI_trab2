#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "testes.h"
#include "interface.h"

// Lê um inteiro do arquivo
int lerProxInteiro(FILE *in){
    int i;
    char buffer[BUFFSIZE];
    if(fgets(buffer, BUFFSIZE, in)){
        // Nota: atoi não é a melhor função do mundo para isso, mas assumo que não terão erros de input nos casos teste.
        i = atoi(buffer);
        return i;
    }else{
        printf("Erro na leitura... Finalizando. \n");
        exit(1);
    }
}

//TODO Verificações aqui

// Retorna a ordem (t) requisitada
int autoInOrdem(FILE *in){
    printf("> Lendo ordem do arquivo...\n");
    
    int t = -1;
    t = lerProxInteiro(in);

    printf("> ordem = %d\n", t);
    return t;
}

// Retorna a operação requisitada
struct Operacao autoInOperacao(FILE *in){
    printf("> Lendo operacao...\n");
    int opCode = 0;
    int param = -1;
    struct Operacao op;

    bool continuar = false;
    char buffer[BUFFSIZE];

    // Loop para possibilitar a impressão na tela sem retornar uma operação
    do{
        continuar = false;

        opCode = lerProxInteiro(in);
        switch (opCode)
        {
        case 1:
            // Busca
            param = lerProxInteiro(in);
            printf("> Operacao busca (%d)\n", param);
            op.tipo = Busca;
            op.param = param;
            break;
        case 2:
            // Inserção
            param = lerProxInteiro(in);
            printf("> Operacao insercao (%d)\n", param);
            op.tipo = Insercao;
            op.param = param;
            break;
        case 3:
            // Finalizar
            printf("> Operacao finalizar\n");
            op.tipo = Finalizar;
            break;
        case 9:
            // Print Auxiliar para visualização dos testes
            printf("> Operacao Print\n");
            if(fgets(buffer, BUFFSIZE, in)){
                printf("\n==== %s\n", buffer);
            }else{
                printf("Erro na leitura... Finalizando. \n");
                exit(1);
            }
            continuar = true;
            break;
        default:
            // Padrão
            printf("> Valor inválido (%d), finalizando\n", opCode);
            op.tipo = Finalizar;
            break;
        }
    }while(continuar);
    
    return op;
}