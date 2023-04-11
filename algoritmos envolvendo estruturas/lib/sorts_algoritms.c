#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lib/sorts_algoritms.h"


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

