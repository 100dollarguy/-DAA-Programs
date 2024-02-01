//
//  DFS.c
//  DAA programs
//
//  Created by ROHAN on 31/01/24.
//

#include "DFS.h"
//
//  DFS&BFS.c
//  DAA programs
//
//  Created by ROHAN on 11/01/24.
//

#include "DFS.h"
#include<stdio.h>
#define MAX 100
int c[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;
void BFS(int v)
{
    int front=0,rear=-1,i;
    visited[v]=1;
    queue[++rear]=v;
    while(front<=rear)
    {
        v=queue[front++];
        printf("%d",v);
        for(i=1;i<=n;i++)
        {
            if(c[v][i]==1&&visited[i]==0)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
    printf("\n");
}
void DFS(int v)
{
    int i;
    visited[v]=1;
    printf("%d",v);
    for(i=1;i<=n;i++)
    {
        if(c[v][i]==1&&visited[i]==0)
        {
            DFS(i);
        }
    }
}
int main()
{
    int i,j,v;
    printf("Enter the number of vertices in the graph:");
    scanf("%d",&n);
    printf("Enter the cost matrix of the graph:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("Enter the starting vertex for BFS:");
    scanf("%d",&v);
    printf("BFS traversal of the graph is:");
    BFS(v);
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("Enter the starting vertex for DFS:");
    scanf("%d",&v);
    printf("DFS traversal of the graph is:");
    DFS(v);
    printf("\n");
    return 0;
}
