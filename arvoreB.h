#ifndef ARVOREB_H
#define ARVOREB_H

#include <stdbool.h>

// Nó da árvore B
typedef struct node
{
    int n;                // Número de chaves
    bool folha;           // Indica se o nó é folha
    int *chaves;          // Ponteiro / array de chaves
    struct node **pNodes; // Pointeiro / array de ponteiros para os nós
} Node;

// Struct principal da árvore B
typedef struct
{
    int t;
    Node *raiz;
} ArvoreB;

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
 * arvoreB: Referência do ponteiro a ser alocado (ArvoreB)
 * 
 * Retorna um bool indicando se a operação teve sucesso
 */
bool criaArvore(int t, ArvoreB **arvoreB);

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
int buscaArvore(Node *no, int chave, Node *nodeEncontrado);

/*
 * insereArvore()
 * Insere na árvore
 * 
 * arvoreB: A árvore onde será inserido o nó
 * chave: Chave a ser inserida
 * nodeEncontrado: Ponteiro para o nó inserido
 * 
 * Retorna o índice da chave inserida, ou -1 caso tenha falhado
 */
int insereArvore(ArvoreB *arvoreB, int chave, Node *nodeInserido);

/*
 * insere()
 * Insere na arvoreB nao cheia
 *
 * r: o no raiz da arvore/subarvore
 * i: indice
 * t: a ordem da arvoreB
 * 
 * Retorna o indice da chave inserida
 */
int insere(Node *r, int i, int t);

/*
 * divideFilho()
 * divide um no caso ele esteja cheio
 *
 * r: o no a ser divido
 * i: indice 
 * t: ordem da arvoreB
 */
void divideFilho(Node *r, int i, int t);

#endif