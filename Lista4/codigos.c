#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#define TAM 2000

int cmp, mov, ordem;
clock_t start, end;

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
	      	cmp++;
	      	max = j;
		  }
	    }
	    if (i != max) {
	    	cmp++;
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
        	cmp += 2;
            v[j+1] = v[j];
            mov++;
            j--; 
        } 
        v[j+1] = aux;
        mov++;
    } 
    end = clock();

    return;
}

void menu(int v[]) {
	printf("\nDigite o m�todo de ordena��o: \n");
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
			printf("\nValor inv�lido.\n");
	}
	
	return;
}

void relatorio() {
	printf("N�mero de Elementos Ordenados: %d\n", TAM);	
	switch(ordem) {
		case 1:
			printf("\nM�todo Buble Sort\n");
			break;
		case 2: 
			printf("\nM�todo Selection Sort\n");
			break;
		case 3:
			printf("\nM�todo Insertion Sort\n");
			break;
	}
	printf("\tTempo de execu��o: %0.2lf ms\n", (((double) end - start) / CLOCKS_PER_SEC) * 1000);
	printf("\tN�mero de compara��es: %d \n", cmp);
	printf("\tN�mero de movimenta��es: %d \n\n", mov);
		
	return;
}


void gerarEntrada(int v[]) {
	FILE *file;
	int i;
	
	file = fopen("com112_entrada.txt", "a");
	fprintf(file, "\n%d\n", TAM);
	fclose(file);
	
	for(i = 0; i < TAM; i++) {
		file = fopen("com112_entrada.txt", "a");
		fprintf(file, "%d ", v[i]);
		fclose(file);
	}
	
	return;
}

void gerarSaida(int v[]) {
	FILE *file;
	int i;
	
	file = fopen("com112_saida.txt", "a");
	fprintf(file, "\n%d\n", TAM);
	fclose(file);
	
	for(i = 0; i < TAM; i++) {
		file = fopen("com112_saida.txt", "a");
		fprintf(file, "%d ", v[i]);
		fclose(file);
	}
	
	return;
}

void gerarRelatorio() {
	FILE *file;
	
	file = fopen("com112_relatorio.txt", "a");
	fprintf(file, "N�mero de Elementos Ordenados: %d\n", TAM);
	fclose(file);
	
	switch(ordem) {
		case 1:
			file = fopen("com112_relatorio.txt", "a");
			fprintf(file, "M�todo Buble Sort\n");
			fclose(file);
			break;
		case 2: 
			file = fopen("com112_relatorio.txt", "a");
			fprintf(file, "M�todo Selection Sort\n");
			fclose(file);
			break;
		case 3:
			file = fopen("com112_relatorio.txt", "a");
			fprintf(file, "M�todo Insertion Sort\n");
			fclose(file);
			break;
	}
	
	file = fopen("com112_relatorio.txt", "a");
	fprintf(file, "\tTempo de execu��o: %0.2lf ms\n", (((double) end - start) / CLOCKS_PER_SEC) * 1000);
	fprintf(file, "\tN�mero de compara��es: %d \n", cmp);
	fprintf(file, "\tN�mero de movimenta��es: %d \n\n", mov);
	fclose(file);
	
	return;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int v[TAM], i, j;
	
	for(i = 0; i < TAM; i++){
		v[i] = rand() % 1000;
	}
	
	printf("Vetor Aleat�rio:\n");
	for(i = 0; i < TAM; i++)
		printf("%d ", v[i]);
	printf("\n");
	
	gerarEntrada(v);

	menu(v);

	printf("\nVetor Ordenado:\n");
	for(i = 0; i < TAM; i++)
		printf("%d ", v[i]);
	printf("\n");

	gerarSaida(v);
		
	relatorio();
	gerarRelatorio();
		
	return 0;
}
