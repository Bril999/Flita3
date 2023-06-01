#include "data.h"

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)calloc(vertices, sizeof(int));
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

bool isConnected(Graph *graph) {
    bool *visited = (bool *)calloc(graph->vertices, sizeof(bool));
    dfs(graph, 0, visited);

    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }
    free(visited);
    return true;
}

void dfs(Graph *graph, int vertex, bool *visited) {
    visited[vertex] = true;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

void visualizeGraph(Graph *graph) {
    FILE *dot_file = fopen("../graph.dot", "w");
    if (dot_file == NULL) {
        printf("Cannot create graph.dot file.\n");
        return;
    }

    fprintf(dot_file, "graph G {\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adjMatrix[i][j]) {
                fprintf(dot_file, "%d -- %d;\n", i, j);
                graph->adjMatrix[j][i] = 0; // Чтобы не выводить дублирующие ребра
            }
        }
    }
    fprintf(dot_file, "}\n");
    fclose(dot_file);
}