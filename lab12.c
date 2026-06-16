#include <stdio.h>

int main() {
    int N = 5;
    int edges[4][2] = {{1, 2}, {2, 3}, {4, 5}, {1, 5}};
    int num_edges = 4;

    int A[5][5] = {0};
    int D[5][5] = {0};
    int L[5][5] = {0};

    for (int i = 0; i < num_edges; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        
        A[u][v] = 1;
        A[v][u] = 1;
        
        D[u][u]++;
        D[v][v]++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            L[i][j] = D[i][j] - A[i][j];
        }
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nDegree Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    printf("\nLaplacian Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", L[i][j]);
        }
        printf("\n");
    }

    return 0;
}