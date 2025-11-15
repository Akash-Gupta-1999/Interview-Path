#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c) {
    color[node] = c;
    for (int nei : graph[node]) {
        if (color[nei] == 0) {
            // assign opposite color using 3 - c (1 -> 2, 2 -> 1)
            if (!dfs(graph, color, nei, 3 - c)) return false;
        } 
        else if (color[nei] == c) {
            return false; // conflict (same color adjacent)
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, 0); // 0 = unvisited, 1/2 = colors
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && !dfs(graph, color, i, 1)) {
            return false;
        }
    }
    return true;
}

int main() {
    // ✅ Test Case 1: Bipartite (square)
    vector<vector<int>> graph1 = {
        {1, 3}, {0, 2}, {1, 3}, {0, 2}
    };
    cout << "Graph 1 (Expected: 1): " << isBipartite(graph1) << endl;

    // ❌ Test Case 2: Not bipartite (triangle, odd cycle)
    vector<vector<int>> graph2 = {
        {1, 2}, {0, 2}, {0, 1}
    };
    cout << "Graph 2 (Expected: 0): " << isBipartite(graph2) << endl;

    // ✅ Test Case 3: Disconnected but bipartite
    vector<vector<int>> graph3 = {
        {1}, {0}, {3}, {2}
    };
    cout << "Graph 3 (Expected: 1): " << isBipartite(graph3) << endl;

    // ❌ Test Case 4: Odd cycle of length 5
    vector<vector<int>> graph4 = {
        {1, 4}, {0, 2}, {1, 3}, {2, 4}, {0, 3}
    };
    cout << "Graph 4 (Expected: 0): " << isBipartite(graph4) << endl;

    return 0;
}
