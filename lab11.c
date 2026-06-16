#include <stdio.h>

int main() {
    int nX = 3;
    int nY = 3;
    
    int adj[3][3] = {
        {1, 1, 0},
        {1, 0, 0},
        {0, 1, 0}
    };

    int satisfies_hall = 1;
    int total_subsets = 1 << nX;

    for (int i = 1; i < total_subsets; i++) {
        int size_W = 0;
        int size_NW = 0;
        int neighbors[10] = {0};

        for (int j = 0; j < nX; j++) {
            if (i & (1 << j)) {
                size_W++;
                for (int k = 0; k < nY; k++) {
                    if (adj[j][k] == 1) {
                        neighbors[k] = 1;
                    }
                }
            }
        }

        for (int k = 0; k < nY; k++) {
            if (neighbors[k] == 1) {
                size_NW++;
            }
        }

        if (size_NW < size_W) {
            satisfies_hall = 0;
            break;
        }
    }

    if (satisfies_hall) {
        printf("Hall's condition satisfied\n");
    } else {
        printf("Hall's condition not satisfied\n");
    }

    return 0;
}