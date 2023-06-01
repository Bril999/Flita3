#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения графа
typedef struct Graph {
    int vertices;
    int **adjMatrix;
} Graph;

Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
bool isConnected(Graph *graph);
void dfs(Graph *graph, int vertex, bool *visited);
void visualizeGraph(Graph *graph);