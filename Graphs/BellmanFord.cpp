#include <iostream>
#include <climits>

class Edge 
{
    public:
        int source;
        int destination;
        int weight;
};

void bellmanford(Edge* graph, int source, int vertices, int edges)
{
    int* distances = new int[vertices];

    for (int i = 0; i < vertices; i++) {
        distances[i] = INT_MAX;
    }

    distances[source] = 0;

    // each edge is relaxed n(vertices) - 1 times
    for (int count = 1; count <= vertices - 1; count++) {
        for (int edge = 0; edge < edges; edge++) {
            int u = graph[edge].source;
            int v = graph[edge].destination;
            int weight = graph[edge].weight;

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    for (int i = 0; i < edges; i++) {
        int u = graph[i].source;
        int v = graph[i].destination;

        int weight = graph[i].weight;

        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            std::cout << "Graph Contains A Negative Cycle" << std::endl;
            return;
        }
    }

    // Printing solution
    for (int i = 0; i < vertices; i++) {
        std::cout << "Distance from " << source << " To " << i << " : " << distances[i] << std::endl;
    }
}

int main()
{
    int v, e;
    std::cin >> v >> e;

    Edge* graph = new Edge[e];

    /*

        5 8
        0 2 4
        0 1 -1
        1 2 3
        3 2 5
        3 1 1
        1 3 2
        1 4 -2
        4 3 -3

    */

    for (int i = 0; i < e; i++) {
        int source, destination, weight;
        std::cin >> source >> destination >> weight;

        graph[i].source = source;
        graph[i].destination = destination;
        graph[i].weight = weight;      

    }

    bellmanford(graph, 0, v, e);
    return 0;
}