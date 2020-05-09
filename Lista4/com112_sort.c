#include "com112_sort.h"

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
