#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createfile(int tamanho, int *n){
    int i;
    FILE *arq, *saida, *relat;
    arq = fopen("com112_entrada.txt", "w");

    fprintf(arq, "%d\n", tamanho);
    for(i = 0; i < tamanho; i++){
        fprintf(arq, "%d ", n[i]);
    }

    saida = fopen("com112_saida.txt", "w");
    relat = fopen("com112_relatorio.txt", "w");
    fprintf(relat, "Numero de elementos ordenados: %d\n", tamanho);

    fclose(arq);
    fclose(saida);
    fclose(relat);

    return;
}

void addArqExit(int tamanho, int *n, double t, int comp, int move, int metodo){
    int i;
    FILE *saida, *relat;
    saida = fopen("com112_saida.txt", "a");
    for(i = 0; i < tamanho; i++){
        fprintf(saida, "%d ", n[i]);
    }
    fprintf(saida, "\n\n");
    fclose(saida);

    relat = fopen("com112_relatorio.txt", "a");
    if(metodo == 1){
        fprintf(relat, "\nMetodo Bubble Sort\nTempo de Execucao: %lf\nNumero de Comparacoes: %d\nNumero de Movimentos: %d\n", t, comp, move);
    } else if(metodo == 2){
        fprintf(relat, "\nMetodo Selection Sort\nTempo de Execucao: %lf\nNumero de Comparacoes: %d\nNumero de Movimentos: %d\n", t, comp, move);
    } else if(metodo == 3){
        fprintf(relat, "\nMetodo Insertion Sort\nTempo de Execucao: %lf\nNumero de Comparacoes: %d\nNumero de Movimentos: %d\n", t, comp, move);
    } else if(metodo == 4){
        fprintf(relat, "\nMetodo Merge Sort\nTempo de Execucao: %lf\nNumero de Comparacoes: %d\nNumero de Movimentos: %d\n", t, comp, move);
    } else if(metodo == 5){
        fprintf(relat, "\nMetodo Quick Sort\nTempo de Execucao: %lf\nNumero de Comparacoes: %d\nNumero de Movimentos: %d\n", t, comp, move);
    }

    fclose(relat);
}

void imprimeRelatorio(){
    char frase[100];
    FILE *arq;
    arq = fopen("com112_relatorio.txt", "r");

    if(arq == NULL){
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }

    printf("\n");
    while(fgets(frase, 100, arq) != NULL){
        printf("%s", frase);
    }

    return;
}
