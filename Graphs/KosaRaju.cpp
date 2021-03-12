#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// DFS 1 - To Fill Traveresed Vertices
void FillStack(vector<int> graph[], int n, int currentVertex, bool isVisited[], stack<int>& finishedTraversing)
{
    isVisited[currentVertex] = true;

    for (int i = 0; i < graph[currentVertex].size(); i++) {
        int currentNeibor = graph[currentVertex][i];

        if (!isVisited[currentNeibor]) {
            FillStack(graph, n, currentNeibor, isVisited, finishedTraversing);
        }
    }

    finishedTraversing.push(currentVertex);
}

void DFSonReverseGraph(
    vector<int> graph[], 
    int n, 
    int currentVertex,
    bool isVisited[], 
    vector<vector<int>>& connectedComponents,
    int& currentConnectedComponentIndex
) {
    isVisited[currentVertex] = true;

    for (int i = 0; i < graph[currentVertex].size(); i++) {
        int currentNeibor = graph[currentVertex][i];

        if (!isVisited[currentNeibor]) {
            DFSonReverseGraph(graph, n, currentNeibor, isVisited, connectedComponents, currentConnectedComponentIndex);
        }
    }

    connectedComponents[currentConnectedComponentIndex].push_back(currentVertex);
}

void KosaRaju()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n + 1];
    vector<int> reverseGraph[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
    }

    bool isVisited[n + 1];
    for (int i = 1; i <= n; i++) {
        isVisited[i] = false;
    }

    stack<int> finishedTraversing;
    
    for (int i = 1; i <= n; i++) {
        if (!isVisited[i]) {
            FillStack(graph, n, i, isVisited, finishedTraversing);
        }
    }

    for (int i = 1; i <= n; i++) {
        isVisited[i] = false;
    }

    vector<vector<int>> connectedComponents;
    int currentConnectedComponentIndex = -1;

    while (!finishedTraversing.empty()) {
        int currentVertex = finishedTraversing.top();

        if (!isVisited[currentVertex]) {
            connectedComponents.push_back(vector<int>());
            currentConnectedComponentIndex++;
            DFSonReverseGraph(reverseGraph, n, currentVertex, isVisited, connectedComponents, currentConnectedComponentIndex);
        }

        finishedTraversing.pop();
    }

    cout << endl;
    for (int i = 0; i <= currentConnectedComponentIndex; i++) {
        for (int j = 0; j < connectedComponents[i].size(); j++) {
            cout << connectedComponents[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    KosaRaju();

    return 0;
}