#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<pair<int,int>>>& adj, vector<bool>& visited, stack<int>& st, int node) {
    visited[node] = true;
    for (auto &[v, w] : adj[node]) {
        if (!visited[v]) dfs(adj, visited, st, v);
    }
    st.push(node);
}

// Function to return shortest path from src in a DAG
vector<int> shortestPathDAG(int V, const vector<vector<pair<int,int>>>& adj, int src) {
    vector<bool> visited(V, false);
    stack<int> st;
    vector<int> dist(V, INT_MAX);

    // Step 1: Get topological order
    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(adj, visited, st, i);
    }

    // Step 2: Initialize source
    dist[src] = 0;

    // Step 3: Relax edges in topological order
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (dist[node] != INT_MAX) {
            for (auto &[v, w] : adj[node]) {
                if (dist[node] + w < dist[v]) {
                    dist[v] = dist[node] + w;
                }
            }
        }
    }

    // Step 4: Convert unreachable nodes to -1
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
        adj[2].push_back({3, 6});
        adj[4].push_back({2, 2});
        adj[4].push_back({5, 4});
        adj[5].push_back({3, 1});

        int src = 0;
        vector<int> dist = shortestPathDAG(V, adj, src);
        cout << "Shortest distances from node " << src << " (TC1): ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    }

    // ---------- Testcase 2 ----------
    {
        int V = 5;
        vector<vector<pair<int,int>>> adj(V);

        adj[0].push_back({1, 1});
        adj[0].push_back({2, 5});
        adj[1].push_back({2, 2});
        adj[1].push_back({3, 2});
        adj[2].push_back({3, 1});
        adj[3].push_back({4, 3});

        int src = 0;
        vector<int> dist = shortestPathDAG(V, adj, src);
        cout << "Shortest distances from node " << src << " (TC2): ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    }

    return 0;
}
