#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "testes.h"
#include "interface.h"


//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
//Reset
#define reset "\e[0m"

// Lê um inteiro do arquivo
int lerProxInteiro(FILE *in)
{
    int i;
    char buffer[BUFFSIZE];
    if (fgets(buffer, BUFFSIZE, in))
    {
        // Nota: atoi não é a melhor função do mundo para isso, mas assumo que não terão erros de input nos casos teste.
        i = atoi(buffer);
        return i;
    }
    else
    {
        printf("Erro na leitura... Finalizando. \n");
        exit(1);
    }
}

// Retorna a ordem (t) requisitada
int autoInOrdem(FILE *in)
{
    printf("> Lendo ordem do arquivo...\n");

    int t = -1;
    t = lerProxInteiro(in);

    printf("> ordem = %d\n", t);
    return t;
}

// Retorna a operação requisitada
struct Operacao autoInOperacao(FILE *in)
{
    printf("> Lendo operacao...\n");
    int opCode = 0;
    int param = -1;
    struct Operacao op;

    bool continuar = false;
    char buffer[BUFFSIZE];

    // Loop para possibilitar a impressão na tela sem retornar uma operação
    do
    {
        continuar = false;

        opCode = lerProxInteiro(in);
        switch (opCode)
        {
        case 1:
            // Busca
            param = lerProxInteiro(in);
            printf(CYN "> Operacao busca (%d)\n" reset, param);
            op.tipo = Busca;
            op.param = param;
            break;
        case 2:
            // Inserção
            param = lerProxInteiro(in);
            printf(CYN "> Operacao insercao (%d)\n" reset, param);
            op.tipo = Insercao;
            op.param = param;
            break;
        case 3:
            // Finalizar
            printf(CYN "> Operacao finalizar\n" reset);
            op.tipo = Finalizar;
            break;
        case 9:
            // Print Auxiliar para visualização dos testes
            printf(CYN "> Operacao Print\n" reset);
            if (fgets(buffer, BUFFSIZE, in))
            {
                printf("\n==== %s\n", buffer);
            }
            else
            {
                printf("Erro na leitura... Finalizando. \n");
                exit(1);
            }
            continuar = true;
            break;
        default:
            // Padrão
            printf(CYN "> Valor inválido (%d), finalizando\n" reset, opCode);
            op.tipo = Finalizar;
            break;
        }
    } while (continuar);

    return op;
}