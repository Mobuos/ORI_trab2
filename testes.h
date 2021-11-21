/*
testes.h

    Daniel Kenichi Tiago Tateishi RA: 790837
    João Dini de Miranda RA: 790716
    Martim Fernandes Ribeiro Lima RA: 756187
*/
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
 * Retorna um struct de operação de acordo com o arquivo
 * (Struct em interface.h)
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