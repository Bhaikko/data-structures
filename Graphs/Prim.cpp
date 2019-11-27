#include <iostream>
#include <climits>

int minVertex(int* weights, bool* isVisited, int vertices)
{
    int minIndex = -1;

    for (int currentVertex = 0; currentVertex < vertices; currentVertex++) {
        if (!isVisited[currentVertex] && (minIndex == -1 || weights[currentVertex] < weights[minIndex])) {
            minIndex = currentVertex;
        }
    }

    return minIndex;
}

void prim(int** graph, int vertices)
{
    bool* isVisited = new bool[vertices];
    int* parents = new int[vertices];
    int* weights = new int[vertices];

    for(int i = 0; i < vertices; i++) {
        weights[i] = INT_MAX;
        isVisited[i] = false;
    }

    parents[0] = -1;
    weights[0] = 0;

    for (int currentVertex = 0; currentVertex < vertices - 1; currentVertex++) {
        int vertex = minVertex(weights, isVisited, vertices);
        isVisited[vertex] = true;

        for (int i = 0; i < vertices; i++) {
            if (graph[vertex][i] && !isVisited[i]) {
                if (graph[vertex][i] < weights[i]) {
                    weights[i] = graph[vertex][i];
                    parents[i] = vertex;
                }
            }
        }

    }

    // Printing MST
    for (int i = 1; i < vertices; i++) {
        if (parents[i] < i) {
            std::cout << parents[i] << " " << i << " " << weights[i] << std::endl;
        } else {
            std::cout << i << " " << parents[i] << " " << weights[i] << std::endl;
        }
    }
}

int main()
{
    int vertices, edges;
    std::cin >> vertices >> edges;  
    int** graph = new int*[vertices];

    for (int i = 0; i < vertices; i++) {
        graph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 1; i <= edges; i++) {
        int e1, e2, weight;
        std::cin >> e1 >> e2 >> weight;
        graph[e1][e2] = weight;
        graph[e2][e1] = weight;
    }



    prim(graph, vertices);

    /*
        SAMPLE INPUT
        6 8
        0 1 2
        0 2 4
        1 2 1
        1 3 7
        2 4 3 
        3 4 2 
        3 5 1
        4 5 5
    */

}