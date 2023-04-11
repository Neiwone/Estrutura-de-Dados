#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../libs/sorts_algorithms.h"

int main () {

    int A[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);
    srand(time(NULL));
    shuffle(A, n);

    while (1)
    {
        printf("\nvetor inicial: ");
        printar_vetor(A, n);

        printf("\nSelecione o algoritmo de ordenacao desejado:\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Bogo Sort\n");
        printf("3 - Insertion Sort\n");
        printf("4 - Selection Sort\n");
        printf("5 - Quick Sort\n");
        printf("6 - Randomizar vetor\n");
        printf("0 - Sair\n\n");
        printf("opcao: ");

        int opcao;
        scanf("%d", &opcao); 
        fflush(stdin);

        switch (opcao) {
        case 1:
            bubble_sort(A, n);
            printar_vetor(A, n);
            break;
        case 2:
            printf("numero de tentativas: %d\n", bogo_sort(A, n));
            printar_vetor(A, n);
            
            break;
        case 3:
            insertion_sort(A, n);
            printar_vetor(A, n);
            break;
        case 4:
            selection_sort(A, n);
            printar_vetor(A, n);
            break;
        case 5:
            quick_sort(A, 0, n - 1);
            printar_vetor(A, n);
            break;
        case 6:
            shuffle(A, n);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("insira um valor valido\n");
            break;
        }

    }
    
}