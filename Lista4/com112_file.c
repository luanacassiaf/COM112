#include "com112_file.h"
#include "com112_sort.h"

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
	fprintf(file, "Número de Elementos Ordenados: %d\n", TAM);
	fclose(file);
	
	switch(ordem) {
		case 1:
			file = fopen("com112_relatorio.txt", "a");
			fprintf(file, "Método Buble Sort\n");
			fclose(file);
			break;
		case 2: 
			file = fopen("com112_relatorio.txt", "a");
			fprintf(file, "Método Selection Sort\n");
			fclose(file);
			break;
		case 3:
			file = fopen("com112_relatorio.txt", "a");
			fprintf(file, "Método Insertion Sort\n");
			fclose(file);
			break;
	}
	
	file = fopen("com112_relatorio.txt", "a");
	fprintf(file, "\tTempo de execução: %0.2lf ms\n", (((double) end - start) / CLOCKS_PER_SEC) * 1000);
	fprintf(file, "\tNúmero de comparações: %d \n", cmp);
	fprintf(file, "\tNúmero de movimentações: %d \n\n", mov);
	fclose(file);
	
	return;
}
