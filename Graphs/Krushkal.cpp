#include <iostream>
#include <algorithm>
#include <vector>

class Edge
{
    public: 
        int source;
        int destination;
        int weight;
};

int findParent(int vertex, int* parents) 
{
    if (parents[vertex] == vertex) {
        return vertex;
    }

    return findParent(parents[vertex], parents);
}

void krushkal(Edge* graph, int edges, int vertices)
{
    std::sort(graph, graph + edges, [](Edge a, Edge b) -> bool { return a.weight < b.weight; });

    std::vector<Edge>* mst = new std::vector<Edge>();
    int* parents = new int[vertices];

    for (int i = 0; i < vertices; i++) {
        parents[i] = i;
    }

    int count = 0;
    int edgeIndex = 0;

    while (count != vertices - 1) {
        Edge currentEdge = graph[edgeIndex];

        int sourceParent = findParent(currentEdge.source, parents);
        int destinationParent = findParent(currentEdge.destination, parents);

        // cycle detection test
        if (sourceParent != destinationParent) {
            mst->push_back(currentEdge);
            count++;
            parents[sourceParent] = destinationParent;
        }

        edgeIndex++;
    }

    // printing MST
    for (int i = 0; i < mst->size(); i++) {
        std::cout << mst->at(i).source << " " << mst->at(i).destination << " " << mst->at(i).weight << std::endl;
    }

}

int main()
{
    int vertices, edges;
    std::cin >> vertices >> edges;

    Edge* graph = new Edge[edges]();


    for (int i = 0; i < edges; i++) {
        int source, destination, weight;
        std::cin >> source >> destination >> weight;
        graph[i].source = source;
        graph[i].destination = destination;
        graph[i].weight = weight;
    }

    /*
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


    krushkal(graph, edges, vertices);

    return 0;
}