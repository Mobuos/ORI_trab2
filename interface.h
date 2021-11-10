#ifndef INTERFACE_H
#define INTERFACE_H

// Enum utilizado para representar as operações
enum TipoOperacao {Busca, Insercao, Finalizar};

// Struct de retorno para input de operações, inclue o tipo e um parâmetro
struct Operacao{
    enum TipoOperacao tipo;
    int param;
};

/*
 * inputOrdem()
 * Adquire a ordem da árvore (t)
 * 
 * Retorna a ordem de árvore requisitada pelo usuário
 */
int inputOrdem();

/*
 * inputOperacao()
 * Adquire a operação a ser feita na árvore
 * 
 * Retorna a operação requisitada pelo usuário, correspondendo
 *  a um enum.
 */
struct Operacao inputOperacao();

#endif