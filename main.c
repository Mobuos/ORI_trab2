#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <stdint.h>
#include "interface.h"
#include "testes.h"
#include "arvoreB.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    // Determina se ser�o usados os testes automatizados
    bool teste;
    teste = false;
    FILE *inFile;
    if (argc == 2)
    {
        teste = true;

        // Abre arquivo
        inFile = fopen(argv[1], "r");
        if (inFile == NULL)
        {
            printf("Erro: Falha na abertura do arquivo\n");
            exit(1);
        }
    }

    // Recebe a vari�vel t (Seja do usu�rio ou do arquivo de testes)
    int t;
    if (teste)
    {
        t = autoInOrdem(inFile);
    }
    else
    {
        t = inputOrdem(inFile);
    }

    ArvoreB *pAB = NULL;
    if (!criaArvore(t, &pAB))
    {
        printf("Erro: Falha ao criar a �rvore\n");
        exit(1);
    }

    // Loop principal de opera��es sobre a �rvore B
    struct Operacao op = {Finalizar, -1};
    Node *pNodeAtual = NULL;
    int indice;
    do
    {
        if (teste)
        {
            op = autoInOperacao(inFile);
        }
        else
        {
            op = inputOperacao();
        }
        switch (op.tipo)
        {
        case Insercao:
            indice = insereArvore(pAB, op.param, &pNodeAtual);
            if(indice == -1)
            {
                printf("Erro: Inser��o falhou\n");
            }
            else if (indice == -2)
            {
                printf("Erro: Chave j� existente\n");
            }
            else
            {
                printf("Indice: %d\n", indice);
            }
            printf("Chave inserida no node de endere�o 0x%04lx\n", (uintptr_t)pNodeAtual);
            break;
        case Busca:
            indice = buscaArvore(pAB->raiz, op.param, &pNodeAtual);
            if (indice == -1)
            {
                printf("CHAVE NAO ENCONTRADA!\n");
            }
            else
            {
                printf("Indice: %d\n", indice);
                printf("Chave encontrada no node de endere�o 0x%04lx\n", (uintptr_t)pNodeAtual);
            }
            
            break;
        case Finalizar:
            printf("Finalizando...\n");
            break;
        default:
            printf("Erro: Operacao recebida da interface inv�lida\n");
            return 1;
            break;
        }
    } while (op.tipo != Finalizar);

    // Fecha o arquivo de testes caso necess�rio
    if (teste)
    {
        fclose(inFile);
    }

    desalocaNodeR(pAB->raiz);

    return 0;
}