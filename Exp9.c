#include <stdio.h>

#define SIZE 20
#define INF 9999

void printPath(int parent[], int j)
{
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

int main()
{
    int n, i, j, u, min, start, count;
    int adj[SIZE][SIZE];
    int dist[SIZE], visited[SIZE], parent[SIZE];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if (n < 1 || n > SIZE) {
        printf("Number of vertices must be between 1 and %d\n", SIZE);
        return 1;
    }
    printf("Enter adjacency matrix (0 = no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &start);
    if (start < 0 || start >= n) {
        printf("Invalid start vertex\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[start] = 0;

    for (count = 0; count < n; count++) {
        min = INF;
        u = -1;
        for (i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        if (u == -1)                       
            break;

         visited[u] = 1;
         for (i = 0; i < n; i++)
             if (adj[u][i] && !visited[i] && dist[u] + adj[u][i] < dist[i]) {
                 dist[i] = dist[u] + adj[u][i];
                 parent[i] = u;
             }
    }

    printf("Shortest distances from %d:\n", start);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("%d -> %d : unreachable\n", start, i);
        } else {
            printf("%d -> %d : %d   Path: ", start, i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
    return 0;
}
