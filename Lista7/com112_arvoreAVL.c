// TAD para Lista Dinâmica Encadeada Circular

#include <stdio.h>
#include <stdlib.h>
#include "com112_arvoreAVL.h"


// definição do struct elemento
struct no
{
    int valor;
    struct no *esq;
    struct no *dir;
    int fator;
};

// função para alocar memória
ArvoreBin* criar_arvore()
{
    // 'raiz' é um ponteiro para ponteiro do tipo No
    ArvoreBin *raiz = (ArvoreBin*) malloc(sizeof(ArvoreBin));

    // se a alocação estiver correta 'raiz' aponta para NULL (arvore vazia)
    if(raiz != NULL)
    {
        *raiz = NULL;
    }

    return raiz;
}

// funcao para desalocar memoria de um nó da arvore
void liberar_no(No *no)
{
    if(no == NULL)
        return;

    liberar_no(no->esq);
    liberar_no(no->dir);
    free(no);
    no = NULL;
}


// função para desalocar memória da arvore
int liberar_arvore(ArvoreBin *raiz)
{
    if(raiz == NULL)
        return 0;

    liberar_no(*raiz); //libera cada no
    free(raiz); // libera a raiz

    return 1;
}

// função calcula o total de nós da arvore binaria
int quantidade_nos_arvore(ArvoreBin *raiz)
{
    // se o ponteiro for nulo ou se a arvore estiver vazio
    if(raiz == NULL || *raiz == NULL)
        return 0;

    // calcula o numero de nos na subarvore esquerda
    int total_esq = quantidade_nos_arvore(&((*raiz)->esq));

    // calcula o numero de nos na subarvore direita
    int total_dir = quantidade_nos_arvore(&((*raiz)->dir));

    // total é a quantidade de nos das subarvores mais a raiz
    return (total_esq + total_dir + 1);
}


// funcao que calcula a altura da arvore binaria
int altura_arvore(ArvoreBin *raiz)
{
    if(raiz == NULL || *raiz == NULL)
        return 0;

    // calcula a altura da subarvore esquerda
    int alt_esq = altura_arvore(&((*raiz)->esq));

    // calcula a altura da subarvore direita
    int alt_dir = altura_arvore(&((*raiz)->dir));

    // altura da arvore é a altura da maior subarvore mais a raiz
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

// funcao retorna 1 se não houver nós na arvore
int esta_vazia_arvore(ArvoreBin *raiz)
{
    if(raiz == NULL || *raiz == NULL)
        return 1;

    return 0;
}


// função para inserção de elementos em uma arvore binaria de busca
int inserir_arvore(ArvoreBin *raiz, int valor)
{
    if(raiz == NULL)
        return 0;

    // cria um nó novo
    No *novo = (No*) malloc(sizeof(No));

    // verifica se a memória foi alocada corretamente
    if(novo == NULL)
    {
        return 0;
    }

    // preenche campos do nó novo criado
    novo->valor = valor;
    novo->fator = 0;
    novo->esq = NULL;
    novo->dir = NULL;

    // se a arvore estiver vazia, raiz recebe o novo nó
    if(*raiz == NULL)
    {
        *raiz = novo;

    }
    else
    {
        No *atual = *raiz;
        No *ant = NULL;

        // percorre a arvore binaria até encontrar uma posicao nula,
        // de acordo com a ordem desejada
        while(atual != NULL)
        {

            ant = atual;

            // verifica se o valor novo já existe na árvore
            if(valor == atual->valor)
            {
                free(novo);
                return 0;
            }

            // identifica a subarvore pela qual irá percorrer
            if(valor < atual->valor)
            {
                atual = atual->esq;
                if(fator_balanceamento(atual) >= 2 || fator_balanceamento(atual) <= -2)
                {
                    if(valor < (*raiz)->esq->valor)
                    {
                        rotacaoLL(raiz);
                    }
                    else
                    {
                        rotacaoLR(raiz);
                    }
                }
            }
            else
            {
                atual = atual->dir;
                if(fator_balanceamento(atual) >= 2 || fator_balanceamento(atual) <= -2)
                {
                    if(valor > (*raiz)->dir->valor)
                    {
                        rotacaoRR(raiz);
                    }
                    else
                    {
                        rotacaoRL(raiz);
                    }
                }
            }
        }

        // verifica para qual filho atribuíra o nó novo
        if(valor < ant->valor)
        {
            ant->esq = novo;
        }
        else
        {
            ant->dir = novo;
        }
    }

    return 1;

}

// função para remoção de um nó da arvore binaria de busca
No* remover_no(No *atual)
{
    No *no1, *no2;

    // verifica se "atual" não possui filho da esquerda
    if(atual->esq == NULL)
    {
        no2 = atual->dir;
        free(atual); // libera memória do nó atual

        // retorna "no2", filho da direita, como nó substituto do nó removido
        return no2;
    }

    no1 = atual;
    no2 = atual->esq;

    // busca o nó mais a direita do nó atual, "no2"
    while(no2->dir != NULL)
    {
        no1 = no2;      // armazena o pai do "no2"
        no2 = no2->dir;
    }

    // verifica se o pai do nó mais a direita é diferente do atual, a ser removido
    if(no1 != atual)
    {
        // subarvore da esquerda do "no2" se torna a subarvore da direita do "no1"
        no1->dir = no2->esq;

        // subarvore da esquerda do "atual" se torna a subarvore da esquerda do "no2"
        no2->esq = atual->esq;
    }

    // subarvore da direita do "atual" se torna a subarvore da direita do "no2"
    no2->dir = atual->dir;

    free(atual); // libera memória do nó atual

    // retorna "no2" como nó substituto do nó removido
    return no2;
}

// função para remoção de elementos de uma arvore binaria de busca
int remover_arvore(ArvoreBin *raiz, int valor)
{
    if(raiz == NULL)
        return 0;

    No *ant = NULL;    // nó pai do nó atual
    No *atual = *raiz; // nó atual

    // percorre a arvore binaria até encontrar o nó a ser removido
    while(atual != NULL)
    {

        // verifica se o valor buscado foi encontrado
        if(valor == atual->valor)
        {

            // verifica se o nó a ser removido é a raiz da árvore
            if(atual == *raiz)
            {
                *raiz = remover_no(atual); // remove o nó e atualiza a arvore

            }
            else
            {

                if(ant->dir == atual)
                {
                    ant->dir = remover_no(atual); // remove o nó e atualiza a arvore
                }
                else
                {
                    ant->esq = remover_no(atual); // remove o nó e atualiza a arvore
                }

            }

            if(fator_balanceamento(raiz) >= 2)
            {
                if(altura_arvore((*raiz)->esq->dir) <= altura_arvore((*raiz)->esq->esq))
                {
                    rotacaoLL(raiz);
                }
                else
                {
                    rotacaoLR(raiz);
                }
            }
            else if(fator_balanceamento(raiz) <= -2)
            {
                if(altura_arvore((*raiz)->dir->esq) <= altura_arvore((*raiz)->dir->dir))
                {
                    rotacaoRR(raiz);
                }
                else
                {
                    rotacaoRL(raiz);
                }
            }
            // nó a ser removido foi encontrado e removido corretamente
            return 1;
        }

        // se o nó atual não é o nó procurado
        // "ant" recebe "atual" e "atual" recebe um de seus filhos
        ant = atual;

        // verifica em qual subarvore o valor procurado pode estar
        // e atualiza o nó atual para o filho da direita ou da esquerda
        if(valor > atual->valor)
        {
            atual = atual->dir;
        }
        else
        {
            atual = atual->esq;
        }

    }

    // nó a ser removido não existe na árvore
    return 0;
}

// função para buscar elementos na arvore binaria
int consultar_arvore(ArvoreBin *raiz, int valor)
{
    if(raiz == NULL)
        return 0;

    No *atual = *raiz;

    // percorre a arvore binaria até encontrar o valor desejado
    while(atual != NULL)
    {

        // retorna 1 quando encontra o valor
        if(valor == atual->valor)
        {
            return 1;
        }

        // identifica a subarvore pela qual irá percorrer
        if(valor < atual->valor)
        {
            atual = atual->esq;
        }
        else
        {
            atual = atual->dir;
        }
    }

    return 0;
}

// função para percorrer a arvore binaria em ordem
void percorrer_em_ordem_arvore(ArvoreBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        percorrer_em_ordem_arvore(&((*raiz)->esq));
        printf("%d\n", (*raiz)->valor);
        percorrer_em_ordem_arvore(&((*raiz)->dir));
    }
}

// função para percorrer a arvore binaria em pré ordem
void percorrer_pre_ordem_arvore(ArvoreBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        printf("%d\n", (*raiz)->valor);
        percorrer_pre_ordem_arvore(&((*raiz)->esq));
        percorrer_pre_ordem_arvore(&((*raiz)->dir));
    }
}

// função para percorrer a arvore binaria em pós ordem
void percorrer_pos_ordem_arvore(ArvoreBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        percorrer_pos_ordem_arvore(&((*raiz)->esq));
        percorrer_pos_ordem_arvore(&((*raiz)->dir));
        printf("%d\n", (*raiz)->valor);
    }
}

int fator_balanceamento(ArvoreBin *no)
{

    int h_esq, h_dir;
    if((*no)->esq == NULL)
    {
        h_esq = 0;
    }
    else
    {
        h_esq = altura_arvore((*no)->esq);
    }

    if((*no)->dir == NULL)
    {
        h_dir = 0;
    }
    else
    {
        h_dir = altura_arvore((*no)->dir);
    }

    (*no)->fator = h_dir - h_esq;

    return (*no)->fator;
}

int maiorElemento(ArvoreBin *no1, ArvoreBin *no2)
{
    if((*no1)->valor > (*no2)->valor)
    {
        return 1;
    }
    else if((*no1)->valor < (*no2)->valor)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void rotacaoLL(ArvoreBin *raiz)
{
    No *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->fator = fator_balanceamento(raiz);
    no->fator = fator_balanceamento(no);
    *raiz = no;
}

void rotacaoRR(ArvoreBin *raiz)
{
    No *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->fator = fator_balanceamento(raiz);
    no->fator = fator_balanceamento(no);
    *raiz = no;
}

void rotacaoLR(ArvoreBin *raiz)
{
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(ArvoreBin *raiz)
{
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}
