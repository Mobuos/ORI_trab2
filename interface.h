#ifndef INTERFACE_H
#define INTERFACE_H

enum Operacao {Busca, Insercao, Finalizar};

// Retorna a ordem (t) requisitada
int inputOrdem();

/// Retorna a operação requisitada
enum Operacao inputOperacao();

#endif