#include<stdio.h>
#include<stdlib.h>
#define infinity 9999
#define MAX 20

int G[MAX][MAX], spanning[MAX][MAX], n;
int prims();

int main() {
    int i, j, total_cost;

    printf("Enter no. of vertices:");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    total_cost = prims();

    printf("\nSpanning tree matrix:\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d\t", spanning[i][j]);
    }

    printf("\nTotal cost of spanning tree: %d", total_cost);

    return 0;
}

int prims() {
    int cost[MAX][MAX];
    int u, v, min_distance, distance[MAX], from[MAX];
    int visited[MAX], no_of_edges, i, min_cost, j;

    // Create cost matrix and initialize other arrays
    for (i = 0; i < n; i++) {
        if (G[i][0] == 0)
            cost[i][0] = infinity;
        else
            cost[i][0] = G[i][0];

        spanning[i][0] = 0;
        distance[i] = cost[i][0];
        visited[i] = 0;
        from[i] = 0;
    }

    min_cost = 0;
    no_of_edges = n - 1;

    while (no_of_edges > 0) {
        // Find the vertex at a minimum distance from the tree
        min_distance = infinity;
        for (i = 1; i < n; i++) {
            if (visited[i] == 0 && distance[i] < min_distance) {
                v = i;
                min_distance = distance[i];
            }
        }

        u = from[v];
        // Insert the edge into the spanning tree
        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];
        no_of_edges--;

        visited[v] = 1;
        
        // Update the distance array for adjacent vertices
        for (i = 1; i < n; i++) {
            if (visited[i] == 0 && G[i][v] < distance[i]) {
                distance[i] = G[i][v];
                from[i] = v;
            }
        }

        min_cost += cost[u][v];
    }

    return min_cost;
}
