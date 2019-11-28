#include <iostream>
#include <stack>
#include <list>

class Graph
{
    private:

        int vertices;
        std::list<int>* graph;

        void topological_sort(int vertex, bool* isVisited, std::stack<int>* noDependency);

    public:
        Graph(int vertices);

        void add_edge(int v1, int v2);

        void topological_sort();

};

Graph::Graph(int vertices)
{
    this->vertices = vertices;
    this->graph = new std::list<int>[this->vertices]();
}

void Graph::add_edge(int v1, int v2)
{
    this->graph[v1].push_back(v2);
}

void Graph::topological_sort(int vertex, bool* isVisited, std::stack<int>* noDependency)
{
    isVisited[vertex] = true;

    std::list<int>::iterator i;

    for (i = this->graph[vertex].begin(); i != this->graph[vertex].end(); i++) {
        if (!isVisited[*i]) {
            this->topological_sort(*i, isVisited, noDependency);
        }
    }

    noDependency->push(vertex);

}

void Graph::topological_sort()
{
    std::stack<int>* noDependency = new std::stack<int>();

    bool* isVisited = new bool[this->vertices];
    for (int i = 0; i < this->vertices; i++) {
        isVisited[i] = false;
    }

    for (int currentVertex = 0; currentVertex < this->vertices; currentVertex++) {
        if (!isVisited[currentVertex]) {
            this->topological_sort(currentVertex, isVisited, noDependency);
        }
    }

    while (!noDependency->empty()) {
        std::cout << noDependency->top() << " ";
        noDependency->pop();
    }
}

int main()
{
    Graph graph(6);

    graph.add_edge(5, 2);
    graph.add_edge(5, 0);
    graph.add_edge(4, 0);
    graph.add_edge(4, 1);
    graph.add_edge(2, 3);
    graph.add_edge(3, 1);

    graph.topological_sort();

    return 0;
}
