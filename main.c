/*
main.c

    Daniel Kenichi Tiago Tateishi RA: 790837
    João Dini de Miranda RA: 790716
    Martim Fernandes Ribeiro Lima RA: 756187
*/
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
    // Determina se serão usados os testes automatizados
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

    // Recebe a variável t (Seja do usuário ou do arquivo de testes)
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
        printf("Erro: Falha ao criar a árvore\n");
        exit(1);
    }

    // Loop principal de operações sobre a árvore B
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
                printf("Erro: Inserção falhou\n");
            }
            else if (indice == -2)
            {
                printf("Erro: Chave já existente\n");
            }
            else
            {
                printf("Indice: %d\n", indice);
            }
            printf("Chave inserida no node de endereço 0x%04lx\n", (uintptr_t)pNodeAtual);
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
                printf("Chave encontrada no node de endereço 0x%04lx\n", (uintptr_t)pNodeAtual);
                int i;
                printf("Nos do no inserido: ");
                for(i = 0; i < pNodeAtual->n; i++){
                    printf("%d ", pNodeAtual->chaves[i]);
                }
                printf("\n");
            }
            
            break;
        case Finalizar:
            printf("Finalizando...\n");
            break;
        default:
            printf("Erro: Operacao recebida da interface inválida\n");
            return 1;
            break;
        }
    } while (op.tipo != Finalizar);

    // Fecha o arquivo de testes caso necessário
    if (teste)
    {
        fclose(inFile);
    }

    desalocaNodeR(pAB->raiz);

    return 0;
}