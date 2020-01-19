#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

int** allocateGraph(int vertices)
{
    int** graph = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        graph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    return graph;
}

bool bfs(int** graph, int source, int sink, int* parents, int vertices)
{
    bool* isVisited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        isVisited[i] = false;
    }

    std::queue<int>* pending = new std::queue<int>();
    pending->push(source);
    isVisited[source] = true;
    parents[source] = -1;

    while (!pending->empty())
    {
        int current = pending->front();
        pending->pop();

        for (int i = 0; i < vertices; i++) {
            if (!isVisited[i] && graph[current][i]) {
                pending->push(i);
                parents[i] = current;
                isVisited[i] = true;
            }
        }

    }
    
    return isVisited[sink];
}

int fordFulkerson(int** graph, int vertices, int source, int sink)
{
    int u, v;

    int** residualGraph = allocateGraph(vertices);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            residualGraph[i][j] = graph[i][j];
        }
    }

    int* parents = new int[vertices];

    int maxFlow = 0;

    while (bfs(residualGraph, source, sink, parents, vertices)) {
        int pathFlow = INT_MAX;
        for (v = sink; v != source; v = parents[v]) {
            u = parents[v];
            pathFlow = std::min(pathFlow, residualGraph[u][v]);
        }

        for (v = sink; v != source; v = parents[v]) {
            u = parents[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    int vertices = 6;
    int** graph = allocateGraph(vertices);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            std::cin >> graph[i][j];
        }
    }

    /*
        0 16 13 0 0 0
        0 0 10 12 0 0
        0 4 0 0 14 0
        0 0 9 0 0 26
        0 0 0 7 0 4
        0 0 0 0 0 0
    */

    std::cout << "Max Flow: " << fordFulkerson(graph, vertices, 0, 5) << std::endl;
    return 0;
}