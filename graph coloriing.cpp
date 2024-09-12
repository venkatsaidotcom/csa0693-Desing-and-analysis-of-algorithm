#include <stdio.h>

#define V 4

int isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return 0;
    return 1;
}

int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) return 1;

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3;
    int color[V] = {0};

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists: \n");
        for (int i = 0; i < V; i++)
            printf("Vertex %d ---> Color %d\n", i, color[i]);
    } else {
        printf("Solution does not exist\n");
    }

    return 0;
}

