#include <stdbool.h>

void printar_vetor(int * A, int n);
void swap(int * a, int * b);


void bubble_sort(int * A, int n);

bool is_sorted(int * A, int n);
void shuffle(int * A, int n);
int bogo_sort(int * A, int n);

void insertion_sort(int * A, int n);

void selection_sort(int * A, int n);

int partition(int * A, int low, int high);
void quick_sort(int * A, int low, int high);

void shell_sort(int * A, int n);