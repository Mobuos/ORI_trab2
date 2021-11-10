#include <stdio.h>
#include <stdlib.h>
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

    opCode = lerProxInteiro(in);

    switch (opCode)
    {
    case 1:
        // Busca
        printf("> Operacao busca (%d)\n", opCode);
        param = lerProxInteiro(in);
        op.tipo = Busca;
        op.param = param;
        break;
    case 2:
        // Inserção
        printf("> Operacao insercao (%d)\n", opCode);
        param = lerProxInteiro(in);
        op.tipo = Insercao;
        op.param = param;
        break;
    case 3:
        // Finalizar
        printf("> Operacao finalizar (%d)\n", opCode);
        op.tipo = Finalizar;
        break;
    default:
        // Padrão
        printf("> Valor inválido (%d), finalizando\n", opCode);
        op.tipo = Finalizar;
        break;
    }
    return op;
}