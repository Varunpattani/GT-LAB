#include <stdio.h>

int adj[4][4] = {
    {1,1,0,0},
    {1,1,0,0},
    {0,0,1,1},
    {0,0,1,1}
};

int visited[4] = {0};

void dfs(int v, int n)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i, n);
        }
    }
}

void main()
{
    int n = 4;
    int friendCircles = 0;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i, n);
            friendCircles++;
        }
    }

    printf("Total Friend Circles = %d", friendCircles);

}