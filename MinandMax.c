#include "MinandMax.h"
#include <stdio.h>

int start, end, mid;
int min1, max1, min2, max2;

void findMinMax(int arr[], int start, int end, int *min, int *max)
{
    if (start == end)
    {
        *min = *max = arr[start];
        return;
    }
    if (end - start == 1)
    {
        if (arr[start] < arr[end])
        {
            *min = arr[start];
            *max = arr[end];
        }
        else
        {
            *min = arr[end];
            *max = arr[start];
        }
        return;
    }
    mid = (start + end) / 2;
    findMinMax(arr, start, mid, &min1, &max1);
    findMinMax(arr, mid + 1, end, &min2, &max2);
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main()
{
    int n, i;
    int arr[100];
    int min, max;

    printf("enter the number of elements:");
    scanf("%d", &n);

    printf("enter the array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("Minimum value in the array: %d\n", min);
    printf("Maximum value in the array: %d\n", max);

    getchar(); // Wait for a key press
    return 0;
}
