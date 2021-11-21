/*
interface.c

    Daniel Kenichi Tiago Tateishi RA: 790837
    João Dini de Miranda RA: 790716
    Martim Fernandes Ribeiro Lima RA: 756187
*/
#include "interface.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFSIZE 1024

// Lê um inteiro positivo, usa uma mensagem de erro para tentar novamente
int lerNatural(char msgErro[])
{
    int valor;
    char buffer[BUFFSIZE];
    int sucesso; // Flag para conversão bem-sucedida

    do
    {
        if (!fgets(buffer, BUFFSIZE, stdin))
        {
            exit(1); // Falha na leitura
        }

        // Convertendo para int
        char *endptr;

        errno = 0; // Reseta errno
        valor = (int)strtol(buffer, &endptr, 10);
        if (errno == ERANGE)
        {
            // Número muito pequeno/grande
            printf("%s", msgErro);
            sucesso = 0;
        }
        else if (endptr == buffer)
        {
            // Nada foi lido
            printf("%s", msgErro);
            sucesso = 0;
        }
        else if (*endptr && *endptr != '\n')
        {
            // *endptr não é nem o final da string nem uma nova linha,
            // então não convertemos todo o input
            printf("%s", msgErro);
            sucesso = 0;
        }
        else if (*endptr == '\0')
        {
            printf("Erro: Buffer inapropriado");
            exit(1);
        }
        else
        {
            if (valor >= 0)
            {
                sucesso = 1;
            }
            else
            {
                sucesso = 0;
            }
        }
    } while (!sucesso); // Repetir até obter um número apropriado

    return valor;
}

// Retorna a ordem (t) requisitada
int inputOrdem()
{
    printf("Ordem: ");
    int t = lerNatural("Por favor digite um valor válido: ");
    return t;
}

// Retorna um struct da operação requisitada
struct Operacao inputOperacao()
{
    int opCode = 0;
    int param = -1;
    struct Operacao op;

    int sucesso;
    do
    {
        sucesso = 1;
        printf("=== Digite a operação requisitada ===\n (1) - Busca\n (2) - Insercao\n (3) - Sair\n");
        opCode = lerNatural("Número inválido, tente novamente: ");

        switch (opCode)
        {
        case 1:
            // Busca
            printf("Digite a chave a ser buscada: ");
            param = lerNatural("Digite uma chave válida: ");
            op.tipo = Busca;
            op.param = param;
            break;
        case 2:
            // Inserção
            printf("Digite a chave a ser inserida: ");
            param = lerNatural("Digite uma chave válida: ");
            op.tipo = Insercao;
            op.param = param;
            break;
        case 3:
            // Finalizar
            op.tipo = Finalizar;
            break;
        default:
            // Operação inválida
            printf("Operação inválida\n");
            sucesso = 0;
            break;
        }
    } while (!sucesso);

    return op;
}