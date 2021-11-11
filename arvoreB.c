#include <stdlib.h>
#include "arvoreB.h"

// Aloca um nó de acordo com a ordem da árvore
Node *alocaNode(int t, int n){
    Node* node = malloc(sizeof(Node*));
    node->n = n;
    node->folha = true;
    // Aloca um vetor com a quantidade máxima de chaves que um nó pode ter
    node->chaves = malloc(sizeof(int*) * (2*t-1));
    // Aloca um vetor com a quantidade máxima de filhos que um nó pode ter
    node->pNodes = malloc(sizeof(Node**) * (2*t));

    return node;
}

// Cria um nó inicial vazio
bool criaArvore(int t, ArvoreB* arvoreB){
    // Verifica se a árvore já foi criada (Se existe nó raiz e se t já está definido)
    if(arvoreB != NULL){
        return false;
    }

    // Cria um nó vazio, coloca o valor de t e raiz no struct
    arvoreB = malloc(sizeof(ArvoreB*));
    arvoreB->t = t;
    arvoreB->raiz = alocaNode(t,0);
    return true;
}

// Busca a árvore pelo nó, retorna o indíce e o nó encontrado por referência
int buscaArvore(ArvoreB* arvoreB, int chave, Node* nodeEncontrado){
    return -1;
}

// Insere na árvore a chave, retorna o índice dela e o nó
int insereArvore(ArvoreB* arvoreB, int chave, Node* nodeInserido){
    return -1;
}