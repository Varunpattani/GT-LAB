#include <stdio.h>

int M = 3;
int N = 3;
int bpGraph[3][3] = {
    {1, 0, 0},
    {1, 1, 0},
    {0, 0, 1}
};

int bpm(int u, int matchR[], int seen[]) {
    for (int v = 0; v < N; v++) {
        if (bpGraph[u][v] && !seen[v]) {
            seen[v] = 1;
            if (matchR[v] < 0 || bpm(matchR[v], matchR, seen)) {
                matchR[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int matchR[3];
    for (int i = 0; i < N; i++) matchR[i] = -1;

    int result = 0;
    for (int u = 0; u < M; u++) {
        int seen[3] = {0};
        if (bpm(u, matchR, seen)) {
            result++;
        }
    }

    printf("Maximum Matching Edges:\n");
    for (int i = 0; i < N; i++) {
        if (matchR[i] >= 0) {
            printf("(%d, %d)\n", matchR[i], i + M);
        }
    }
    printf("Maximum Matching Size: %d\n", result);

    printf("\nMaximal Matching Edges (Greedy Approach):\n");
    int max_match[3] = {-1, -1, -1};
    int x_matched[3] = {0};
    
    for (int u = 0; u < M; u++) {
        for (int v = 0; v < N; v++) {
            if (bpGraph[u][v] && max_match[v] == -1 && !x_matched[u]) {
                max_match[v] = u;
                x_matched[u] = 1;
                printf("(%d, %d)\n", u, v + M);
                break;
            }
        }
    }

    if (result == M && result == N) {
        printf("\nType: Perfect Matching Achieved\n");
    } else {
        printf("\nType: Perfect Matching Not Achieved\n");
    }

    return 0;
}