#ifndef ARVOREB_H
#define ARVOREB_H

#include <stdbool.h>

// Nó da árvore B
typedef struct node{
    int n;           // Número de chaves
    bool folha;      // Indica se o nó é folha
    int* *chaves;  // Ponteiro de array de chaves
    struct node** *pNodes; // Pointeiro de array de ponteiros para os nós
    //NOTA: Não sei se isso funciona, to testando em um código separado
} Node;

// Struct principal da árvore B
typedef struct{
    int t;
    Node* raiz;
} ArvoreB;

// Cria um nó inicial vazio
bool criaArvore(int t, ArvoreB* arvoreB);

// Busca na árvore pela chave, retorna o índice dela e o nó
int buscaArvore(int chave, Node* nodeEncontrado);

// Insere na árvore a chave, retorna o índice dela e o nó
int insereArvore(int chave, Node* nodeInserido);

#endif