#include <bits/stdc++.h>
using namespace std;

// DFS to detect cycle in directed graph
bool dfsDirected(vector<vector<int>>& adj, vector<int>& visited, vector<int>& path, int node) {
    visited[node] = 1;
    path[node] = 1;  // mark node in current DFS path

    for (int nei : adj[node]) {
        if (!visited[nei]) {
            if (dfsDirected(adj, visited, path, nei)) return true;
        } else if (path[nei]) {
            return true; // cycle detected
        }
    }

    path[node] = 0; // remove node from current DFS path
    return false;
}

// Function to check if graph contains a cycle (directed)
bool isCycleDirected(int V, vector<vector<int>>& adj) {
    vector<int> visited(V, 0);
    vector<int> path(V, 0); // keeps track of nodes in current DFS path

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsDirected(adj, visited, path, i)) return true;
        }
    }

    return false;
}

int main() {
    int numTests = 3; // number of test cases

    vector<pair<int, vector<vector<int>>>> testCases;

    // Test Case 1: Directed Acyclic Graph (DAG)
    testCases.push_back({
        4,
        {
            {1},    // 0 -> 1
            {2},    // 1 -> 2
            {3},    // 2 -> 3
            {}      // 3
        }
    });

    // Test Case 2: Directed graph with a cycle
    testCases.push_back({
        4,
        {
            {1},    // 0 -> 1
            {2},    // 1 -> 2
            {3},    // 2 -> 3
            {1}     // 3 -> 1 creates cycle 1->2->3->1
        }
    });

    // Test Case 3: Disconnected directed graph with a cycle
    testCases.push_back({
        5,
        {
            {1},    // 0 -> 1
            {},     // 1
            {3},    // 2 -> 3
            {4},    // 3 -> 4
            {2}     // 4 -> 2 creates cycle 2->3->4->2
        }
    });

    // Run all test cases
    for (int t = 0; t < numTests; t++) {
        int V = testCases[t].first;
        vector<vector<int>> adj = testCases[t].second;

        cout << "Test Case " << t + 1 << ": ";
        cout << (isCycleDirected(V, adj) ? "Contains Cycle" : "No Cycle") << endl;
    }

    return 0;
}
