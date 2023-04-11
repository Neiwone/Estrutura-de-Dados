#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sorts_algorithms.h"


void printar_vetor(int * A, int n) {
    for (int i = 0; i < n; i++) printf("%d%s", A[i], (i < n - 1) ? ", " : ".\n");
}

void swap(int * a, int * b) { 
    int aux = *a; 
    *a = *b; 
    *b = aux; 
} 

void bubble_sort(int * A, int n) {

    if(n < 0) return; 
    for (int i = 0; i < n - 1; i++) if(A[i] > A[i+1]) swap(&A[i], &A[i+1]);  
    bubble_sort(A, n-1); 
    
}

bool is_sorted(int * A, int n) {
    while(--n >= 1) if(A[n] < A[n-1]) return false;
    return true;
}
 
void shuffle(int * A, int n) {

    for(int i = 0; i < n; i++) {
        int r = rand() % n;
        swap(&A[i], &A[r]);
    }
}
 
int bogo_sort(int * A, int n) {
    int tentativasbogo = 0;
    while(!is_sorted(A, n)) {
        shuffle(A, n);
        tentativasbogo+=1;
    }
    return tentativasbogo;
}

void insertion_sort(int * A, int n) {

    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

void selection_sort(int * A, int n) { 
    int min;
    for (int i = 0; i < (n-1); i++) {
        min = i;
        for (int j = (i+1); j < n; j++) if(A[j] < A[min]) min = j;
        if (i != min) swap(&A[i], &A[min]);
    }
}

int partition(int * A, int low, int high) {
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return (i + 1);
}

void quick_sort(int * A, int low, int high) {

    if (low < high) {
        int pi = partition(A, low, high);
        quick_sort(A, low, pi - 1);
        quick_sort(A, pi + 1, high);
    }

}