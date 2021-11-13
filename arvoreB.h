#ifndef ARVOREB_H
#define ARVOREB_H

#include <stdbool.h>

// Nó da árvore B
typedef struct node{
    int n;                 // Número de chaves
    bool folha;            // Indica se o nó é folha
    //int* *chaves;
    int* chaves;          // Ponteiro de array de chaves
    //struct node** *pNodes;
    struct node* *pNodes; // Pointeiro de array de ponteiros para os nós
} Node;

// Struct principal da árvore B
typedef struct{
    int t;
    Node* raiz;
} ArvoreB;

// Aloca um nó de acordo com a ordem da árvore
/*
 * alocaNode()
 * Aloca um nó de acordo com a ordem da árvore
 * 
 * t: A ordem da árvore
 * n: O número de chaves
 * 
 * Retorna um ponteiro para o struct de nó alocado
 */
Node *alocaNode(int t, int n);

/*
 * criaArvore()
 * Cria uma nova árvore B com um nó inicial vazio
 * 
 * t: A ordem da árvore
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
 * r: O nó raiz da árvore onde será efetuada a inserção
 * t: a ordem da arvoreB
 * chave: Chave a ser inserida
 * nodeEncontrado: Ponteiro para o nó inserido
 * 
 * Retorna o índice da chave inserida, ou -1 caso tenha falhado
*/
int insereArvore(Node* r, int chave, int t, Node* nodeInserido);

/**/
void insere(Node* r, int i, int t);
/**/
void divideFilho(Node* r, int i, int t);

#endif