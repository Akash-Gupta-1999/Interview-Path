#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
}

int main() {
    int n = 7; // number of nodes
    vector<vector<int>> adj(n);

    // Component 1
    adj[0] = {1};
    adj[1] = {0, 2};
    adj[2] = {1};

    // Component 2
    adj[3] = {4};
    adj[4] = {3};

    // Component 3
    adj[5] = {6};
    adj[6] = {5};

    vector<bool> visited(n, false);

    cout << "BFS Traversal of all components:\n";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "Component starting at " << i << ": ";
            bfs(i, adj, visited);
            cout << endl;
        }
    }

    return 0;
}
