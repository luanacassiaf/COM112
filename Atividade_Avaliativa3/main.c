#include <stdio.h>
#include "com112_hash.h"

int menu(){
  int op = 0, TABLE_SIZE, ok, mat;
  Hash* ha;
  struct aluno* al;
  al = (struct aluno*) malloc(sizeof(struct aluno));

  while(op != 5){
    printf("\nMENU:\n");
    printf("1) Criar tabela Hash\n");
    printf("2) Liberar tabela Hash\n");
    printf("3) Inserir Elemento (sem colisao)\n");
    printf("4) Consultar Elemento (sem colisao)\n");
    printf("5) Sair\n");
    printf("Escolher opcao: ");
    scanf("%d", &op);
    printf("\n");

    switch(op){
      case 1:
        printf("Digite o tamanho da tabela Hash: ");
        scanf("%d", &TABLE_SIZE);
        ha = criaHash(TABLE_SIZE);

        if(ha != NULL){
          printf("\nTabela Hash criada com sucesso!\n");
        }else{
          printf("\nTabela Hash nao foi criada!\n");
        }
        break;

      case 2:
        liberaHash(ha);
        printf("\nTabela Hash liberada!\n");
        break;

      case 3:

        printf("Digite a matricula do aluno: ");
        scanf("%d", &al->matricula);
        printf("Digite o nome do aluno: ");
        scanf("%s", &al->nome);
        printf("Digite a nota 1 do aluno: ");
        scanf("%f", &al->n1);
        printf("Digite a nota 2 do aluno: ");
        scanf("%f", &al->n2);

        ok = insereHash_SemColisao(ha, al);
        if(ok == 1){
          printf("\nElemento inserido com sucesso!\n");
        }else{
          printf("\nNao foi possivel inserir o elemento!\n");
        }
        break;

      case 4:
        printf("Digite a matricula do aluno para buscar: ");
        scanf("%d", &mat);
        ok = buscaHash_SemColisao(ha, mat, al);

        if(ok == 1){
          printf("\nElemento foi encontrado!\n");
        }else{
          printf("\nElemento nao foi encontrado!\n");
        }
        break;

      case 5:
        printf("Saindo...");
        liberaHash(ha);
        break;

      default:
        printf("Valor invalido.");
        break;
    }
  }

  free(al);
  return 0;
}


int main() {
  menu();
  return 0;
}
