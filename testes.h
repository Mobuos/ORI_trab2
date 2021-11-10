#ifndef TESTES_H
#define TESTES_H

#include "interface.h" //enum

/*
 * autoInOrdem()
 * Obtém a ordem para a árvore B
 * 
 * Retorna a ordem especificada no arquivo de testes
 */
int autoInOrdem();

/*
 * autoInOperacao()
 * Obtém a próxima operação para a árvore B
 *
 * Retorna a operação especificada no arquivo de testes
 */
enum Operacao autoInOperacao();

#endif