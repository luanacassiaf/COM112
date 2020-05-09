#include "com112_sort.h"
#include "com112_file.h"

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
	printf("\nN�mero de Elementos Ordenados: %d\n", TAM);	
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
