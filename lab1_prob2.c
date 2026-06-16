// Problem 2: Write a program to perform the following basic graph-related operations: 
// 1. Represent a graph using adjacency matrix. 
// 2. Represent a graph using adjacency list. 
// 3. Find the degree of each vertex in the graph. 
// 4. Determine whether the graph is simple, complete, or connected. 
// 5. Display total number of vertices and edges.

#include <stdio.h>

void main()
{
    int v, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int adjMat[v][v];


    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    printf("Enter the edges (source destination):\n");

    for(int i = 0; i < e; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);

        adjMat[src][dest]++;
        adjMat[dest][src]++;   
    }

    printf("\nAdjacency Matrix:\n");

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }

    printf("\nAdjacency List:\n");
    for(int i = 0; i < v; i++)
    {
        printf("%d -> ", i);

        for(int j = 0; j < v; j++)
        {
            if(adjMat[i][j] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    printf("\nDegree of each Vertex:\n");
    for(int i = 0; i < v; i++)
    {
        int degree = 0;

        for(int j = 0; j < v; j++)
        {
            degree += adjMat[i][j];
        }

        printf("Vertex %d = %d\n", i, degree);
    }

    int isSimple = 1;
    for(int i = 0; i < v; i++)
    {
        if(adjMat[i][i] != 0)       
        {
            isSimple = 0;
            break;
        }
        for(int j = i + 1; j < v; j++)
        {
            if(adjMat[i][j] > 1)     
            {
                isSimple = 0;
                break;
            }
        }
        if(!isSimple) break;
    }
    printf("\nSimple Graph   : %s\n", isSimple ? "Yes" : "No");

    int isComplete = isSimple;
    if(isComplete)
    {
        for(int i = 0; i < v; i++)
        {
            int degree = 0;
            for(int j = 0; j < v; j++)
                degree += adjMat[i][j];
            if(degree != v - 1)
            {
                isComplete = 0;
                break;
            }
        }
    }
    printf("Complete Graph : %s\n", isComplete ? "Yes" : "No");

    int visited[v], que[v];
    int f = 0, r = 0;
    for(int i = 0; i < v; i++) visited[i] = 0;

    visited[0] = 1;
    que[r++] = 0;

    while(f < r)
    {
        int node = que[f++];
        for(int j = 0; j < v; j++)
            if(adjMat[node][j] > 0 && !visited[j])  
            {
                visited[j] = 1;
                que[r++] = j;
            }
    }

    int isConnected = 1;
    for(int i = 0; i < v; i++)
        if(!visited[i]) { isConnected = 0; break; }

    printf("Connected Graph: %s\n", isConnected ? "Yes" : "No");


    printf("\nTotal Vertices : %d\n", v);
    printf("Total Edges    : %d\n", e);

    
}