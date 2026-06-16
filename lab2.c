#include <stdio.h>

void main()
{
    int v = 5;
    // Adjacency matrix for:
    // [[1,2], [0,2,3], [0,1,4], [1,4], [2,3]]

    int adjMat[5][5] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };

    int visited[5] = {0};
    int que[5];
    int f = 0, r = 0;

    
    visited[0] = 1;
    que[r++] = 0;

    printf("BFS Traversal: ");

    while(f < r)
    {
        int current = que[f++];

        printf("%d ", current);

        for(int i = 0; i < v; i++)
        {
            if(adjMat[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                que[r++] = i;
            }
        }
    }

}