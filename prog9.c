#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int A[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[low + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void Mergesort(int A[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        Mergesort(A, low, mid);
        Mergesort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements (n) or -999 to quit:");
    scanf("%d", &n);

    while (n != -999) {
        int A[n];

        srand(time(NULL));  // Fix: seed srand with current time
        for (i = 0; i < n; i++) {
            A[i] = rand();
        }

        clock_t start_time = clock();
        Mergesort(A, 0, n - 1);
        clock_t end_time = clock();

        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Time taken to sort (n=%d): %1f seconds\n", n, time_taken);

        printf("Enter the number of elements (n) or -999 to quit:");
        scanf("%d", &n);
    }

    return 0;
}
