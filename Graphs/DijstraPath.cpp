#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Neighbor {
    int dest;
    ll weight;
};

struct Vertex {
    vector<Neighbor*> neighbors;
    int source;
    ll distance;
};

struct CompareDistance {
    bool operator()(Vertex* a, Vertex* b) {
        return a->distance >= b->distance;
    }
};

void Dijsktra(Vertex* graph[], int source, int n, bool isVisited[]) 
{
    graph[source]->distance = 0;

    priority_queue<Vertex*, vector<Vertex*>, CompareDistance> pending;
    pending.push(graph[source]);

    while (!pending.empty()) {
        Vertex* minVertex = pending.top();    
        pending.pop();

        if (isVisited[minVertex->source]) {
            continue;
        }

        isVisited[minVertex->source] = true;

        for (unsigned int i = 0; i < minVertex->neighbors.size(); i++) {
            
            Neighbor* neighbor = minVertex->neighbors[i];
            Vertex* neighborVertex = graph[neighbor->dest];

            ll distance = minVertex->distance + neighbor->weight;

            if (distance < neighborVertex->distance) {
                graph[neighbor->dest]->distance = distance;
                pending.push(neighborVertex);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << graph[i]->distance << " ";
    }

}

void solution()
{
    int n, m;
    cin >> n >> m;

    Vertex* graph[n + 1];

    for (int i = 1; i <= n; i++) {
        graph[i] = new Vertex();
        graph[i]->source = i;
        graph[i]->distance = LLONG_MAX;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;

        cin >> a >> b >> c;

        Neighbor* neighbor = new Neighbor();
        neighbor->dest = b;
        neighbor->weight = c;

        graph[a]->neighbors.push_back(neighbor);
    }

    bool isVisited[n + 1];
    for (int i = 1; i <= n; i++) {
        isVisited[i] = false;
    }

    Dijsktra(graph, 1, n, isVisited);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}