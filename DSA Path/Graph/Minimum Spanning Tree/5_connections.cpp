#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    void Unionbysize(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);
        if (u_par == v_par) return;

        if (size[u_par] > size[v_par]) {
            parent[v_par] = u_par;
            size[u_par] += size[v_par];
        } else {
            parent[u_par] = v_par;
            size[v_par] += size[u_par];
        }
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;

    DisjointSet dsu(n);
    for (auto &it : connections)
        dsu.Unionbysize(it[0], it[1]);

    int components = 0;
    for (int i = 0; i < n; i++) {
        if (dsu.findParent(i) == i)
            components++;
    }

    return components - 1;
}

int main() {
    vector<vector<vector<int>>> testCases = {
        {{0, 1}, {0, 2}, {1, 2}},              // Already mostly connected
        {{0, 1}, {0, 2}, {3, 4}, {2, 3}},      // Needs 0 operations
        {{0, 1}, {2, 3}, {1, 2}},              // Fully connected
        {{0, 1}, {2, 3}},                      // 1 operation needed
        {{0, 1}}                               // Not enough edges
    };

    for (int t = 0; t < testCases.size(); t++) {
        cout << "Test Case " << t + 1 << ":\n";
        int n = 5;
        auto connections = testCases[t];
        int result = makeConnected(n, connections);
        cout << "Minimum operations to connect all computers: " << result << "\n\n";
    }
}
