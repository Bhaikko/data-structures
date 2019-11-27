#include <iostream>
#include <climits>

// THIS CODE IS USED TO PRINT SHORTEST DISTANCE FROM SOURCE TO EACH VERTEX

// This can be optimised through priority queue
int minDistanceVertex(int* distances, bool* isVisited, int vertices)
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int currentVertex = 0; currentVertex < vertices; currentVertex++) {
        if (!isVisited[currentVertex] && distances[currentVertex] <= min) {
            min = distances[currentVertex];
            minIndex = currentVertex;
        }
    }

    return minIndex;
}

void dijkstra(int** graph, int vertices, int source)
{
       
    bool* isVisited = new bool[vertices];
    int* distances = new int[vertices];

    for (int i = 0; i < vertices; i++) {
        distances[i] = INT_MAX;
        isVisited[i] = false;
    } 

    distances[source] = 0;

    for (int count = 0; count < vertices; count++) {
        int currentVertex = minDistanceVertex(distances, isVisited, vertices);
        isVisited[currentVertex] = true;

        for (int vertex = 0; vertex < vertices; vertex++) {
            if (!isVisited[vertex] && graph[vertex][currentVertex]) {
                int distance = graph[vertex][currentVertex] + distances[currentVertex];

                if (distance < distances[vertex]) {
                    distances[vertex] = distance;
                }
            }
        }
    }

    // Printing solution
    for (int i = 0; i < vertices; i++) {
        std::cout << "Distance from " << source << " To " << i << " : " << distances[i] << std::endl;
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



    dijkstra(graph, vertices, 0);

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
