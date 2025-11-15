#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    // undirected edges
    adj[0] = {1, 3};
    adj[1] = {0, 2, 4};
    adj[2] = {1};
    adj[3] = {0, 4};
    adj[4] = {1, 3};

    vector<bool> visited(n, false);

    cout << "DFS Traversal starting from 0: ";
    dfs(0, adj, visited);

    return 0;
}
