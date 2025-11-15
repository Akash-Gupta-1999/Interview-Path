#include <bits/stdc++.h>
using namespace std;

// Function to return shortest path distances from source to all vertices
vector<int> shortestPath(int V, vector<vector<int>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front(); 
        q.pop();

        for (auto it : adj[node]) {
            if (dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    // Convert INT_MAX to -1 (for unreachable nodes)
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) dist[i] = -1;
    }
    return dist;
}

int main() {
    // ---------- Testcase 1 ----------
    {
        int V = 6;
        vector<vector<int>> adj(V);
        adj[0].push_back(1); adj[1].push_back(0);
        adj[0].push_back(2); adj[2].push_back(0);
        adj[1].push_back(3); adj[3].push_back(1);
        adj[2].push_back(4); adj[4].push_back(2);
        adj[3].push_back(5); adj[5].push_back(3);

        int src = 0;
        vector<int> dist = shortestPath(V, adj, src);
        cout << "Shortest distances from node " << src << " (TC1): ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    }

    // ---------- Testcase 2 ----------
    {
        int V = 4;
        vector<vector<int>> adj(V);
        adj[0].push_back(1); adj[1].push_back(0);
        adj[1].push_back(2); adj[2].push_back(1);
        adj[2].push_back(3); adj[3].push_back(2);

        int src = 0;
        vector<int> dist = shortestPath(V, adj, src);
        cout << "Shortest distances from node " << src << " (TC2): ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    }

    // ---------- Testcase 3 (Disconnected graph) ----------
    {
        int V = 5;
        vector<vector<int>> adj(V);
        adj[0].push_back(1); adj[1].push_back(0);
        adj[1].push_back(2); adj[2].push_back(1);

        // node 3 and 4 are disconnected
        int src = 0;
        vector<int> dist = shortestPath(V, adj, src);
        cout << "Shortest distances from node " << src << " (TC3): ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    }

    return 0;
}
