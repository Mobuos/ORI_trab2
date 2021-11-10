#ifndef INTERFACE_H
#define INTERFACE_H

// Enum utilizado para representar as operações
enum TipoOperacao {Busca, Insercao, Finalizar};

// Struct de retorno para input de operações, inclue o tipo e um parâmetro
struct Operacao{
    enum TipoOperacao tipo; // Tipo da operação
    int param; // A chave na qual executar a operação
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
 * Retorna um struct de operação de acordo com os valores requisitados
 */
struct Operacao inputOperacao();

#endif