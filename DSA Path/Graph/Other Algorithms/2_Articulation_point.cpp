#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, int& timer, vector<bool>& isAP) {
    tin[node] = low[node] = timer++;
    int children = 0;

    for (int v : adj[node]) {
        if (v == parent) continue; // skip the edge to parent
        if (tin[v] == -1) {
            dfs(v, node, adj, tin, low, timer, isAP);
            low[node] = min(low[node], low[v]);
            if (low[v] >= tin[node] && parent != -1) // articulation point condition
                isAP[node] = true;
            children++;
        } else {
            low[node] = min(low[node], tin[v]); // back edge
        }
    }

    if (parent == -1 && children > 1) // root with multiple children
        isAP[node] = true;
}

vector<int> findArticulationPoints(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> tin(n, -1), low(n);
    vector<bool> isAP(n, false);
    int timer = 0;

    for (int i = 0; i < n; i++) {
        if (tin[i] == -1)
            dfs(i, -1, adj, tin, low, timer, isAP);
    }

    vector<int> articulationPoints;
    for (int i = 0; i < n; i++)
        if (isAP[i]) articulationPoints.push_back(i);

    return articulationPoints;
}

int main() {
    vector<pair<int, vector<vector<int>>>> testCases = {
        {5, {{0,1},{0,2},{2,1},{0,3},{3,4}}},
        {4, {{0,1},{1,2},{2,3}}},
        {7, {{0,1},{1,2},{2,0},{1,3},{1,4},{1,6},{3,5},{4,5}}}
    };

    for (int t = 0; t < testCases.size(); t++) {
        int n = testCases[t].first;
        auto edges = testCases[t].second;
        cout << "Test Case " << t+1 << ":\n";
        cout << "Number of vertices: " << n << "\nEdges:\n";
        for (auto &e : edges) cout << e[0] << " " << e[1] << "\n";

        auto ap = findArticulationPoints(n, edges);
        cout << "Articulation Points: ";
        for (int v : ap) cout << v << " ";
        cout << "\n\n";
    }

    return 0;
}
