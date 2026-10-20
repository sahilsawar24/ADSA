
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // Undirected graph
    }

    int src;
    cin >> src;

    vector<int> dist = dijkstra(V, adj, src);

    for (int i = 0; i < V; i++) {
        cout << "Distance from " << src << " to " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << '\n';
    }

    return 0;
}
