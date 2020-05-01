#include <stdio.h>
#include<time.h>
#define TAM 10000

void bubleSort(int v[]) {
	int i, j, aux;
	int cmp = 0, mov = 0;
	
	for(i=0; i < TAM; i++) {
		for(j = 0; j < (TAM - 1) ; j++) {
			
			if(v[j] > v[j+1]) { 
				cmp++;
				aux = v[j];
				mov++;
				v[j] = v[j+1];
				mov++;
				v[j+1] = aux;
				mov++;
			}
		}
	}
	
    relatorio(cmp, mov);
	
	return;
}

void selectionSort(int v[]) {
	int i, j, max, aux;
	int cmp = 0, mov = 0;
	
	for (i = 0; i < (TAM - 1); i++) {
	    max = i;
	    for (j = i+1; j < TAM; j++) {
	      if (v[j] < v[max]){
	      	max = j;
	      	cmp++;
		  }
	    }
	    if (i != max) {
	      aux = v[i];
	      mov++;
	      v[i] = v[max];
	      mov++;
	      v[max] = aux;
	      mov++;
	    }
 	}
 	
    relatorio(cmp, mov);
 	
 	return;
}

void insertionSort(int v[]) { 
    int i, j, aux;
    int cmp = 0, mov = 0;
	
    for (i = 1; i < TAM; i++) { 
       	aux = v[i];
       	mov++;
        j = i - 1;
        while (j >= 0 && v[j] > aux) {
        	cmp++;
            v[j+1] = v[j];
            j--; 
            mov++;
        } 
        v[j+1] = aux;
    } 
    
    relatorio(cmp, mov);
    
    return;
}

void menu(int v[]){
	printf("\nDigite o metodo de ordenacao: \n");
	printf("1 - Buble Sort\n2 - Selection Sort\n3 - Insertion Sort\n");
	int ordem;
	scanf("%d", &ordem);
	
	switch(ordem) {
		case 1:
			bubleSort(v);
			break;
		case 2: 
			selectionSort(v);
			break;
		case 3:
			insertionSort(v);
			break;
		default:
			printf("\nValor invalido.\n");
	}
}

void relatorio(int cmp, int mov){
	//printf("\nTempo de execucao: %lf \n", t);
	printf("Numero de comparacoes entre elementos do vetor: %d \n", cmp);
	printf("Numero de movimentacoes entre elementos do vetor: %d \n\n", mov);
}

int main() {
	int v[TAM], i;
	
	clock_t t;
	t = clock();
	
	for(i = 0; i < TAM; i++)
		v[i] = rand() % 1000;
	
	printf("Vetor aleatorio:\n");
	for(i = 0; i < TAM; i++)
		printf("%d ", v[i]);
	printf("\n");
	
	bubleSort(v);
	
	printf("Vetor ordenado:\n");
	for(i = 0; i < TAM; i++)
		printf("%d ", v[i]);
	printf("\n");
	
    printf("\nTempo de execucao: %lf \n", t/CLOCKS_PER_SEC);
	return 0;
}
