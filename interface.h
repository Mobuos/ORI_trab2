#ifndef INTERFACE_H
#define INTERFACE_H

// Enum utilizado para representar as operações
enum Operacao {Busca, Insercao, Finalizar};

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
enum Operacao inputOperacao();

#endif