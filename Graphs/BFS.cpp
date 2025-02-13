#include <iostream>
#include <queue>

// bfs for graph having disjoint graphs
void bfs(int** graph, int vertices, int start, bool* isVisited)
{
    std::queue<int>* pending = new std::queue<int>();
    pending->push(start);  
    isVisited[start] = true; 

    while(!pending->empty()) {

        int currentVertex = pending->front();
        pending->pop();

        std::cout << currentVertex << " ";

        for(int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !isVisited[i]) {
                isVisited[i] = true;
                pending->push(i);
            }
        }
    }

    delete pending;

}

void bfs(int** graph, int vertices) 
{

    bool* isVisited = new bool[vertices];

    for(int i = 0; i < vertices; i++) {
        isVisited[i] = false;
    }

    for (int i = 0; i < vertices; i++) {
        if (!isVisited[i]) {
            bfs(graph, vertices, i, isVisited);
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

    bfs(graph, vertices);

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