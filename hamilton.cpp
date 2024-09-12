#include <stdio.h>
#include <stdbool.h>

#define V 4

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };

    int path[V];
    for (int i = 0; i < V; i++) path[i] = -1;

    path[0] = 0; // Start from the first vertex
    bool found = false;

    int pos = 1;
    while (pos < V) {
        bool safe = true;
        if (graph[path[pos - 1]][pos] == 0) safe = false;

        for (int i = 0; i < pos; i++) {
            if (path[i] == pos) {
                safe = false;
                break;
            }
        }

        if (safe) {
            path[pos] = pos;
            pos++;
        } else {
            path[pos] = -1;
            pos--;
        }

        if (pos == V) {
            if (graph[path[V - 1]][path[0]] == 1) {
                found = true;
                break;
            }
            path[V - 1] = -1;
            pos--;
        }
    }

    if (found) {
        printf("Hamiltonian Circuit found:\n");
        for (int i = 0; i < V; i++)
            printf(" %d ", path[i]);
        printf(" %d\n", path[0]); // Print the first vertex to complete the circuit
    } else {
        printf("No Hamiltonian Circuit found\n");
    }

    return 0;
}

