#include <stdio.h>
#include <stdlib.h>
#include "testes.h"
#include "interface.h"

#define BUFFSIZE 128

//TODO Verificações aqui

// Retorna a ordem (t) requisitada
int autoInOrdem(FILE *in){
    printf("testes: Lendo ordem do arquivo...\n");

    char buffer[BUFFSIZE];
    int t = -1;
    if(fgets(buffer, BUFFSIZE, in)){
        // Nota: atoi não é a melhor função do mundo para isso, mas assumo que não terão erros de input nos casos teste.
        t = atoi(buffer);
    }else{
        printf("Erro na leitura... Finalizando. \n");
        exit(1);
    }

    printf("testes: ordem = %d\n", t);
    return t;
}

// Retorna a operação requisitada
enum Operacao autoInOperacao(FILE *in){
    printf("testes: Lendo operacao...\n");

    char buffer[BUFFSIZE];
    int op = 0;
    
    if(fgets(buffer, BUFFSIZE, in)){
        op = atoi(buffer);
    }else{
        printf("Erro na leitura... Finalizando. \n");
        exit(1);
    }

    switch (op)
    {
    case 1:
        printf("testes: Operacao busca (%d)\n", op);
        return Busca;
        break;
    case 2:
         printf("testes: Operacao insercao (%d)\n", op);
        return Insercao;
        break;
    case 3:
        printf("testes: Operacao finalizar (%d)\n", op);
        return Finalizar;
        break;
    default:
        printf("testes: Valor inválido (%d), finalizando\n", op);
        return Finalizar;
        break;
    }
}