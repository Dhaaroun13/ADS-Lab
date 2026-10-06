#include <stdio.h>

#define SIZE 20

int q[SIZE], front = 0, rear = 0;

void enqueue(int v) { q[rear++] = v; }
int dequeue() { return q[front++]; }
int isEmpty() { return front == rear; }

int main()
{
    int n, i, j, v, start;
    int adj[SIZE][SIZE];
    int visited[SIZE] = {0};

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

    printf("BFS Traversal: ");
    visited[start] = 1;
    enqueue(start);
    while (!isEmpty()) {
        v = dequeue();
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
    return 0;
}
