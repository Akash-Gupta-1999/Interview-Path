#include <bits/stdc++.h>
using namespace std;

// ==============================
// Tarjan's Algorithm for Bridges
// ==============================
void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, int& timer, vector<vector<int>>& bridges) {
    tin[node] = low[node] = timer++;
    for (int it : adj[node]) {
        if (tin[it] == -1) {
            dfs(it, node, adj, tin, low, timer, bridges);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node])
                bridges.push_back({node, it});
        } else if (it != parent) {
            low[node] = min(low[node], tin[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);
    vector<vector<int>> bridges;
    vector<int> tin(n, -1), low(n);
    int timer = 0;

    for (auto it : connections) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    for (int i = 0; i < n; i++) {
        if (tin[i] == -1)
            dfs(i, -1, adj, tin, low, timer, bridges);
    }

    return bridges;
}

// ==============================
// Main Function with Multiple Test Cases
// ==============================
int main() {
    vector<pair<int, vector<vector<int>>>> testCases = {
        {4, {{0,1},{1,2},{2,0},{1,3}}},
        {5, {{0,1},{1,2},{2,0},{1,3},{3,4}}},
        {6, {{0,1},{1,2},{2,3},{3,4},{4,5},{5,0},{2,5}}}
    };

    for (int t = 0; t < testCases.size(); t++) {
        cout << "==============================\n";
        cout << "Test Case " << t + 1 << "\n";
        cout << "==============================\n";

        int n = testCases[t].first;
        auto edges = testCases[t].second;

        cout << "Number of nodes: " << n << "\n";
        cout << "Connections:\n";
        for (auto &e : edges)
            cout << e[0] << " - " << e[1] << "\n";

        auto bridges = criticalConnections(n, edges);
        cout << "Critical Connections (Bridges):\n";
        for (auto &b : bridges)
            cout << b[0] << " - " << b[1] << "\n";
        cout << "\n";
    }

    return 0;
}
