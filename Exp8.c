#include <stdio.h>

#define SIZE 20

int visited[SIZE];

void DFS(int adj[SIZE][SIZE], int n, int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            DFS(adj, n, i);
}

int main()
{
    int n, i, j, start;
    int adj[SIZE][SIZE];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if (n < 1 || n > SIZE) {
        printf("Number of vertices must be between 1 and %d\n", SIZE);
        return 1;
    }
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter start vertex (0-%d): ", n - 1);
    scanf("%d", &start);
    if (start < 0 || start >= n) {
        printf("Invalid start vertex\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(adj, n, start);
    printf("\n");
    return 0;
}
