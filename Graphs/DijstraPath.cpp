#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Neighbor {
    int dest;
    int weight;
};

struct Vertex {
    vector<Neighbor> neighbors;
    int source;
    int distance;
};

struct CompareDistance {
    bool operator()(Vertex const& a, Vertex const& b) {
        return a.distance >= b.distance;
    }
};

void Dijsktra(Vertex graph[], int source, int n, bool isVisited[]) 
{
    graph[source].distance = 0;

    priority_queue<Vertex, vector<Vertex>, CompareDistance> pending;
    pending.push(graph[source]);

    // for (int i = 1; i <= n; i++) {
    while (!pending.empty()) {
        Vertex minVertex = pending.top();    
        pending.pop();

        isVisited[minVertex.source] = true;

        cout << minVertex.source << endl;

        for (int i = 0; i < minVertex.neighbors.size(); i++) {
            
            Neighbor neighbor = minVertex.neighbors[i];
            // cout << neighbor.dest << " ";
            Vertex neighborVertex = graph[neighbor.dest];

            int distance = minVertex.distance + neighbor.weight;
            printf("%i %i %i\n", minVertex.distance, neighbor.weight, distance);
            if (distance < neighborVertex.distance) {
                graph[neighbor.dest].distance = distance;
            }

            cout << neighborVertex.source << endl;
            if (!isVisited[neighborVertex.source]) {
                pending.push(neighborVertex);
            }
        }

        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        cout << graph[i].distance << " ";
    }

}

void solution()
{
    int n, m;
    cin >> n >> m;

    Vertex graph[n + 1];

    for (int i = 1; i <= n; i++) {
        graph[i].source = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        Neighbor neighbor;
        neighbor.dest = b;
        neighbor.weight = c;

        // graph[a].source = a;
        graph[a].neighbors.push_back(neighbor);
        graph[a].distance = INT_MAX;
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