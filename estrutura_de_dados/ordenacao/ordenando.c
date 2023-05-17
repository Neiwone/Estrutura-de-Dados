#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../libs/sorts_algorithms.h"

int main () {

    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(A) / sizeof(A[0]);
    srand(time(0));
    //shuffle(A, n);

    while (1)
    {
        printf("\nvetor inicial: ");
        printar_vetor(A, n);

        printf("\nSelecione o algoritmo de ordenacao desejado:\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Bubble Sort with flag\n");
        printf("3 - Bogo Sort\n");
        printf("4 - Insertion Sort\n");
        printf("5 - Selection Sort\n");
        printf("6 - Selection Sort with max & min\n");
        printf("7 - Quick Sort\n");
        printf("8 - Shell Sort\n");
        printf("9 - Counting Sort\n");
        printf("10 - Radix Sort\n");
        printf("11 - Randomizar vetor\n");
        printf("0 - Sair\n\n");
        printf("opcao: ");

        int opcao;
        scanf("%d", &opcao); 
        fflush(stdin);

        switch (opcao) {
        case 1:
            printf("bubble sort: \n");
            bubble_sort(A, n);
            printar_vetor(A, n);
            break;
        case 2:
            printf("bubble sort with flag: \n");
            bubble_sortV2(A, n);
            printar_vetor(A, n);
            break;
        case 3:
            printf("numero de tentativas: %d\n", bogo_sort(A, n));
            printf("\n");
            printar_vetor(A, n);
            break;
        case 4:
            insertion_sort(A, n);
            printar_vetor(A, n);
            break;
        case 5:
            printf("selection sort: \n");
            selection_sort(A, n);
            printar_vetor(A, n);
            break;
        case 6:
            printf("selection sort with max and min: \n");
            selection_sortV2(A, n);
            printar_vetor(A, n);
            break;
        case 7:
            quick_sort(A, 0, n - 1);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 8:
            shell_sort(A, n);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 9:
            counting_sort(A, n);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 10:
            radix_sort(A, n);
            printf("\n");
            printar_vetor(A, n);
            break;
        case 11:
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