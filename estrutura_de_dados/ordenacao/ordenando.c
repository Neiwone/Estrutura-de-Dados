#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../libs/sorts_algorithms.h"

int main () {

    int A[] = {10, 1, 32, 3, 341, 5, 26, 7, 102};
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
        printf("6 - Shell Sort\n");
        printf("7 - Counting Sort\n");
        printf("8 - Radix Sort\n");
        printf("9 - Randomizar vetor\n");
        printf("0 - Sair\n\n");
        printf("opcao: ");

        int opcao;
        scanf("%d", &opcao); 
        fflush(stdin);

        switch (opcao) {
        case 1:
            bubble_sort(A, n);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 2:
            printf("numero de tentativas: %d\n", bogo_sort(A, n));
            printf("\n");
            printar_vetor(A, n);
            break;
        case 3:
            insertion_sort(A, n);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 4:
            selection_sort(A, n);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 5:
            quick_sort(A, 0, n - 1);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 6:
            shell_sort(A, n);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 7:
            counting_sort(A, n);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 8:
            radix_sort(A, n);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 9:
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