//indegree and out degree
//  prog12.c
//  DAA programs
//
//  Created by ROHAN on 31/01/24.
//

#include "prog12.h"
#include <stdio.h>

// Function to print the adjacency matrix
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

// Function to print in-degree and out-degree for each vertex
void printDegree(int maxVertices, int adjacencyMatrix[][maxVertices]) {
    int i, j;
    for (i = 0; i < maxVertices; i++) {
        int inDegree = 0, outDegree = 0;
        for (j = 0; j < maxVertices; j++) {
            if (adjacencyMatrix[j][i] == 1) {
                inDegree++;
            }
            if (adjacencyMatrix[i][j] == 1) {
                outDegree++;
            }
        }
        printf("Vertex %d: In-Degree = %d, Out-Degree = %d\n", i + 1, inDegree, outDegree);
    }
}

int main() {
    int maxVertices, numEdges, i;

    printf("Enter the number of vertices: ");
    scanf("%d", &maxVertices);

    // Initialize an adjacency matrix to store the graph
    int adjacencyMatrix[maxVertices][maxVertices];

    // Initialize all elements in the adjacency matrix to 0
    for (i = 0; i < maxVertices; i++) {
        for (int j = 0; j < maxVertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex pairs, e.g., 1 2):\n");

    // Input the edges and update the adjacency matrix
    for (i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);

        // Update the adjacency matrix to represent the edge
        if (vertex1 >= 1 && vertex1 <= maxVertices && vertex2 >= 1 && vertex2 <= maxVertices) {
            adjacencyMatrix[vertex1 - 1][vertex2 - 1] = 1;
            adjacencyMatrix[vertex2 - 1][vertex1 - 1] = 1; // For an undirected graph
        } else {
            printf("Invalid edge. Vertex numbers should be between 1 and %d.\n", maxVertices);
            i--; // Decrement the loop counter to re-enter the edge
        }
    }

    printAdjacencyMatrix(maxVertices, adjacencyMatrix);

    // Print in-degree and out-degree for each vertex
    printDegree(maxVertices, adjacencyMatrix);

    return 0;
}
