#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#define TAM 10000

clock_t start, end;
int cmp, mov, ordem;

void bubleSort(int v[]) {
	start = clock();
	
	int i, j, aux;
	cmp = 0;
	mov = 0;
	
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
	end = clock();
	
	return;
}

void selectionSort(int v[]) {
	start = clock();
	
	int i, j, max, aux;
	cmp = 0;
	mov = 0;
	
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
   	end = clock();

 	return;
}

void insertionSort(int v[]) { 
	start = clock();

    int i, j, aux;
    cmp = 0;
	mov = 0;
	
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
    end = clock();

    return;
}

void menu(int v[]) {
	printf("\nDigite o método de ordenação: \n");
	printf("\t1 - Buble Sort\n");
	printf("\t2 - Selection Sort\n");
	printf("\t3 - Insertion Sort\n");
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
			printf("\nValor inválido.\n");
	}
}

void relatorio(int v[], int t, int cmp, int mov) {
	FILE *file;
	
	printf("\tTempo de execução: %0.2lf s\n", ((double)end-start/CLOCKS_PER_SEC)/1000);
	printf("\tNúmero de comparações: %d \n", cmp);
	printf("\tNúmero de movimentações: %d \n\n", mov);
	
	file = fopen("com112_relatorio.txt", "w");
	fprintf(file, "Número de Elementos Ordenados: %d\n", TAM);
	fclose(file);
		
	bubleSort(v);
	file = fopen("com112_relatorio.txt", "a");
	fprintf(file, "\nMétodo Buble Sort\n");
	fprintf(file, "\tTempo de execução: %0.2lf s\n", ((double)end-start/CLOCKS_PER_SEC)/1000);
	fprintf(file, "\tNúmero de comparações: %d \n", cmp);
	fprintf(file, "\tNúmero de movimentações: %d \n\n", mov);
	fclose(file);
	
	selectionSort(v);
	file = fopen("com112_relatorio.txt", "a");
	fprintf(file, "Método Selection Sort\n");
	fprintf(file, "\tTempo de execução: %0.2lf s\n", ((double)end-start/CLOCKS_PER_SEC)/1000);
	fprintf(file, "\tNúmero de comparações: %d \n", cmp);
	fprintf(file, "\tNúmero de movimentações: %d \n\n", mov);
	fclose(file);
	
	insertionSort(v);
	file = fopen("com112_relatorio.txt", "a");
	fprintf(file, "Método Insertion Sort\n");
	fprintf(file, "\tTempo de execução: %0.2lf s\n", ((double)end-start/CLOCKS_PER_SEC)/1000);
	fprintf(file, "\tNúmero de comparações: %d \n", cmp);
	fprintf(file, "\tNúmero de movimentações: %d \n\n", mov);
	fclose(file);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	FILE *file;
	
	int v[TAM], i;
	
	for(i = 0; i < TAM; i++)
		v[i] = rand() % 1000;
	
	printf("Vetor Aleatório:\n");
	for(i = 0; i < TAM; i++)
		printf("%d ", v[i]);
	printf("\n");
	
	file = fopen("com112_entrada.txt", "w");
	fprintf(file, "%d\n", TAM);
	fclose(file);
	
	for(i = 0; i < TAM; i++) {
		file = fopen("com112_entrada.txt", "a");
		fprintf(file, "%d ", v[i]);
		fclose(file);
	}
	
	menu(v);

	printf("\nVetor Ordenado:\n");
	for(i = 0; i < TAM; i++)
		printf("%d ", v[i]);
	printf("\n");
	
	file = fopen("com112_saida.txt", "w");
	fprintf(file, "%d\n", TAM);
	fclose(file);
	
	for(i = 0; i < TAM; i++) {
		file = fopen("com112_saida.txt", "a");
		fprintf(file, "%d ", v[i]);
		fclose(file);
	}
	
	printf("\nNúmero de Elementos Ordenados: %d\n", TAM);	
	switch(ordem) {
		case 1:
			printf("\nMétodo Buble Sort\n");
			break;
		case 2: 
			printf("\nMétodo Selection Sort\n");
			break;
		case 3:
			printf("\nMétodo Insertion Sort\n");
			break;
	}
		
	relatorio(v, end-start, cmp, mov);
		
	return 0;
}
