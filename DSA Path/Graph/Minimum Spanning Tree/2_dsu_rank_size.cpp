#include <bits/stdc++.h>
using namespace std;

// ====================================
// Class: DisjointSet
// ====================================
class DisjointSet {
public:
    vector<int> parent, rank, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);
        if (u_par == v_par) return;

        if (rank[u_par] > rank[v_par])
            parent[v_par] = u_par;
        else if (rank[u_par] < rank[v_par])
            parent[u_par] = v_par;
        else {
            parent[v_par] = u_par;
            rank[u_par]++;
        }
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
// Function: runDSUTest
// ====================================
void runDSUTest(int n, vector<pair<int, int>> unions, vector<pair<int, int>> queries) {
    cout << "Number of elements: " << n << "\n";

    // ---- Using Union by Rank ----
    {
        cout << "\nUsing Union by Rank:\n";
        DisjointSet ds(n);
        for (auto &p : unions) {
            ds.unionByRank(p.first, p.second);
        }

        for (auto &q : queries) {
            bool same = (ds.findParent(q.first) == ds.findParent(q.second));
            cout << "Are " << q.first << " and " << q.second
                 << " connected? " << (same ? "Yes" : "No") << "\n";
        }
    }

    // ---- Using Union by Size ----
    {
        cout << "\nUsing Union by Size:\n";
        DisjointSet ds(n);
        for (auto &p : unions) {
            ds.unionBySize(p.first, p.second);
        }

        for (auto &q : queries) {
            bool same = (ds.findParent(q.first) == ds.findParent(q.second));
            cout << "Are " << q.first << " and " << q.second
                 << " connected? " << (same ? "Yes" : "No") << "\n";
        }
    }

    cout << "----------------------------------------\n\n";
}

// ====================================
// Main Function with Multiple Test Cases
// ====================================
int main() {
    vector<pair<int, vector<pair<int, int>>>> unionTests = {
        {5, {{1, 2}, {2, 3}, {4, 5}}},
        {6, {{1, 2}, {2, 3}, {1, 4}, {5, 6}}},
        {7, {{1, 2}, {2, 3}, {4, 5}, {6, 7}}}
    };

    vector<vector<pair<int, int>>> queryTests = {
        {{1, 3}, {1, 4}, {4, 5}},
        {{1, 6}, {3, 4}, {5, 6}},
        {{1, 5}, {2, 3}, {6, 7}}
    };

    for (int i = 0; i < unionTests.size(); i++) {
        cout << "==============================\n";
        cout << "Test Case " << i + 1 << "\n";
        cout << "==============================\n";
        runDSUTest(unionTests[i].first, unionTests[i].second, queryTests[i]);
    }

    return 0;
}
