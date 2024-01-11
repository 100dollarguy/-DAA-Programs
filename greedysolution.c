//
//  greedysolution.c
//  DAA programs
//
//  Created by ROHAN on 11/01/24.
//
#include <stdio.h>

void knapsackGreedy(int M, int n, int w[20], int P[20]) {
    double x[20];
    double sum = 0.0;
    int i, j;
    double ratio[20];
    int order[20];
    int Rc = M;

    for (i = 0; i < n; i++) {
        ratio[i] = (double)P[i] / w[i];
        order[i] = i;
    }

    // Corrected the sorting logic
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[order[j]] < ratio[order[j + 1]]) {
                int tempIndex = order[j];
                order[j] = order[j + 1];
                order[j + 1] = tempIndex;
            }
        }
    }

    for (i = 0; i < n; i++) {
        x[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int currentIndex = order[i];
        if (w[currentIndex] <= Rc) {
            // Corrected the assignment operator
            x[currentIndex] = Rc / w[currentIndex];
            Rc = Rc - w[currentIndex];
            sum = sum + P[currentIndex];
        } else {
            x[currentIndex] = (double)Rc / w[currentIndex];
            sum += (P[currentIndex] * x[currentIndex]);
            break;
        }
    }

    printf("Solution vector 'x':\n");
    for (i = 0; i < n; i++) {
        printf("%21f", x[i]);
    }

    printf("\nMaximum profit: %21f\n", sum);
}

int main() {
    int M, n, i, w[20], P[20];  // Corrected the declaration of P
    printf("Enter Knapsack capacity (M): ");
    scanf("%d", &M);
    printf("Enter the number of objects (n): ");
    scanf("%d", &n);

    printf("Enter weights for each object:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter profits for each object:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }

    knapsackGreedy(M, n, w, P);  // Corrected the function call

    return 0;
}
