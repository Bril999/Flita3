#include "data.h"

int main() {
    FILE *file;
    int src, dest;
    int max_vertex = 0;

    file = fopen("../filename.txt", "r");
    if (file == NULL) {
        printf("Cannot open the file.\n");
        return 1;
    }

    while (fscanf(file, "%d %d", &src, &dest) != EOF) {
        if (src > max_vertex) max_vertex = src;
        if (dest > max_vertex) max_vertex = dest;
    }
    fseek(file, 0, SEEK_SET);

    Graph *graph = createGraph(max_vertex + 1);

    while (fscanf(file, "%d %d", &src, &dest) != EOF) {
        addEdge(graph, src, dest);
    }
    fclose(file);

    visualizeGraph(graph);
    printf("The graph is %s connected.\n", isConnected(graph) ? "" : "not ");

    return 0;
}
