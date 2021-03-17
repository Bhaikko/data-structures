#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool IsSafe(int currentVertex, set<int> graph[], int n, int path[], int pos)
{
    // Check if current Vertex has Edge from Last vertex in Path
    if (graph[path[pos - 1]].find(currentVertex) == graph[path[pos - 1]].end()) {
        return false;
    }

    // CHeck if current Vertex has not been already added
    for (int i = 1; i < pos; i++) {
        if (path[i] == currentVertex) {
            return false;
        }
    }

    return true;
}

bool HamiltonianPath(set<int> graph[], int n, int path[], int pos, bool& isCycle)
{
    if (pos == n) {
        // Hamiltonian Path Found

        // Check for Hamiltonian Cycle
        // True - Hamiltonian Cycle
        // False - Hamiltonian Path
        isCycle = graph[path[pos - 1]].find(1) != graph[path[pos - 1]].end();
        return true;
    }

    for (int v = 2; v <= n; v++) {
        if (IsSafe(v, graph, n, path, pos)) {
            path[pos] = v;

            if (HamiltonianPath(graph, n, path, pos + 1, isCycle)) {
                return true;
            }

            path[pos] = -1;
        }
    }

    return false;


}

void HamiltonianPath(set<int> graph[], int n)
{
    int path[n + 1];
    for (int i = 1; i <= n; i++) {
        path[i] = -1;
    }

    path[0] = 1;

    bool isCycle = false;

    if (!HamiltonianPath(graph, n, path, 1, isCycle)) {
        cout << "No Path or Cycle Exist" << endl;
    } else {
        // Printing Solution
        for (int i = 0; i < n; i++) {
            cout << path[i] << " ";
        } 

        if (isCycle) {
            cout << path[0] << " "; 
        }

        cout << endl;
    }

}

// To Find Hamiltonian Path or Cycle in an Undirected Graph
void HamiltonianPath()
{
    int n, m;
    cin >> n >> m;

    set<int> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        // graph[a].push_back(b);
        // graph[b].push_back(a);

        graph[a].insert(b);
        graph[b].insert(a);
    }

    HamiltonianPath(graph, n);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    HamiltonianPath();

    return 0;
}