// bibliotecas do sistema
#include <stdio.h>

// bibliotecas do projeto
#include "com112_arvoreAVL.h"

// funcao principal
int main(void)
{
    ArvoreBin *raiz;
    int opcao, valor, ok, pos;


    // menu de opções para execuções de operações sobre a lista
    do
    {
        printf("\n\nMenu de opçoes");
        printf("\n1 - Criar arvore");
        printf("\n2 - Liberar arvore");
        printf("\n3 - Inserir elemento");
        printf("\n4 - Remover elemento");
        printf("\n5 - Consultar elemento");
        printf("\n6 - Imprimir percurso pré-ordem");
        printf("\n7 - Imprimir percurso em-ordem");
        printf("\n8 - Imprimir percurso pós-ordem");
        printf("\n9 - Altura da arvore");
        printf("\n10 - Total de elementos");
        printf("\n11 - Sair");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:

            // criar arvore binaria
            raiz = criar_arvore();

            if(raiz != NULL)
            {
                printf("\n Arvore criada com sucesso!");
            }
            else
            {
                printf("\n Arvore nao criada!");
            }
            break;


        case 2:

            // liberar arvore binaria
            ok = liberar_arvore(raiz);

            if(ok)
            {
                printf("\n Arvore liberada com sucesso!");
            }
            else
            {
                printf("\n Arvore nao liberada!");
            }
            break;

        case 3:

            // inserir nó na árvore binária
            printf("\n Valor a ser inserido: ");
            scanf("%d", &valor);

            ok = inserir_arvore(raiz, valor);

            if(ok == 1)
            {
                printf("\n Inserçao realizada com sucesso!");
            }
            else
            {
                printf("\n Falha na inserçao!");
            }

            break;

        case 4:

            // remover nó com determinado valor
            printf("\n Valor a ser removido: ");
            scanf("%d", &valor);

            ok = remover_arvore(raiz, valor);

            if(ok == 1)
            {
                printf("\n Remocao realizada com sucesso!");
            }
            else
            {
                printf("\n Falha na remocao!");
            }

            break;

        case 5:

            // busca elemento pelo valor
            printf("\n Valor a ser buscado: ");
            scanf("%d", &valor);

            ok = consultar_arvore(raiz, valor);

            if(ok == 1)
            {
                printf("\n Busca realizada com sucesso!");
            }
            else
            {
                printf("\n Valor nao encontrado na arvore!");
            }


            break;

        case 6:
            // imprime percurso pré-ordem
            percorrer_pre_ordem_arvore(raiz);
            break;

        case 7:
            // imprime percurso em-ordem
            percorrer_em_ordem_arvore(raiz);
            break;

        case 8:
            // imprime percurso pós-ordem
            percorrer_pos_ordem_arvore(raiz);
            break;


        case 9:
            // imprime a altura da árvore binária
            printf("%d\n", altura_arvore(raiz));
            break;

            break;

        case 10:
            // imprime o número total de nós na árvore binária
            printf("%d\n", quantidade_nos_arvore(raiz));
            break;

        case 11:

            // libera memória e finaliza programa
            liberar_arvore(raiz);
            printf("\nFinalizando...");
            break;

        default:
            printf("\nOpcao invalida!");
            break;
        }

    }
    while(opcao != 11);

    return 0;
}
