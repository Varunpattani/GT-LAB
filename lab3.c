#include <stdio.h>

int adjMat[5][5] = {
    {0,1,1,0,0},
    {1,0,1,0,0},
    {1,1,0,1,1},
    {0,0,1,0,0},
    {0,0,1,0,0}
};

int visited[5] = {0};

void dfs(int current, int v)
{
    visited[current] = 1;
    printf("%d ", current);

    for(int i = 0; i < v; i++)
    {
        if(adjMat[current][i] == 1 && visited[i] == 0)
        {
            dfs(i, v);
        }
    }
}

void main()
{
    int v = 5;
    int start = 0;

    printf("DFS Traversal: ");

    dfs(start, v);
}