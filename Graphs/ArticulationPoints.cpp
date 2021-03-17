#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void ArticulationPoints(
    vector<int> graph[],
    int currentVertex,
    bool isVisited[],
    int discoveryTime[],
    int parents[],
    int low[],
    bool articulationPoints[],
    int& time 
) {
    int children = 0;

    isVisited[currentVertex] = true;
    discoveryTime[currentVertex] = low[currentVertex] = ++time;

    for (int i = 0; i < graph[currentVertex].size(); i++) {
        int currentNeighbor = graph[currentVertex][i];
        if (!isVisited[currentNeighbor]) {
            children++;
            parents[currentVertex] = currentVertex;

            ArticulationPoints(graph, currentNeighbor, isVisited, discoveryTime, parents, low, articulationPoints, time);

            low[currentVertex] = min(low[currentVertex], low[currentNeighbor]);

            // If currentVertex is Root
            if (parents[currentVertex] == -1 && children > 1) {
                articulationPoints[currentVertex] = true;
            }

            // If currentVertex is Not Root;
            if (parents[currentVertex] != -1 && low[currentNeighbor] >= discoveryTime[currentVertex]) {
                articulationPoints[currentVertex] = true;
            }
        } else if (currentNeighbor != parents[currentVertex]) {
            low[currentVertex] = min(low[currentVertex], discoveryTime[currentNeighbor]);
        }
    }
}

// Find Artichulation Points in Undirected Graph
void ArticulationPoints()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool    isVisited[n + 1];
    int     discoveryTime[n + 1];
    int     parents[n + 1];
    int     low[n + 1];
    bool    articulationPoints[n + 1];

    for (int i = 1; i <= n; i++) {
        isVisited[i] = false;
        parents[i] = -1;
        articulationPoints[i] = false;
    }

    int time = 0;

    for (int i = 1; i <= n; i++) {
        if (!isVisited[i]) {
            ArticulationPoints(graph, i, isVisited, discoveryTime, parents, low, articulationPoints, time);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (articulationPoints[i]) {
            cout << i << " ";
        }
    }

    cout << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ArticulationPoints();

    return 0;
}