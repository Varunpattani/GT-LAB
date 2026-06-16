#include <stdio.h>

int V = 4;
int adj[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {0, 0, 1, 0}
};

void dfs(int u, int visited[], int skip_v) {
    visited[u] = 1;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visited[v] && v != skip_v) {
            dfs(v, visited, skip_v);
        }
    }
}

int is_connected(int skip_v, int skip_u_edge, int skip_v_edge) {
    int visited[10] = {0};
    int start = (skip_v == 0) ? 1 : 0;
    if (start >= V) return 0;

    int temp = 0;
    if (skip_u_edge != -1 && skip_v_edge != -1) {
        temp = adj[skip_u_edge][skip_v_edge];
        adj[skip_u_edge][skip_v_edge] = 0;
        adj[skip_v_edge][skip_u_edge] = 0;
    }

    dfs(start, visited, skip_v);

    if (skip_u_edge != -1 && skip_v_edge != -1) {
        adj[skip_u_edge][skip_v_edge] = temp;
        adj[skip_v_edge][skip_u_edge] = temp;
    }

    for (int i = 0; i < V; i++) {
        if (i != skip_v && !visited[i]) return 0;
    }
    return 1;
}

int main() {
    int vc = V - 1;
    for (int i = 0; i < V; i++) {
        if (!is_connected(i, -1, -1)) {
            vc = 1;
            break;
        }
    }

    int ec = V - 1;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adj[i][j]) {
                if (!is_connected(-1, i, j)) {
                    ec = 1;
                    break;
                }
            }
        }
        if (ec == 1) break;
    }

    printf("Vertex Connectivity: %d\n", vc);
    printf("Edge Connectivity: %d\n", ec);
    
    if (vc == 1) {
        printf("Graph is Separable\n");
    } else {
        printf("Graph is Non-separable\n");
    }

    return 0;
}