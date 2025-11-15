#include <bits/stdc++.h>
using namespace std;

// ====================================
// DFS for original graph to fill stack
// ====================================
void dfs(vector<vector<int>>& adj, stack<int>& order, vector<int>& visited, int node) {
    visited[node] = 1;
    for (int it : adj[node]) {
        if (!visited[it])
            dfs(adj, order, visited, it);
    }
    order.push(node);
}

// ====================================
// DFS for reversed graph to collect SCC
// ====================================
void dfs2(vector<vector<int>>& adj, vector<int>& component, vector<int>& visited, int node) {
    visited[node] = 1;
    component.push_back(node);
    for (int it : adj[node]) {
        if (!visited[it])
            dfs2(adj, component, visited, it);
    }
}

// ====================================
// Kosaraju's Algorithm
// ====================================
vector<vector<int>> kosarajuSCC(int n, vector<vector<int>>& adj) {
    vector<vector<int>> rev_adj(n);
    stack<int> order;
    vector<int> visited(n, 0);
    vector<vector<int>> scc; 

    // Step 1: DFS on original graph to fill order stack
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(adj, order, visited, i);
    }

    // Step 2: Create reversed graph
    for (int i = 0; i < n; i++) {
        for (int j : adj[i])
            rev_adj[j].push_back(i);
    }

    // Step 3: DFS on reversed graph in order of finishing times
    fill(visited.begin(), visited.end(), 0);
    while (!order.empty()) {
        int node = order.top(); order.pop();
        if (visited[node]) continue;

        vector<int> component;
        dfs2(rev_adj, component, visited, node);
        scc.push_back(component);
    }

    return scc;
}

// ====================================
// Main Function with Multiple Test Cases
// ====================================
int main() {
    vector<pair<int, vector<vector<int>>>> testCases;

    // ---------- Test Case 1 ----------
    {
        int n = 5;
        vector<vector<int>> adj = {
            {2, 3},    // neighbors of 0
            {0},       // neighbors of 1
            {1},       // neighbors of 2
            {4},       // neighbors of 3
            {}         // neighbors of 4
        };
        testCases.push_back({n, adj});
    }

    // ---------- Test Case 2 ----------
    {
        int n = 4;
        vector<vector<int>> adj = {
            {1},       // neighbors of 0
            {2},       // neighbors of 1
            {3},       // neighbors of 2
            {1}        // neighbors of 3
        };
        testCases.push_back({n, adj});
    }

    // ---------- Test Case 3 ----------
    {
        int n = 6;
        vector<vector<int>> adj = {
            {1},       // neighbors of 0
            {2},       // neighbors of 1
            {0, 3},    // neighbors of 2
            {4},       // neighbors of 3
            {5},       // neighbors of 4
            {3}        // neighbors of 5
        };
        testCases.push_back({n, adj});
    }

    // Run all test cases
    for (int t = 0; t < testCases.size(); t++) {
        cout << "==============================\n";
        cout << "Test Case " << t + 1 << "\n";
        cout << "==============================\n";

        int n = testCases[t].first;
        auto adj = testCases[t].second;

        cout << "Graph adjacency list:\n";
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            for (auto &v : adj[i])
                cout << v << " ";
            cout << "\n";
        }

        auto scc = kosarajuSCC(n, adj);

        cout << "Strongly Connected Components:\n";
        for (auto &comp : scc) {
            cout << "{ ";
            for (auto &v : comp)
                cout << v << " ";
            cout << "}\n";
        }
        cout << "\n";
    }

    return 0;
}
