#include <stdlib.h>
#include "arvoreB.h"

// Aloca um nó de acordo com a ordem da árvore
Node *alocaNode(int t, int n)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->n = n;
    node->folha = true;
    // Aloca um vetor com a quantidade máxima de chaves que um nó pode ter
    node->chaves = (int *)malloc(sizeof(int) * (2 * t - 1));
    for (int i = 0; i < 2 * t - 1; i++)
        node->chaves[i] = -1;
    // Aloca um vetor com a quantidade máxima de filhos que um nó pode ter
    node->pNodes = (Node **)malloc(sizeof(Node *) * (2 * t));
    for (int i = 0; i < 2 * t; i++)
        node->pNodes[i] = NULL;

    return node;
}

// Cria um nó inicial vazio
bool criaArvore(int t, ArvoreB **arvoreB)
{
    // Verifica se a árvore já foi criada (Se existe nó raiz e se t já está definido)
    if (*arvoreB != NULL)
    {
        return false;
    }

    // Cria um nó vazio, coloca o valor de t e raiz no struct
    *arvoreB = (ArvoreB *)malloc(sizeof(ArvoreB));
    (*arvoreB)->t = t;
    (*arvoreB)->raiz = alocaNode(t, 0);
    return true;
}

// Busca a árvore pelo nó, retorna o indíce e o nó encontrado por referência
int buscaArvore(Node *no, int chave, Node **nodeEncontrado)
{
    int i = 0;

    while (i < no->n && chave > no->chaves[i])
    {
        i++;
    }

    // Encontrou?
    if (i < no->n && no->chaves[i] == chave)
    {
        *nodeEncontrado = no;
        return i;
    }
    // Chegou no final da árvore?
    else if (no->folha)
    {
        return -1;
    }
    return buscaArvore(no->pNodes[i], chave, nodeEncontrado);
}

// Insere na árvore a chave, retorna o índice dela e o nó
int insereArvore(ArvoreB *arvoreB, int chave, Node **nodeInserido)
{
    if (arvoreB == NULL)
        return -1;

    if (buscaArvore(arvoreB->raiz, chave, nodeInserido) != -1){
        return -2;
    }
    
    Node *r = arvoreB->raiz;

    // Árvore está cheia?
    if (r->n == 2 * arvoreB->t - 1)
    {
        Node *aux = alocaNode(arvoreB->t, 0);
        arvoreB->raiz = aux;
        aux->folha = false;
        aux->pNodes[0] = r;

        divideFilho(aux, 0, arvoreB->t);
        return insere(aux, chave, arvoreB->t, nodeInserido);
    }
    else
    {
        return insere(r, chave, arvoreB->t, nodeInserido);
    }

    return -1;
}

// Divide o nó filho
void divideFilho(Node *no, int i, int t)
{
    Node *z = alocaNode(t, 0);
    Node *y = no->pNodes[i];
    z->folha = y->folha;
    z->n = t - 1;

    // Copiando as chaves para o novo nó
    for (int j = 0; j < t - 1; j++)
        z->chaves[j] = y->chaves[j + t];

    // Para nós não folha, copiar os ponteiros dos filhos de y->z
    if (!y->folha)
    {
        for (int j = 0; j < t; j++)
            z->pNodes[j] = y->pNodes[j + t];
    }

    y->n = t - 1;

    // Movendo os ponteiros de nodes
    for (int j = no->n; j >= i + 1; j--)
        no->pNodes[j + 1] = no->pNodes[j];

    no->pNodes[i + 1] = z;

    // Movendo outras chaves
    for (int j = no->n - 1; j >= i; j--)
        no->chaves[j + 1] = no->chaves[j];

    no->chaves[i] = y->chaves[t - 1];
    no->n = no->n + 1;
}

// Insere um nó em uma árvore B não-cheia.
int insere(Node *r, int chave, int t, Node **nodeInserido)
{
    int i = r->n - 1;

    // Caso Folha
    if (r->folha)
    {
        while (i >= 0 && chave < r->chaves[i])
        {
            r->chaves[i + 1] = r->chaves[i];
            i--;
        }
        r->chaves[i + 1] = chave;
        r->n = r->n + 1;
        *nodeInserido = r;
        return i + 1;
    }
    // Caso não-folha
    else
    {
        while (i >= 0 && chave < r->chaves[i])
            i--;
        i++;
        if (r->pNodes[i]->n == 2 * t - 1)
        {
            divideFilho(r, i, t);
            if (chave > r->chaves[i])
                i++;
        }
        return insere(r->pNodes[i], chave, t, nodeInserido);
    }
}

// Desaloca uma árvore-B
void desalocaNodeR(Node *node)
{
    // Se existem pNodes não nulos nesse nó, chamar desalocaAB neles
    int i;
    for(i = 0; i < node->n+1; i++){
        if(node->pNodes[i] != NULL)
        {
            desalocaNodeR(node->pNodes[i]);
        }
    }
    // Após desalocar (ou não caso não tenha o que desalocar), desalocar o próprio nó
    free(node->pNodes);
    free(node->chaves);
    free(node);
}