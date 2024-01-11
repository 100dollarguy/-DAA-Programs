//
//  mergesort.c
//  DAA programs
//
//  Created by ROHAN on 11/01/24.
//

#include "mergesort.h"
#include <stdio.h>

void mergesort(int arr[], int min, int h);

int main(void) {
    int array[100], n, i = 0;
    printf("\t\t\tMerge Sort\n\n\n");
    printf("Enter the number of elements to be sorted: \n");
    scanf("%d", &n);
    printf("\nEnter the elements to be sorted: \n");
    for (i = 0; i < n; i++) {
        printf("\tArray[%d]= ", i);
        scanf("%d", &array[i]);
    }
    printf("\nBefore mergesort:");
    for (i = 0; i < n; i++) {
        printf("%4d", array[i]);
    }
    printf("\n");
    mergesort(array, 0, n - 1);
    printf("\nAfter Mergesort:");
    for (i = 0; i < n; i++) {
        printf("%4d", array[i]);
    }
    printf("\n");
}

void mergesort(int arr[], int min, int h) {
    int i = 0;
    int length = h - min + 1;
    int pivot = 0;
    int merge1 = 0;
    int merge2 = 0;
    int temp[100];

    if (min == h)
        return;

    pivot = (min + h) / 2;
    mergesort(arr, min, pivot);
    mergesort(arr, pivot + 1, h);

    for (i = 0; i < length; i++) {
        temp[i] = arr[min + i];
    }

    merge1 = 0;
    merge2 = pivot - min + 1;

    for (i = 0; i < length; i++) {
        if (merge2 <= h - min) {
            if (merge1 <= pivot - min) {
                if (temp[merge1] > temp[merge2]) {
                    arr[i + min] = temp[merge2++];
                } else {
                    arr[i + min] = temp[merge1++];
                }
            } else {
                arr[i + min] = temp[merge2++];
            }
        } else {
            arr[i + min] = temp[merge1++];
        }
    }
}
