//sum of subset
//  prog14.c
//  DAA programs
//
//  Created by ROHAN on 31/01/24.
//

#include "prog14.h"
#include <stdio.h>
#include <stdlib.h>

static int total_nodes;

void printValues(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum) {
    total_nodes++;
    if (target_sum == sum) {
        printValues(t, t_size);
        subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        return;
    } else {
        for (int i = ite; i < s_size; i++) {
            t[t_size] = s[i];
            subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
        }
    }
}

void generateSubsets(int s[], int size, int target_sum) {
    int *tuplet_vector = (int *)malloc(size * sizeof(int));
    subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    free(tuplet_vector);
}

int main() {
    int set[] = {5, 6, 12, 54, 2, 20, 15};
    int size = sizeof(set) / sizeof(set[0]);

    printf("The set is: ");
    printValues(set, size);

    generateSubsets(set, size, 25);

    printf("Total Nodes generated: %d\n", total_nodes);

    return 0;
}
