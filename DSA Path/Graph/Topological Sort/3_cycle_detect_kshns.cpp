#include <bits/stdc++.h>
using namespace std;

// Function to check if a directed graph contains a cycle using Kahn's Algorithm
bool hasCycle(int V, const vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);

    // Step 1: Compute indegree
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) indegree[v]++;
    }

    // Step 2: Push nodes with indegree 0 into queue
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    int count = 0; // track how many nodes are processed

    // Step 3: Process queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neigh : adj[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0) q.push(neigh);
        }
    }

    // Step 4: If not all nodes are processed => cycle exists
    return (count != V);
}

int main() {
    // ---------- Testcase 1 (No cycle) ----------
    {
        int V = 6;
        vector<vector<int>> adj(V);
        adj[5].push_back(0);
        adj[5].push_back(2);
        adj[4].push_back(0);
        adj[4].push_back(1);
        adj[2].push_back(3);
        adj[3].push_back(1);

        cout << "Has Cycle (TC1): " << hasCycle(V, adj) << endl; // Expected: 0
    }

    // ---------- Testcase 2 (No cycle) ----------
    {
        int V = 4;
        vector<vector<int>> adj(V);
        adj[0].push_back(1);
        adj[1].push_back(2);
        adj[2].push_back(3);

        cout << "Has Cycle (TC2): " << hasCycle(V, adj) << endl; // Expected: 0
    }

    // ---------- Testcase 3 (Cycle present) ----------
    {
        int V = 3;
        vector<vector<int>> adj(V);
        adj[0].push_back(1);
        adj[1].push_back(2);
        adj[2].push_back(0); // creates cycle

        cout << "Has Cycle (TC3): " << hasCycle(V, adj) << endl; // Expected: 1
    }

    return 0;
}
