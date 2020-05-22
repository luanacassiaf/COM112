#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp, mov;

void bubbleSort(int tamanho, int *n)
{
    int i, j, aux, *V, compara = 0, move = 0, met = 1;
    clock_t c2, c1;
    double tempo;

    V = (int *) malloc(tamanho * sizeof(int));
    for(i = 0; i < tamanho; i++)
    {
        V[i] = n[i];
    }

    c1 = clock();
    for(i = 1; i < tamanho; i++)
    {
        for(j = tamanho-1; j >=i; j--)
        {
            compara++;
            if(V[j-1]>V[j])
            {
                aux = V[j];
                V[j] = V[j-1];
                V[j-1] = aux;
                move++;
            }
        }
    }
    c2 = clock();
    tempo = (c2 - c1)/(double)CLOCKS_PER_SEC;

    addArqExit(tamanho, V, tempo, compara, move, met);
    free(V);
    return;
}

void selectionSort(int tamanho, int *n)
{
    int i, j, min, *V, aux, compara = 0, move = 0, met = 2;
    clock_t c2, c1;
    double tempo;

    V = (int *) malloc(tamanho * sizeof(int));
    for(i = 0; i < tamanho; i++)
    {
        V[i] = n[i];
    }

    c1 = clock();
    for (i = 0; i < tamanho-1; i++)
    {
        min = i;
        for (j = (i+1); j < tamanho; j++)
        {
            compara++;
            if(V[j] < V[min])
            {
                min = j;
            }
        }
        compara++;
        if (V[i] != V[min])
        {
            aux = V[i];
            V[i] = V[min];
            V[min] = aux;
            move++;
        }
    }
    c2 = clock();
    tempo = (c2 - c1)/(double)CLOCKS_PER_SEC;

    addArqExit(tamanho, V, tempo, compara, move, met);
    free(V);
    return;
}

void insertionSort(int tamanho, int *n){
    int i, j, *V, aux, compara = 0, move = 0, met = 3;
    clock_t c2, c1;
    double tempo;

    V = (int *) malloc(tamanho * sizeof(int));
    for(i = 0; i < tamanho; i++)
    {
        V[i] = n[i];
    }

    c1 = clock();
    for (i = 1; i < tamanho; i++) {
        aux = V[i];
        j = i - 1;
        compara++;
        while (j >= 0 && V[j] > aux) {
            V[j + 1] = V[j];
            j = j - 1;
            move++;
            compara++;
        }
        V[j + 1] = aux;
    }
    c2 = clock();
    tempo = (c2 - c1)/(double)CLOCKS_PER_SEC;

    addArqExit(tamanho, V, tempo, compara, move, met);
    free(V);
    return;
}

void merge(int l, int r, int *v){
    int i;
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    merge (l, mid, v);
    merge (mid + 1, r, v);

    int qtdElementosL = mid - l + 1;
    int qtdElementosR = r - (mid + 1) + 1;

    int vetorL[qtdElementosL];
    int vetorR[qtdElementosR];

    for (i = l; i <= mid; i++){
        vetorL[i - l] = v[i];
        mov++;
    }
    for (i = mid + 1; i <= r; i++){
        vetorR[i - (mid + 1)] = v[i];
        mov++;
    }

    int posL = 0, posR = 0;
    for (i = l; i <= r; i++) {
        int elementoAtual;
        if (posL >= qtdElementosL) {
            elementoAtual = vetorR[posR];
            posR++;
            comp++;
            mov++;
        } else if (posR >= qtdElementosR) {
            elementoAtual = vetorL[posL];
            posL++;
            comp += 2;
            mov++;
        } else if (vetorL[posL] <= vetorR[posR]) {
            elementoAtual = vetorL[posL];
            posL++;
            comp += 3;
            mov++;
        } else {
            elementoAtual = vetorR[posR];
            posR++;
            comp += 3;
            mov++;
        }

        v[i] = elementoAtual;
    }
}

void mergeSort(int tamanho, int *n){
    int l = 0, r = tamanho-1, *v, met = 4, i;
    clock_t c2, c1;
    double tempo;

    v = (int *) malloc(tamanho * sizeof(int));
    for(i = 0; i < tamanho; i++)
    {
        v[i] = n[i];
    }

    c1 = clock();
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    merge (l, mid, v);
    merge (mid + 1, r, v);

    int qtdElementosL = mid - l + 1;
    int qtdElementosR = r - (mid + 1) + 1;

    int vetorL[qtdElementosL];
    int vetorR[qtdElementosR];

    for (i = l; i <= mid; i++){
			vetorL[i - l] = v[i];
			mov++;
		}

    for (i = mid + 1; i <= r; i++){
			 vetorR[i - (mid + 1)] = v[i];
			 mov++;
		}

    int posL = 0, posR = 0;
    for (i = l; i <= r; i++) {
        int elementoAtual;
        if (posL >= qtdElementosL) {
            elementoAtual = vetorR[posR];
            posR++;
						comp++;
						mov++;
        } else if (posR >= qtdElementosR) {
            elementoAtual = vetorL[posL];
            posL++;
						comp += 2;
						mov++;
        } else if (vetorL[posL] <= vetorR[posR]) {
            elementoAtual = vetorL[posL];
            posL++;
						comp += 3;
						mov++;
        } else {
            elementoAtual = vetorR[posR];
            posR++;
						comp += 3;
						mov++;
        }

        v[i] = elementoAtual;
    }
    c2 = clock();
    tempo = (c2 - c1)/(double)CLOCKS_PER_SEC;

    addArqExit(tamanho, v, tempo, comp, mov, met);
    free(v);
    return;
}

void quickSort(int left, int right, int *n, int tamanho){
    int i, j, x, y, *v, met = 5;
    clock_t c2, c1;
    double tempo;
		comp = 0;
		mov = 0;

    v = (int *) malloc(tamanho * sizeof(int));
    for(i = 0; i < tamanho; i++)
    {
        v[i] = n[i];
    }

    i = left;
    j = right;
    x = v[(left + right) / 2];

    c1 = clock();
    while(i <= j) {
        while(v[i] < x && i < right) {
            i++;
						comp++;
        }
        while(v[j] > x && j > left) {
            j--;
						comp++;
        }
        if(i <= j) {
						comp++;
            y = v[i];
            v[i] = v[j];
            v[j] = y;
						mov += 3;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick(left, j, v);
    }
    if(i < right) {
        quick(i, right, v);
    }
    c2 = clock();
    tempo = (c2 - c1)/(double)CLOCKS_PER_SEC;

    addArqExit(tamanho, v, tempo, comp, mov, met);
    free(v);
    return;
}

void quick(int left, int right, int *v){
    int i, j, x, y;

    i = left;
    j = right;
    x = v[(left + right) / 2];

    while(i <= j) {
        while(v[i] < x && i < right) {
            i++;
						comp++;
        }
        while(v[j] > x && j > left) {
            j--;
						comp++;
        }
        if(i <= j) {
						comp++;
            y = v[i];
            v[i] = v[j];
            v[j] = y;
						mov += 3;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick(left, j, v);
    }
    if(i < right) {
        quick(i, right, v);
    }
}
