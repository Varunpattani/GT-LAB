#include <stdio.h>

#define V 6

int adj[V][V] = {
    {0,1,0,0,0,0},
    {1,0,1,1,0,0},
    {0,1,0,0,0,0},
    {0,1,0,0,1,1},
    {0,0,0,1,0,0},
    {0,0,0,1,0,0}
};

void bfs(int start, int dist[])
{
    int visited[V] = {0};
    int q[V];
    int f = 0, r = 0;

    for(int i=0;i<V;i++)
        dist[i] = -1;

    visited[start] = 1;
    dist[start] = 0;
    q[r++] = start;

    while(f < r)
    {
        int curr = q[f++];

        for(int i=0;i<V;i++)
        {
            if(adj[curr][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                dist[i] = dist[curr] + 1;
                q[r++] = i;
            }
        }
    }
}

void main()
{
    int degree[V] = {0};
    int dist[V][V];
    int eccentricity[V];

    printf("1. Pendent (Leaf) Vertices:\n");

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            degree[i] += adj[i][j];

        if(degree[i] == 1)
            printf("%d ", i);
    }

    printf("\n\n2. Degree of Each Vertex:\n");
    for(int i=0;i<V;i++)
        printf("Vertex %d = %d\n", i, degree[i]);

    printf("\n3. Distance Matrix:\n");

    for(int i=0;i<V;i++)
        bfs(i, dist[i]);

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }

    printf("\n4. Eccentricity of Each Vertex:\n");

    for(int i=0;i<V;i++)
    {
        int max = 0;

        for(int j=0;j<V;j++)
        {
            if(dist[i][j] > max)
                max = dist[i][j];
        }

        eccentricity[i] = max;
        printf("Vertex %d = %d\n", i, max);
    }

    int minEcc = eccentricity[0];

    for(int i=1;i<V;i++)
    {
        if(eccentricity[i] < minEcc)
            minEcc = eccentricity[i];
    }

    printf("\n5. Center of Tree:\n");

    for(int i=0;i<V;i++)
    {
        if(eccentricity[i] == minEcc)
            printf("%d ", i);
    }

    int edges = 0;

    for(int i=0;i<V;i++)
    {
        for(int j=i+1;j<V;j++)
        {
            if(adj[i][j] == 1)
                edges++;
        }
    }

    printf("\n\n6. Tree Verification:\n");

    if(edges == V - 1)
        printf("Given graph is a Tree\n");
    else
        printf("Given graph is NOT a Tree\n");
}