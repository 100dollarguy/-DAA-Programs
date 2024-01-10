//
//  TsMan.c
//  DAA programs
//
//  Created by ROHAN on 10/01/24.
//

#include "TsMan.h"
//created By ROHAN
//on 10/01/2024
#include "TsMan.h"
#include <stdio.h>
#include <stdlib.h>

int a[10][10], visited[10], n, cost = 0;

void get() {
    int i, j;
    printf("\n\n Enter Number Of Cities:");
    scanf("%d", &n);
    printf("\n Enter Cost Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("\n\n Enter Elements Of Row #%d\n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        visited[i] = 0;
    }
    printf("\n\n The Cost Matrix is:\n");
    for (i = 0; i < n; i++) {
        printf("\n\n");
        for (j = 0; j < n; j++)
            printf("\t %d", a[i][j]);
    }
}

void mincost(int city) {
    int ncity, least(int c);
    visited[city] = 1;
    printf("%d==>", city + 1);
    ncity = least(city);
    if (ncity == 999) {
        ncity = 0;
        printf("%d", ncity + 1);
        cost += a[city][ncity];
        return;
    }
    mincost(ncity);
}

int least(int c) {
    int i, nc = 999;
    int min = 999, kmin;
    for (i = 0; i < n; i++) {
        if ((a[c][i] != 0 && visited[i] == 0))
            if (a[c][i] < min) {
                min = a[c][i];
                kmin = a[c][i];
                nc = i;
            }
    }
    if (min != 999)
        cost += kmin;
    return nc;
}

void put() {
    printf("\n\n Minimum Cost: %d", cost);
}

int main() {
    get();
    printf("\n\n The Path Is:\n\n");
    mincost(0);
    put();

    return 0;
}
