#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> safeNode, indegree(n, 0);
    vector<vector<int>> adj(n);
    queue<int> q;

    // Step 1: Reverse the graph
    for (int i = 0; i < n; i++) {
        for (int it : graph[i])
            adj[it].push_back(i);
    }

    // Step 2: Compute indegree in reversed graph
    for (int i = 0; i < n; i++) {
        for (int it : adj[i])
            indegree[it]++;
    }

    // Step 3: Push terminal nodes (indegree 0) into queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    // Step 4: Process nodes
    while (!q.empty()) {
        int node = q.front(); q.pop();
        safeNode.push_back(node);

        for (int it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    sort(safeNode.begin(), safeNode.end());
    return safeNode;
}

int main() {
    // ---------- Testcase 1 ----------
    {
        vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
        vector<int> result = eventualSafeNodes(graph);
        cout << "Safe Nodes (TC1): ";
        for (int x : result) cout << x << " ";
        cout << endl;
        // Expected: 2 4 5 6
    }

    // ---------- Testcase 2 ----------
    {
        vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
        vector<int> result = eventualSafeNodes(graph);
        cout << "Safe Nodes (TC2): ";
        for (int x : result) cout << x << " ";
        cout << endl;
        // Expected: 4
    }

    // ---------- Testcase 3 ----------
    {
        vector<vector<int>> graph = {{},{0,2,3,4},{3},{4},{}};
        vector<int> result = eventualSafeNodes(graph);
        cout << "Safe Nodes (TC3): ";
        for (int x : result) cout << x << " ";
        cout << endl;
        // Expected: 0 1 2 3 4
    }

    // ---------- Testcase 4 ----------
    {
        vector<vector<int>> graph = {{1},{2},{3},{4},{}};
        vector<int> result = eventualSafeNodes(graph);
        cout << "Safe Nodes (TC4): ";
        for (int x : result) cout << x << " ";
        cout << endl;
        // Expected: 0 1 2 3 4
    }

    return 0;
}
