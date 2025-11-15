#include <bits/stdc++.h>
using namespace std;

// Function to implement Dijkstra's Algorithm
vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top(); 
        pq.pop();

        for (auto &[v, w] : adj[node]) {
            if (dist[node] + w < dist[v]) {
                dist[v] = dist[node] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Replace INT_MAX with -1 for unreachable nodes
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) dist[i] = -1;
    }
    return dist;
}

int main() {
    // ---------- Testcase 1 ----------
    {
        int V = 6;
        vector<vector<pair<int,int>>> adj(V);

        adj[0].push_back({1, 2});
        adj[0].push_back({4, 1});
        adj[1].push_back({2, 3});
        adj[4].push_back({2, 2});
        adj[4].push_back({5, 4});
        adj[5].push_back({3, 1});

        int src = 0;
        vector<int> dist = dijkstra(V, adj, src);
        cout << "Dijkstra distances from " << src << " (TC1): ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    }

    // ---------- Testcase 2 ----------
    {
        int V = 6;
        vector<vector<pair<int,int>>> adj(V);

        adj[0].push_back({1, 4});
        adj[0].push_back({2, 2});
        adj[1].push_back({2, 5});
        adj[1].push_back({3, 10});
        adj[2].push_back({4, 3});
        adj[4].push_back({3, 4});
        adj[3].push_back({5, 11});

        int src = 0;
        vector<int> dist = dijkstra(V, adj, src);
        cout << "Dijkstra distances from " << src << " (TC2): ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    }

    // ---------- Testcase 3 ----------
    {
        int V = 4;
        vector<vector<pair<int,int>>> adj(V);

        adj[0].push_back({1, 1});
        adj[1].push_back({2, 1});
        adj[2].push_back({3, 1});

        int src = 0;
        vector<int> dist = dijkstra(V, adj, src);
        cout << "Dijkstra distances from " << src << " (TC3): ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    }

    // ---------- Testcase 4 ----------
    {
        int V = 7;
        vector<vector<pair<int,int>>> adj(V);

        adj[0].push_back({1, 2});
        adj[0].push_back({2, 4});
        adj[1].push_back({2, 1});
        adj[1].push_back({3, 7});
        adj[2].push_back({4, 3});
        adj[3].push_back({5, 1});
        adj[4].push_back({3, 2});
        adj[4].push_back({5, 5});
        adj[5].push_back({6, 7});

        int src = 0;
        vector<int> dist = dijkstra(V, adj, src);
        cout << "Dijkstra distances from " << src << " (TC4): ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    }

    // ---------- Testcase 5 (Disconnected Graph) ----------
    {
        int V = 5;
        vector<vector<pair<int,int>>> adj(V);

        adj[0].push_back({1, 2});
        adj[1].push_back({2, 2});
        // Node 3 and 4 are disconnected

        int src = 0;
        vector<int> dist = dijkstra(V, adj, src);
        cout << "Dijkstra distances from " << src << " (TC5): ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    }

    return 0;
}
