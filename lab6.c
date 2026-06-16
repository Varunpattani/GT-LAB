#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int V, E;


int dfs_count(int src) {
    visited[src] = 1;
    int count = 1;
    for (int i = 0; i < V; i++)
        if (adj[src][i] && !visited[i])
            count += dfs_count(i);
    return count;
}

int main() {
    int u, v, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("\nArticulation Points (Cut Vertices):\n");
    int found = 0;

    for (int skip = 0; skip < V; skip++) {

        // Reset visited array manually
        for (i = 0; i < V; i++)
            visited[i] = 0;

        visited[skip] = 1;  // remove this vertex

        // Start DFS from first non-skipped vertex
        int start = (skip == 0) ? 1 : 0;
        int reachable = dfs_count(start);

        // If reachable < V-1, graph broke => cut vertex
        if (reachable < V - 1) {
            printf("  Vertex %d is an Articulation Point\n", skip);
            found = 1;
        }
    }

    if (!found)
        printf("  No articulation points found.\n");

    return 0;
}