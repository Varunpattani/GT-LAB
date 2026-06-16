#include <stdio.h>

void print_edge(int u, int v) {
    if (u < v) {
        printf("(%d,%d)", u, v);
    } else {
        printf("(%d,%d)", v, u);
    }
}

int main() {
    int V = 5;
    int E = 6;
    int edges[6][2] = {{0,1}, {0,2}, {1,2}, {1,3}, {2,4}, {3,4}};

    int branches[10][2];
    int num_branches = 0;
    
    int chords[10][2];
    int num_chords = 0;

    int parent[10];
    for (int i = 0; i < V; i++) {
        parent[i] = i; 
    }

    int tree_adj[10][10] = {0};

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int root_u = u;
        while (parent[root_u] != root_u) {
            root_u = parent[root_u];
        }
        
        int root_v = v;
        while (parent[root_v] != root_v) {
            root_v = parent[root_v];
        }

        if (root_u != root_v) {
            parent[root_u] = root_v;
            
            branches[num_branches][0] = u;
            branches[num_branches][1] = v;
            num_branches++;

            tree_adj[u][v] = 1;
            tree_adj[v][u] = 1;
        } else {
            chords[num_chords][0] = u;
            chords[num_chords][1] = v;
            num_chords++;
        }
    }

    printf("Output:\nBranches:\n");
    for (int i = 0; i < num_branches; i++) {
        printf("(%d,%d)\n", branches[i][0], branches[i][1]);
    }

    printf("\nChords:\n");
    for (int i = 0; i < num_chords; i++) {
        printf("(%d,%d)\n", chords[i][0], chords[i][1]);
    }

    printf("\nFundamental Circuits:\n");
    for (int c = 0; c < num_chords; c++) {
        int start = chords[c][0];
        int end = chords[c][1];

        int stack[20];
        int top = 0;
        int visited[10] = {0};
        int parent_node[10];
        
        for(int i = 0; i < V; i++) parent_node[i] = -1;

        stack[top++] = start;
        visited[start] = 1;

        while (top > 0) {
            int curr = stack[--top];

            if (curr == end) break;

            for (int i = 0; i < V; i++) {
                if (tree_adj[curr][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    parent_node[i] = curr;
                    stack[top++] = i;
                }
            }
        }

        printf("C%d = {", c + 1);

        int curr = end;
        int is_first = 1;
        while (curr != start) {
            int p = parent_node[curr];
            if (!is_first) printf(",");
            print_edge(p, curr);
            curr = p;
            is_first = 0;
        }

        printf(",");
        print_edge(start, end);
        printf("}\n");
    }

    int rank = V - 1;
    int nullity = E - V + 1;

    printf("\nRank of Graph = %d\n", rank);
    printf("Nullity of Graph = %d\n", nullity);

    printf("\n--- Verification ---\n");
    printf("Number of branches (%d) == Rank (%d) -> %s\n", num_branches, rank, (num_branches == rank) ? "Verified" : "Failed");
    printf("Number of chords (%d) == Nullity (%d) -> %s\n", num_chords, nullity, (num_chords == nullity) ? "Verified" : "Failed");

    return 0;
}