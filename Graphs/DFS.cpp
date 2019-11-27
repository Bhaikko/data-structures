#include <iostream>

void dfs(int** graph, int vertices, int currentVertex, bool* isVisited)
{
    std::cout << currentVertex << " ";
    isVisited[currentVertex] = true;

    for (int i = 0; i < vertices; i++) {
        if (graph[currentVertex][i] && !isVisited[i]) {
            isVisited[i] = true;
            dfs(graph, vertices, i, isVisited);
        }
    }
}

void dfs(int** graph, int vertices)
{
    bool* isVisited = new bool[vertices];

    for(int i = 0; i < vertices; i++) {
        isVisited[i] = false;
    }

    for (int i = 0; i < vertices; i++) {
        if (!isVisited[i]) {
            dfs(graph, vertices, i, isVisited);
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
    }

    for (int i = 1; i <= edges; i++) {
        int e1, e2;
        std::cin >> e1 >> e2;
        graph[e1][e2] = 1;
        graph[e2][e1] = 1;
    }

    dfs(graph, vertices);

    /*
        SAMPLE INPUT
        10 11
        0 1
        0 4
        0 6
        1 5
        1 2
        1 3
        2 3
        5 6
        7 8
        7 9
        8 9
    */

}