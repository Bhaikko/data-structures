#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool GraphHasEulerianPath(int in[], int out[], int n)
{
    int startNodes = 0,
        endNodes = 0;

    for (int i = 1; i <= n; i++) {
        if (out[i] - in[i] > 1 || in[i] - out[i] > 1) {
            return false;
        } else if (out[i] - in[i] == 1) {
            startNodes++;
        } else if (in[i] - out[i] == 1) {
            endNodes++;
        }
    } 

    return 
        (endNodes == 0 && startNodes == 0) ||
        (endNodes == 1 && startNodes == 1);
}

int FindStartNode(int in[], int out[], int n)
{
    int start = 1;
    for (int i = 1; i <= n; i++) {
        if (out[i] - in[i] == 1) {
            // unique Starting Node
            return i;
        }

        // Start Ay any node with an outgoing Edge
        if (out[i] > 0) {
            start = i;
        }
    }

    return start;
}

void DFS(vector<int> graph[], int currentVertex, int out[], int n, stack<int>& path)
{
    while (out[currentVertex] != 0) {
        int neighbor = graph[currentVertex][--out[currentVertex]];
        DFS(graph, neighbor, out, n, path);
    }

    path.push(currentVertex);
}

// Finding Eulerian Circuit in Directed Graph
void HeirHolzer()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    // In and Out Degree Arrays
    int in[n + 1], 
        out[n + 1];

    // Counting In and Out Degrees
    for (int i = 1; i <= n; i++) {
        in[i] = 0;
        out[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        out[i] = graph[i].size();
        for (int j = 0; j < graph[i].size(); j++) {
            in[graph[i][j]]++;
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     printf("%i %i %i \n", i, in[i], out[i]);
    // }

    if (!GraphHasEulerianPath(in, out, n)) {
        cout << "Not Possible" << endl;
        return;
    }

    int startNode = FindStartNode(in, out, n);
    stack<int> path;

    DFS(graph, startNode, out, n, path);

    cout << path.size() << endl;

    if (path.size() == m + 1) {
        // cout << "Path Found" << endl;
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }

    } else {
        cout << "No Path" << endl;
    }

    cout << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    HeirHolzer();

    return 0;
}