/*
interface.h

    Daniel Kenichi Tiago Tateishi RA: 790837
    João Dini de Miranda RA: 790716
    Martim Fernandes Ribeiro Lima RA: 756187
*/
#ifndef INTERFACE_H
#define INTERFACE_H
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Enum utilizado para representar as operações
enum TipoOperacao
{
    Busca,
    Insercao,
    Finalizar
};

// Struct de retorno para input de operações, inclue o tipo e um parâmetro
struct Operacao
{
    enum TipoOperacao tipo; // Tipo da operação
    int param;              // A chave na qual executar a operação
};

/*
 * lerInteiro()
 * Lê um número positivo e inteiro (Natural) da entrada padrão
 * 
 * msgErro: Mensagem apresentada ao usuário caso a entrada não seja válida
 * - Exemplo: "Entrada inválida, tente novamente"
 * 
 * Retorna o número lido.
 * (Fonte: http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html)
 */
int lerInteiro(char msgErro[]);

/*
 * inputOrdem()
 * Adquire a ordem da árvore (t), seguindo o requerimento de t>=2
 * 
 * Retorna a ordem de árvore requisitada pelo usuário
 */
int inputOrdem();

/*
 * inputOperacao()
 * Adquire a operação a ser feita na árvore
 * 
 * Retorna um struct de operação de acordo com os valores requisitados
 */
struct Operacao inputOperacao();

#endif