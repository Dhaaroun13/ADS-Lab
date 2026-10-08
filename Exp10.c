#include <stdio.h>

#define MAXV 20
#define MAXE 100

typedef struct {
    int u, v, w;
} Edge;

int find(int parent[], int i)
{
    return (parent[i] == i) ? i : (parent[i] = find(parent, parent[i]));
}

void unionSet(int parent[], int x, int y)
{
    parent[y] = x;
}

int main()
{
    int n, e, i, j, x, y, count = 0, cost = 0;
    Edge edges[MAXE], t;
    int parent[MAXV];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    if (n < 1 || n > MAXV || e < 0 || e > MAXE) {
        printf("Vertices must be 1-%d and edges 0-%d\n", MAXV, MAXE);
        return 1;
    }

    printf("Enter edges (u v w):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        if (edges[i].u < 0 || edges[i].u >= n || edges[i].v < 0 || edges[i].v >= n) {
            printf("Invalid vertex in edge %d\n", i + 1);
            return 1;
        }
    }

    /* sort edges by weight */
    for (i = 0; i < e - 1; i++)
        for (j = i + 1; j < e; j++)
            if (edges[i].w > edges[j].w) {
                t = edges[i];
                edges[i] = edges[j];
                edges[j] = t;
            }

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in MST:\n");
    for (i = 0; i < e && count < n - 1; i++) {
        x = find(parent, edges[i].u);
        y = find(parent, edges[i].v);


        if (x != y) {
            printf("%d-%d (%d)\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            unionSet(parent, x, y);
            count++;
        }
    }
    if (count < n - 1)
         printf("Graph is not connected - no spanning tree exists\n");
    else
         printf("Total cost of MST = %d\n", cost);
    return 0;
}
