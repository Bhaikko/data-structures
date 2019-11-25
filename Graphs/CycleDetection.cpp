#include <iostream>
#include <list>

class Graph
{
    private:
        int vertices;
        std::list<int>* graph;

    private:
        bool isCyclic(int parent, bool* visited, int v);

    public: 
        Graph(int vertices);
        void add_edge(int v1, int v2);
        bool isCyclic();
};

Graph::Graph(int vertices)
{
    this->vertices = vertices;
    graph = new std::list<int>[this->vertices]();
}

void Graph::add_edge(int v1, int v2)
{
    this->graph[v1].push_back(v2);
    this->graph[v2].push_back(v1);
}

bool Graph::isCyclic(int parent, bool* visited, int currentVertex)
{
    visited[currentVertex] = true;

    std::list<int>::iterator i;
    for(i = this->graph[currentVertex].begin(); i != this->graph[currentVertex].end(); i++) {
        if (!visited[*i]) {
            if (this->isCyclic(currentVertex, visited, *i)) {
                return true;
            }
        } else if(*i != parent) {
            // If an adjacent is visited and not parent of current vertex, 
            // then there is a cycle. 
            return true;
        }
    }

    return false;
}

bool Graph::isCyclic()
{
    bool* visited = new bool[this->vertices];
    for(int i = 0; i < this->vertices; i++) {
        visited[i] = false;
    }

    for (int currentVertex = 0; currentVertex < this->vertices; currentVertex++) {
        if (!visited[currentVertex]) {
            if (this->isCyclic(-1, visited, currentVertex)) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    Graph* graph = new Graph(5);

    graph->add_edge(1, 0);
    graph->add_edge(2, 0);
    graph->add_edge(1, 2);
    graph->add_edge(3, 0);
    graph->add_edge(3, 4);

    std::cout << (graph->isCyclic() ? "Cyclic" : "Not Cyclic") << std::endl;

    Graph graph2(3); 
    graph2.add_edge(0, 1); 
    graph2.add_edge(1, 2); 
    std::cout << (graph2.isCyclic() ? "Cyclic" : "Not Cyclic") << std::endl;
    return 0;
}