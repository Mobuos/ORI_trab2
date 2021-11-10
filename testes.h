#ifndef TESTES_H
#define TESTES_H

#include "interface.h" //enum
#define BUFFSIZE 128

/*
 * autoInOrdem()
 * Obtém a ordem para a árvore B
 * 
 * Retorna a ordem especificada no arquivo de testes
 */
int autoInOrdem(FILE *in);

/*
 * autoInOperacao()
 * Obtém a próxima operação para a árvore B
 *
 * Retorna a operação especificada no arquivo de testes
 */
struct Operacao autoInOperacao(FILE *in);

/*
 * lerProxInteiro()
 * Lê o primeiro inteiro da próxima linha de um arquivo
 * 
 * in: Arquivo de onde será lido o inteiro
 * 
 * Retorna o inteiro lido do arquivo
 */
int lerProxInteiro(FILE *in);

#endif