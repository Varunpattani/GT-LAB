#include <stdio.h>

int main() {
    int N = 4;
    int edges[4][2] = {{0, 1}, {0, 2}, {2, 3}, {1, 3}};
    int adj[4][4] = {0};

    for (int i = 0; i < 4; i++) {
        adj[edges[i][0]][edges[i][1]] = 1;
        adj[edges[i][1]][edges[i][0]] = 1;
    }

    int min_tdom = N + 1;

    printf("Total Dominating Sets:\n");
    for (int i = 1; i < (1 << N); i++) {
        int is_tdom = 1;
        int size = 0;

        for (int v = 0; v < N; v++) {
            if (i & (1 << v)) size++;
        }

        for (int v = 0; v < N; v++) {
            int has_neighbor_in_set = 0;
            for (int u = 0; u < N; u++) {
                if ((i & (1 << u)) && adj[v][u]) {
                    has_neighbor_in_set = 1;
                    break;
                }
            }
            if (!has_neighbor_in_set) {
                is_tdom = 0;
                break;
            }
        }

        if (is_tdom) {
            printf("{");
            int first = 1;
            for (int v = 0; v < N; v++) {
                if (i & (1 << v)) {
                    if (!first) printf(",");
                    printf("%d", v + 1);
                    first = 0;
                }
            }
            printf("}\n");
            if (size < min_tdom) min_tdom = size;
        }
    }
    printf("Total Domination Number = %d\n", min_tdom);

    return 0;
}