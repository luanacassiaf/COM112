#ifndef COM112_ARVOREAVL_H_INCLUDED
#define COM112_ARVOREAVL_H_INCLUDED

// TAD para Árvore Dinâmica Encadeada

//#ifndef _ARVORE_AVL
//#define _ARVORE_AVL

// definição de tipos abstratos
typedef struct no No;
typedef No* ArvoreBin;

// funções para alocar e desalocar memória
ArvoreBin* criar_arvore();
int liberar_arvore(ArvoreBin *raiz);

// funções para obter informações da arvore binaria
int quantidade_nos_arvore(ArvoreBin *raiz);
int altura_arvore(ArvoreBin *raiz);
int esta_vazia_arvore(ArvoreBin *raiz);

// função para inserção de elementos da arvore binaria
int inserir_arvore(ArvoreBin *raiz, int valor);

// função para remoção de elementos da arvore binaria
int remover_arvore(ArvoreBin *raiz, int valor);

// função para buscar elementos na arvore binaria
int consultar_arvore(ArvoreBin *raiz, int valor);

// funções para percorrer a arvore binaria
void percorrer_em_ordem_arvore(ArvoreBin *raiz);
void percorrer_pre_ordem_arvore(ArvoreBin *raiz);
void percorrer_pos_ordem_arvore(ArvoreBin *raiz);

int fator_balanceamento(ArvoreBin *no);

int maiorElemento(ArvoreBin *no1, ArvoreBin *no2);

void rotacaoLL(ArvoreBin *raiz);
void rotacaoRR(ArvoreBin *raiz);
void rotacaoLR(ArvoreBin *raiz);
void rotacaoRL(ArvoreBin *raiz);

//#endif

#endif // COM112_ARVOREAVL_H_INCLUDED
