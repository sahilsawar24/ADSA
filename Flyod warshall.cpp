
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {

                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }

            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], w);
    }

    floydWarshall(dist, V);

    cout << "Shortest Distance Matrix:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
