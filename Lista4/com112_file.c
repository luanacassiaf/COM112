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
