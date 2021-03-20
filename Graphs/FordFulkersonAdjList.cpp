#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int src;
    int dest;
    int forwardFlow;
    int backwardFlow;   // Residual Capacity
};

string GetKey(int a, int b) {
    return "(" + to_string(a) + ", " + to_string(b) + ")";
}

// To Find Augmented Path based on Residual Flow and Graph Connectivity
bool BFS(vector<Edge*> graph[], int n, int source, int sink, int parents[])
{
    bool isVisited[n + 1];

    for (int i = 1; i <= n; i++) {
        isVisited[i] = false;
    }

    queue<int> pending;
    pending.push(source);
    isVisited[source] = true;
    parents[source] = -1;
    
    while (!pending.empty()) {
        int u = pending.front();
        pending.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i]->dest;


            if (!isVisited[v] && graph[u][i]->forwardFlow > 0) {
                if (v == sink) {
                    // Augmented Path Found
                    parents[v] = u;
                    return true;
                }

                pending.push(v);
                parents[v] = u;
                isVisited[v] = true;

            }
        }
    }

    // No More Augmented paths exist
    return false;
}

void FordFulkerson()
{
    int n, m;
    cin >> n >> m;

    int source, sink;
    // cin >> source >> sink;
    source = 1;
    sink = n;

    vector<Edge*> graph[n + 1];
    unordered_map<string, Edge*> edges;
    int parents[n + 1];
    bool isVisited[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b, flow;
        cin >> a >> b >> flow;

        Edge* newEdge = new Edge();
        newEdge->src = a;
        newEdge->dest = b;
        newEdge->forwardFlow = flow;
        newEdge->backwardFlow = 0;

        edges[GetKey(a, b)] = newEdge;

        graph[a].push_back(newEdge);
    }

    for (int i = 1; i <= n; i++) {
        parents[i] = -1;
    }

    int maxFlow = 0;

    while (BFS(graph, n, source, sink, parents)) {
        int pathFlow = INT_MAX;
        
        // Finding Bottleneck in Current Augmented Path
        for (int v = sink; v != source; v = parents[v]) {
            int u = parents[v];
            pathFlow = min(pathFlow, edges[GetKey(u, v)]->forwardFlow);
        }

        // Update the Residual Capacities of Current Augmented Path
        for (int v = sink; v != source; v = parents[v]) {
            int u = parents[v];

            Edge* currentEdge = edges[GetKey(u, v)];

            currentEdge->forwardFlow -= pathFlow;
            currentEdge->backwardFlow += pathFlow;
        }

        maxFlow += pathFlow;
    }

    cout << maxFlow << endl;

}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    FordFulkerson();

    return 0;
}

/*
7 11
1 2 3
3 1 3
2 4 3
3 5 2
4 5 2
3 4 1
1 4 3
5 2 1
4 6 6
6 7 9
5 7 1

*/