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
    for (int i = 0; i < n - 1; i++) {
        if(A[i] > A[i+1]) swap(&A[i], &A[i+1]);
    }
    bubble_sort(A, n-1); 
    
}

void bubble_sortV2(int * A, int n)
{
    bool flag = true;
 
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            swap(&A[i], &A[i+1]);
            flag = false;
        }
    }
    if (!flag) bubble_sortV2(A, n);
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
    int timessorted = 0;
    while(!is_sorted(A, n)) {
        shuffle(A, n);
        timessorted++;
    }
    return timessorted;
}

void insertion_sort(int * A, int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        for (int j = i - 1; j >= 0 && A[j] > key; j--) {
            A[j + 1] = A[j];
            A[j] = key;
        }
    }
}

void selection_sort(int * A, int n) { 
    for  (int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) if(A[j] < A[min]) min = j;
        if(i != min) swap(&A[i], &A[min]);
    }
}

void selection_sortV2(int * A, int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int min = i;
        int max = j;
        for (int k = i + 1; k <= j; k++)  {
            if(A[k] > A[max]) max = k;
            if(A[k] < A[min]) min = k;
        }
        if(i != min) {
            if(i == max) max = min;
            swap(&A[i], &A[min]);
        }
        if(j != max) swap(&A[j], &A[max]);
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

void shell_sort(int * A, int n) {
    for (int h = n/2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            int key = A[i];
            int j;
            for (j = i; j >= h && A[j - h] > key; j -= h) A[j] = A[j - h];
            A[j] = key;
        }
    }
}

void counting_sort(int * A, int n) {

    int max = A[0];
    for (int i = 0; i < n; i++) if(A[i] > max) max = A[i];
    
    int output[n];
    int * count = calloc(max, sizeof(int));

    for (int i = 0; i < n; i++) count[A[i]]++;

    for (int i = 0; i < max; i++) count[i + 1] += count[i];
    
    for (int i = 0; i < n; i++) output[--count[A[i]]] = A[i];
    
    for (int i = 0; i < n; i++) A[i] = output[i];
}

void counting_sort_to_radix(int * A, int n, int exp) {

    
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(A[i] / exp) % 10]++;

    for (int i = 1; i < n; i++) count[i] += count[i-1];

    for (int i = n - 1; i >= 0; i--) output[--count[(A[i] / exp) % 10]] = A[i];

    for (int i = 0; i < n; i++) A[i] = output[i];
}

void radix_sort(int * A, int n) {

    int max = A[0];
    for (int i = 0; i < n; i++) if(A[i] > max) max = A[i];
    
    for (int exp = 1; max / exp > 0; exp *= 10) counting_sort_to_radix(A, n, exp);
}