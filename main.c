#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "interface.h"
#include "testes.h"
#include "arvoreB.h"

int main(int argc, char *argv[])
{
    // Determina se serão usados os testes automatizados
    bool teste;
    teste = false;
    FILE *inFile;
    if(argc == 2){
        teste = true;
        
        // Abre arquivo
        inFile = fopen(argv[1], "r");
        if(inFile == NULL){
            printf("Erro: Falha na abertura do arquivo\n");
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
    ArvoreB* pRaizAB = NULL;
    //printf("main: Criar arvore de ordem %d\n", t);
    criaArvore(t, pRaizAB);
    
    // Loop principal de operações sobre a árvore B
    struct Operacao op = {Finalizar, -1};
    Node* pNodeAtual = NULL;
    int indice;
    do{
        if(teste){
            op = autoInOperacao(inFile);
        }else{
            op = inputOperacao();
        }
        switch (op.tipo)
        {
        case Insercao:
            //printf("main: Insercao de %d\n", op.param);
            indice = insereArvore(pRaizAB, op.param, pNodeAtual);
            indice != -1 ? printf("Indice: %d\n", indice) : printf("Erro: Insercao falhou\n");
            break;
        case Busca:
            //printf("main: Busca de %d\n", op.param);
            indice = buscaArvore(pRaizAB, op.param, pNodeAtual);
            indice != -1 ? printf("Indice: %d\n", indice) : printf("CHAVE NAO ENCONTRADA!\n");
            break;
        case Finalizar:
            printf("Finalizando...\n");
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