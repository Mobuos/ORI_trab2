#include <stdlib.h>
#include "arvoreB.h"

// Aloca um nó de acordo com a ordem da árvore
Node *alocaNode(int t, int n){
    Node* node = (Node*) malloc(sizeof(Node));
    node->n = n;
    node->folha = true;
    // Aloca um vetor com a quantidade máxima de chaves que um nó pode ter
    node->chaves = (int*) malloc(sizeof(int) * (2*t-1));
    for(int i = 0; i < 2*t-1; i++)
        node->chaves[i] = -1;
    // Aloca um vetor com a quantidade máxima de filhos que um nó pode ter
    node->pNodes = (Node**) malloc(sizeof(Node*) * (2*t));
    for(int i = 0; i < 2*t; i++)
        node->pNodes[i] = NULL;

    return node;
}

// Cria um nó inicial vazio
bool criaArvore(int t, ArvoreB* *arvoreB){
    // Verifica se a árvore já foi criada (Se existe nó raiz e se t já está definido)
    if(*arvoreB != NULL){
        return false;
    }

    // Cria um nó vazio, coloca o valor de t e raiz no struct
    *arvoreB = (ArvoreB*) malloc(sizeof(ArvoreB));
    (*arvoreB)->t = t;
    (*arvoreB)->raiz = alocaNode(t,0);
    return true;
}

// Busca a árvore pelo nó, retorna o indíce e o nó encontrado por referência
int buscaArvore(Node* no, int chave, Node* nodeEncontrado){
    int i = 0;

    while(i < no->n && chave > no->chaves[i]){
        i++;
    }
    
    if(i < no->n && no->chaves[i] == chave){
        nodeEncontrado = no;
        return i;
    }else if(no->folha){
        return -1;
    }
    return buscaArvore(no->pNodes[i], chave, nodeEncontrado);
}

// Insere na árvore a chave, retorna o índice dela e o nó
int insereArvore(ArvoreB* arvoreB, int chave, Node* nodeInserido){
    if(arvoreB == NULL) 
        return -1;
    Node* r = arvoreB->raiz;

    // Árvore está cheia?
    if(r->n == 2 * arvoreB->t - 1){
        Node* aux = alocaNode(arvoreB->t, 0);
        arvoreB->raiz = aux;
        aux->folha = false;
        aux->pNodes[0] = r;

        divideFilho(aux, 0, arvoreB->t);
       return insere(aux, chave, arvoreB->t);
    }else{
       return insere(r, chave, arvoreB->t);
    }
    
    return -1;
}

// Divide o nó filho 
void divideFilho(Node* no, int i, int t){
    Node* z = alocaNode(t, 0);
    Node* y = no->pNodes[i];
    z->folha = y->folha;
    z->n = t - 1;

    for(int j = 0; j < t-1; j++) 
        z->chaves[j] = y->chaves[j + t];

    //caso de problema, analisar divisoes de nodes nao folha
    if(!y->folha){
        for (int j = 0; j < t; j++)
            z->pNodes[j] = y->pNodes[j + t];
    }

    y->n = t - 1;

    //analisar aqui tbm
    for(int j = no->n; j < i + 1; j++)
        no->pNodes[j + 1] = no->pNodes[j];
    
    no->pNodes[i + 1] = z; 

    //movendo outras chaves
    for(int j = no->n - 1; j < i; j++)
        no->chaves[j + 1] = no->chaves[j]; 
    
    no->chaves[i] = y->chaves[t - 1];
    no->n = no->n + 1;
}

// Insere um nó em uma árvore B não-cheia.
int insere(Node* r, int chave, int t){
    int i = r->n - 1;

    if(r->folha){
        while(i >= 0 && chave < r->chaves[i]){
            r->chaves[i + 1] = r->chaves[i];
            i--; 
        }
        r->chaves[i + 1] = chave;
        r->n = r->n + 1;
        return i + 1;
        //return i;
    }else{
        while(i >= 0 && chave < r->chaves[i])
            i--;
        i++;
        if(r->pNodes[i]->n == 2*t - 1){
            divideFilho(r, i, t);
            if(chave > r->chaves[i])
                i++;
        }
       return insere(r->pNodes[i], chave, t);
    }
}