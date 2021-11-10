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

/*
 * criaArvore()
 * Cria uma nova árvore B com um nó inicial vazio
 * 
 * t: O grau da árvore
 * arvoreB: Um ponteiro no qual a árvore será alocada
 * 
 * Retorna um bool indicando se a operação teve sucesso
 */
bool criaArvore(int t, ArvoreB* arvoreB);

/*
 * buscaArvore()
 * Busca na árvore pela chave
 * 
 * arvoreB: O nó raiz da árvore onde será efetuada a busca
 * chave: Chave a ser procurada
 * nodeEncontrado: Ponteiro para o nó encontrado
 * 
 * Retorna o índice da chave encontrada, ou -1 caso tenha falhado
*/
int buscaArvore(ArvoreB* arvoreB, int chave, Node* nodeEncontrado);

/*
 * insereArvore()
 * Insere na árvore
 * 
 * arvoreB: O nó raiz da árvore onde será efetuada a inserção
 * chave: Chave a ser inserida
 * nodeEncontrado: Ponteiro para o nó inserido
 * 
 * Retorna o índice da chave inserida, ou -1 caso tenha falhado
*/
int insereArvore(ArvoreB* arvoreB, int chave, Node* nodeInserido);

#endif