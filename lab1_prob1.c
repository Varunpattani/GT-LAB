// Problem  1:  Given  the  number  of  vertices  and  edges  of  a  graph,  the  task  is  to  represent  the  adjacency  list  of a 
// directed graph. 
// Input: V=3, edges[][]={{0,1},{1,2},{2,0}}  
// Output:  
// 0 -> 1 
// 1 -> 2 
// 2 -> 0 
// Input: V=4, edges[][]={{0,1},{1,2},{1,3},{2,3},{3,0}} 
// Output:  
// 0 -> 1 
// 1 -> 2 3 
// 2 -> 3 
// 3 -> 0


#include <stdio.h>

void main()
{   
    int v, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int edges[e][2];
    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    for (int i = 0; i < v; i++) {
        printf("%d -> ", i);
        for (int j = 0; j < e; j++) {
            if (edges[j][0] == i) {
                printf("%d ", edges[j][1]);
            }
        }
        printf("\n");
    }
}