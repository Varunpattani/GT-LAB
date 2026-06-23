#include <stdio.h>

int adjList[5][5] = {
    {1,2},
    {0,2},
    {0,1,3,4},
    {2},
    {2}
};

int v = 5;

int size[5] = {2,2,4,1,1};
int visited[5] = {0};

void dfs(int current){
    visited[current] = 1;
    printf("%d ",current);
    for(int i=0;i<size[current];i++){
        if(!visited[adjList[current][i]]) dfs(adjList[current][i]);
    }
}

void main(){
    int start = 0;
    dfs(start);
}
