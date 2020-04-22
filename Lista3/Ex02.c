#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TAM 10

typedef struct{
	char nome[200];
	double salario;
} Funcionario;
Funcionario func[TAM];


void ordenarSalarios(Funcionario func[]){
	int i, j, max, aux;
	char auxN[200];
	
	for (i = 0; i < (TAM - 1); i++) {
	    max = i;
	    for (j = i+1; j < TAM; j++) {
	      if (func[j].salario > func[max].salario)
	  		max = j;
	    }
	   
	    if (i != max) {
	      aux = func[i].salario;
	      strcpy(auxN, func[i].nome);
	      
	      func[i].salario = func[max].salario;
	      strcpy(func[i].nome, func[max].nome);
	      
	      func[max].salario = aux;
	      strcpy(func[max].nome, auxN);
	    }
 	}
 	return;
}

void ordenarNomes(Funcionario func[]) {
	int i, j, max, aux;
	char auxN[200];
	
	for (i = 0; i < (TAM - 1); i++) {
	    max = i;
	    for (j = i+1; j < TAM; j++) {
	      if (strcmp(func[j].nome, func[max].nome) < 0)
	  		max = j;
	    }
	   
	    if (i != max) {
	      strcpy(auxN, func[i].nome);
	      aux = func[i].salario;
	      
	      strcpy(func[i].nome, func[max].nome);
	      func[i].salario = func[max].salario;
	      
	      strcpy(func[max].nome, auxN);
	      func[max].salario = aux;
	    }
	}
	
	return;
}

int main() {
	int i;
	char n[TAM][200];
	
	for(i=0; i<TAM; i++) {
		printf("Funcionario %d\n", i+1);
		printf("Digite o nome: ");
		gets(func[i].nome);
		getchar();
		
		printf("Digite o salario: ");
		scanf("%lf", &func[i].salario);
		fflush(stdin);
		
		printf("\n");
	}
	
    ordenarSalarios(func);
	
	printf("Ordem Decrescente de Salario: \n");
	for(i=0; i<TAM; i++)
		printf("%s %0.2lf \n", func[i].nome, func[i].salario);
	printf("\n");
	
	ordenarNomes(func);
	
	printf("Ordem Alfabetica: \n");
	for(i=0; i<TAM; i++)
		printf("%s %0.2lf \n", func[i].nome, func[i].salario);
	printf("\n");
	
	return 0;
}
