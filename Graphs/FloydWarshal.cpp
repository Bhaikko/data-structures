#include <iostream>
#include <climits>

void floydWarshall (int** graph, int vertices)
{
    int** distances = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        distances[i] = new int[vertices];
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            distances[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }


    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            std::cout << distances[i][j] << " ";
        }

        std::cout << std::endl;
    }
    
}

int main()
{
    int vertices;
    std::cin >> vertices;
    int** graph = new int*[vertices];

    for (int i = 0; i < vertices; i++) {
        graph[i] = new int[vertices];
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            std::cin >> graph[i][j];
        }
    }

    /*
        4
        0 3 999999 7
        8 0 2 999999
        5 999999 0 1
        2 999999 999999 0
    */

    floydWarshall(graph, vertices);
    return 0;


}