#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TAM 10
  
typedef struct{
	int codigo;
	char descricao[200];
	double preco;
}Produto;
Produto prod[TAM];  
  
void insertionSort(Produto prod[]) 
{ 
    int i, j, auxCod, auxP;
	char key[200];
	
    for (i = 1; i < TAM; i++) { 
        strcpy(key, prod[i].descricao);
        auxCod = prod[i].codigo;
        auxP = prod[i].preco;
        j = i - 1;
  
        while (j >= 0 && strcmp(prod[j].descricao, key) > 0) { 
            strcpy(prod[j+1].descricao, prod[j].descricao);
            prod[j+1].codigo = prod[j].codigo;
       		prod[j+1].preco = prod[j].preco;
            j--; 
        } 
        strcpy(prod[j+1].descricao, key);
        prod[j+1].codigo = auxCod;
       	prod[j+1].preco = auxP;
    } 
} 

int main() {
	int i;
	
	for(i=0; i<TAM; i++){
		printf("Produto %d \n", i+1);

		printf("Digite o codigo: ");
		scanf("%d", &prod[i].codigo);
		fflush(stdin);
		
		printf("Digite a descricao: ");
		gets(prod[i].descricao);
		getchar();
		
		printf("Digite o preco: ");
		scanf("%lf", &prod[i].preco);
		fflush(stdin);
		
		printf("\n");
	}
		
	insertionSort(prod);
	
	printf("Ordem Alfabetica: \n");
	for(i=0; i<TAM; i++)
		printf("%d %s %0.2lf \n", prod[i].codigo, prod[i].descricao, prod[i].preco);
	printf("\n");
		
	int x, cont = 0;
	printf("Digite o codigo do produto a ser buscado: ");
	scanf("%d", &x);
	for(i=0; i<TAM; i++) {
		if(x != prod[i].codigo) {
			cont++;
		}else{
			cont++;
			printf("Produto encontrado apos %d comparacoes.\n", cont);
			break;
		}
	}
	
	if(cont == TAM) 
		printf("%d comparacoes ocorreram, mas o produto nao foi encontrado.\n", cont);
	
	return 0;
}
