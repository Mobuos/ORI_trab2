#ifndef ARVOREB_H
#define ARVOREB_H

#include <stdbool.h>

typedef struct node{
    int n;           // Número de chaves
    bool folha;      // Indica se o nó é folha
    int* *chaves;  // Ponteiro de array de chaves
    struct node** *pNodes; // Pointeiro de array de ponteiros para os nós
    //NOTA: Não sei se isso funciona, to testando em um código separado
} Node;

typedef struct{
    int t;
    Node* raiz;
} ArvoreB;

bool criaArvore();

int buscaArvore(int chave, Node* nodeEncontrado);

int insereArvore(int chave, Node* nodeInserido);

#endif