#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void relatorio(){
    imprimeRelatorio();
}

void menu(int tamanho, int *n)
{
    int v;
    while(v != 6)
    {
        printf ("\nMenu:\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Merge Sort\n5.Quick Sort\n6.Relatorio\n7.Sair\n\nEscolha uma opcao: ");
        scanf("%d", &v);
        printf("\n");

        switch (v)
        {
        case 1 :
            bubbleSort(tamanho, n);
            break;

        case 2 :
            selectionSort(tamanho, n);
            break;

        case 3 :
            insertionSort(tamanho, n);
            break;

        case 4 :
            mergeSort(tamanho, n);
            break;

        case 5:
            quickSort(0, tamanho-1, n, tamanho);
            break;

        case 6:
            relatorio();
            break;

        case 7:
            exit(0);
            break;

        default :
            printf ("Valor invalido!\n");
        }
    }
    return;
}

int main()
{
    int tamanho, *n, i;

    srand(time(NULL));
    tamanho = rand();
    n = (int *) malloc(tamanho * sizeof(int));
    for(i = 0; i < tamanho; i++)
    {
        n[i] = rand();
    }

    createfile(tamanho, n);

    menu(tamanho, n);

    return 0;
}
