#include <stdio.h>
#define TAM 10

void bubleSort(int v[]) {
	int i, j, aux;
	
	for(i=0; i<TAM; i++) {
		for(j=0; j<TAM-1; j++) {
			if(v[j] < v[j+1]) {
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
	return;
}

int main() {
	int v[TAM], i;
	
	printf("Digite 10 valores: \n");
	for(i=0; i<TAM; i++)
		scanf("%d", &v[i]);
		
	bubleSort(v);
	
	printf("Vetor ordenado: \n");
	for(i=0; i<TAM; i++)
		printf("%d ", v[i]);
	printf("\n");
	
	return 0;
}
