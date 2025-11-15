#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, int src, vector<vector<int>>& edges) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0; // ✅ Initialize source

    // Relax all edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto &it : edges) {
            int u = it[0], v = it[1], w = it[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Check for negative weight cycle
    for (auto &it : edges) {
        int u = it[0], v = it[1], w = it[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "⚠️ Negative weight cycle detected!\n";
            return {-1};
        }
    }

    return dist;
}

int main() {
    vector<vector<vector<int>>> testCases = {
        // ✅ TC1: Simple graph (no negative cycle)
        {{0, 1, 5}, {1, 2, -2}, {1, 5, -3}, {2, 4, 3}, {3, 2, 6}, {5, 3, 1}},

        // ✅ TC2: Larger graph
        {{0, 1, 6}, {0, 2, 7}, {1, 2, 8}, {1, 3, 5}, {1, 4, -4}, 
         {2, 3, -3}, {2, 4, 9}, {3, 1, -2}, {4, 3, 7}},

        // ✅ TC3: Small positive-weight graph
        {{0, 1, 4}, {0, 2, 5}, {1, 2, -3}, {2, 3, 4}},

        // ⚠️ TC4: Graph with a negative weight cycle
        {{0, 1, 1}, {1, 2, -1}, {2, 3, -1}, {3, 1, -1}}
    };

    vector<int> nValues = {6, 5, 4, 4};
    vector<int> sources = {0, 0, 0, 0};

    for (int t = 0; t < testCases.size(); t++) {
        cout << "==============================\n";
        cout << "Test Case " << t + 1 << ":\n";
        cout << "Number of vertices: " << nValues[t] << "\n";
        cout << "Source vertex: " << sources[t] << "\n";
        cout << "Edges: [ ";
        for (auto &e : testCases[t])
            cout << "{" << e[0] << "," << e[1] << "," << e[2] << "} ";
        cout << "]\n";

        vector<int> result = bellmanFord(nValues[t], sources[t], testCases[t]);
        if (result.empty() || result[0] == -1)
            cout << "Output: ❌ Negative cycle detected or no valid result\n\n";
        else {
            cout << "Shortest distances from source: ";
            for (int d : result)
                cout << (d == INT_MAX ? "INF " : to_string(d) + " ");
            cout << "\n\n";
        }
    }

    return 0;
}
