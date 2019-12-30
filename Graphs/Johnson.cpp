// Implementation of Johnson's algorithm in C++

#include <iostream>
#include <climits>
#include <vector>

// Edge class to store source, destination, weight in Edge object for bellford algorithm
class Edge
{
    public:
        int source;
        int destination;
        int weight;

        Edge(int source, int destination, int weight) {
            this->source = source;
            this->weight = weight;
            this->destination = destination;

        }
};

// Returns the vertex with minimum distance from source
int minVertex(int* distances, bool* isVisited, int vertices)
{
    int minimum = INT_MAX;
    int minVertex = -1;

    for (int vertex = 0; vertex < vertices; vertex++) {
        if (!isVisited[vertex] && distances[vertex] <= minimum) {
            minimum = distances[vertex];
            minVertex = vertex;
        }
    }

    return minVertex;
}

// Dijkstra algorithm for modified graph independent of negative edges
void dijkstra(int** graph, int** modifiedGraph, int vertices, int source) 
{
    // isVisted array that keep tracks of all vertices being visited or not
    bool* isVisited = new bool[vertices];

    // Shortest distance of all vertices from the source
    int* distances = new int[vertices];

    // Initialising both above arrays
    for (int i = 0; i < vertices; i++) {
        isVisited[i] = false;
        distances[i] = INT_MAX;
    }

    distances[source] = 0;

    for (int i = 0; i < vertices; i++) {
        // The current vertex which is at min Distance 
		// from the source and not yet included in the 
		// shortest path tree 
        int currentVertex = minVertex(distances, isVisited, vertices);
        isVisited[currentVertex] = true;

        for (int j = 0; j < vertices; j++) {
            if (!isVisited[j] && (distances[j] > distances[currentVertex] + modifiedGraph[currentVertex][j]) && graph[currentVertex][j]) {
                distances[j] = distances[currentVertex] + modifiedGraph[currentVertex][j];
            }
        }
    }


    // Print the shortest distance of all vertices from source
    for (int i = 0; i < vertices; i++) {
        distances[i] == INT_MAX ? 
            std::cout << "Vertex " << i << ": " << "inf" << std::endl :
            std::cout << "Vertex " << i << ": " << distances[i] << std::endl;
    }

    std::cout << std::endl;

}


// Function to calculate shortest distances from source 
// to all other vertices using Bellman-Ford algorithm 
int* bellmanFord(int** graph, std::vector<Edge*>* edgesList, int vertices)
{
    // Add a source s and calculate its min 
	// distance from every other node 
    int* modifiedDistances = new int[vertices + 1];
    for (int i = 0; i <= vertices; i++) {
        modifiedDistances[i] = INT_MAX;
    }
    modifiedDistances[vertices] = 0;

    for (int i = 0; i < vertices; i++) {
        Edge* newEdge = new Edge(vertices, i, 0);
        edgesList->push_back(newEdge);
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < edgesList->size(); j++) {
            int currentSource = edgesList->at(j)->source;
            int currentDestination = edgesList->at(j)->destination;
            int currentWeight = edgesList->at(j)->weight;

            if (modifiedDistances[currentSource] != INT_MAX && modifiedDistances[currentSource] + currentWeight < modifiedDistances[currentDestination]) {
                modifiedDistances[currentDestination] = modifiedDistances[currentSource] + currentWeight;
            }
        }
    }

    return modifiedDistances;
}

void johnson(int** graph, int vertices)
{
    std::vector<Edge*>* edgesList = new std::vector<Edge*>();

    // Create list of edges for Bellman-Ford Algorithm
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j]) {
                Edge* newEdge = new Edge(i, j, graph[i][j]);
                edgesList->push_back(newEdge);
            }
        }
    }

    // weights used to modify the original weights
    int* modifiedWeights = bellmanFord(graph, edgesList, vertices);

    // Create modifiedGraph having zero weights for all edges
    int** modifiedGraph = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        modifiedGraph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            modifiedGraph[i][j] = 0;
        }
    }

    // Modify the weights to get rid of negative weights
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j]) {
                modifiedGraph[i][j] = graph[i][j] + modifiedWeights[i] - modifiedWeights[j];
            }
        }
    }

    // Modified Graph Print
    std::cout << "Modified Graph" << std::endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            std::cout << modifiedGraph[i][j] << " ";            
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Dijkstra on modified graph for each vertex as source one by one
    for (int i = 0; i < vertices; i++) {
        std::cout << "Shortest distance with vertex " << i << " as source: " << std::endl;
        dijkstra(graph, modifiedGraph, vertices, i);
    }
    
}

int main()
{
    int vertices = 4;
    int** graph = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        graph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    /*
        [[0, -5, 2, 3], 
        [0, 0, 4, 0], 
        [0, 0, 0, 1], 
        [0, 0, 0, 0]] 
    */

    graph[0][1] = -5;
    graph[0][2] = 2;
    graph[0][3] = 3;
    graph[1][2] = 4;
    graph[2][3] = 1;

    johnson(graph, vertices);

    return 0;
}
