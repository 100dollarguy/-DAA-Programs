//
//  DivideNconquer.c
//  DAA programs
//
//  Created by ROHAN on 11/01/24.
//

#include "DivideNconquer.h"
#include <stdio.h>

// Function to partition the array
int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (1) {
        while (i <= j && A[i] <= pivot)
            i++;
        while (A[j] > pivot)
            j--;

        if (i <= j) {
            // Swap A[i] and A[j]
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        } else {
            // Swap A[low] and A[j]
            temp = A[low];
            A[low] = A[j];
            A[j] = temp;
            return j;
        }
    }
}

// Function to perform quicksort
void quicksort(int A[], int low, int high) {
    if (low < high) {
        int j = partition(A, low, high);
        quicksort(A, low, j - 1);
        quicksort(A, j + 1, high);
    }
}

int main() {
    int i, n;
    int A[100];

    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    quicksort(A, 0, n - 1);

    printf("Sorted list of elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
