//adjacency matrice
//  prog11.c
//  DAA programs
//
//  Created by ROHAN on 31/01/24.
//

#include "prog11.h"
#include <stdio.h>

void printAdjacencyMatrix(int maxVertices, int adjacencyMatrix[][maxVertices]) {
    int i, j;
    printf("Adjacency Matrix of the Graph:\n");
    for (i = 0; i < maxVertices; i++) {
        for (j = 0; j < maxVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maxVertices, numEdges, i, j;

    printf("Enter the number of vertices:");
    scanf("%d", &maxVertices);

    int adjacencyMatrix[maxVertices][maxVertices];

    for (i = 0; i < maxVertices; i++) {
        for (j = 0; j < maxVertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges:");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex pairs, e.g., 1,2):\n");

    for (i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        scanf("%d%d", &vertex1, &vertex2);

        if (vertex1 >= 1 && vertex1 <= maxVertices && vertex2 >= 1 && vertex2 <= maxVertices) {
            adjacencyMatrix[vertex1 - 1][vertex2 - 1] = 1;
            adjacencyMatrix[vertex2 - 1][vertex1 - 1] = 1; // Corrected index
        } else {
            printf("Invalid edge. Vertex numbers should be between 1 and %d.\n", maxVertices);
            i--;
        }
    }

    printAdjacencyMatrix(maxVertices, adjacencyMatrix);

    return 0;
}
