#include <bits/stdc++.h>
using namespace std;

// ====================================
// Class: DisjointSet
// ====================================
class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {
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

// ====================================
// Function: numberOfProvinces
// ====================================
// Parameters:
//   n - number of cities
//   edges - list of connections between cities
// Returns:
//   Number of provinces (connected components)
// ====================================
int numberOfProvinces(int n, vector<pair<int, int>>& edges) {
    int provinces = 0;
    DisjointSet dsu(n);

    // perform unions
    for (auto it : edges)
        dsu.unionBySize(it.first, it.second);

    // count unique parents (roots)
    for (int i = 0; i < n; i++) {
        if (dsu.findParent(i) == i)
            provinces++;
    }

    return provinces;
}

// ====================================
// Main Function with Multiple Test Cases
// ====================================
int main() {
    vector<pair<int, vector<pair<int, int>>>> testCases;

    // ---------- Test Case 1 ----------
    {
        int n = 3;
        vector<pair<int, int>> edges = {
            {0, 1},
            {1, 2}
        };
        testCases.push_back({n, edges});
    }

    // ---------- Test Case 2 ----------
    {
        int n = 4;
        vector<pair<int, int>> edges = {
            {0, 1},
            {2, 3}
        };
        testCases.push_back({n, edges});
    }

    // ---------- Test Case 3 ----------
    {
        int n = 5;
        vector<pair<int, int>> edges = {
            {0, 1},
            {1, 2},
            {3, 4}
        };
        testCases.push_back({n, edges});
    }

    // ---------- Test Case 4 ----------
    {
        int n = 4;
        vector<pair<int, int>> edges = {
            {0, 1},
            {1, 2},
            {2, 3},
            {3, 0}
        };
        testCases.push_back({n, edges});
    }

    // ---------- Run All Test Cases ----------
    for (int t = 0; t < testCases.size(); t++) {
        cout << "==============================\n";
        cout << "Test Case " << t + 1 << "\n";
        cout << "==============================\n";
        int n = testCases[t].first;
        auto edges = testCases[t].second;

        cout << "Number of cities: " << n << "\n";
        cout << "Edges:\n";
        for (auto &e : edges)
            cout << e.first << " " << e.second << "\n";

        int provinces = numberOfProvinces(n, edges);
        cout << "Number of Provinces: " << provinces << "\n\n";
    }

    return 0;
}
