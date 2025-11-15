#include <bits/stdc++.h>
using namespace std;

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
// Function: kruskalMST
// ====================================
// Parameters:
//   n - number of vertices
//   edges - list of edges {u, v, weight}
// Returns:
//   Total weight of Minimum Spanning Tree (MST)
// ====================================
int kruskalMST(int n, vector<vector<int>>& edges) {
    vector<vector<int>> krk_edges;
    vector<pair<int,int>> st;
    DisjointSet dsu(n);
    int cost = 0;

    for(auto it : edges)
        krk_edges.push_back({it[2],it[0],it[1]});

    sort(krk_edges.begin(),krk_edges.end());

    for(auto it : krk_edges){
        int w = it[0], u =it[1], v = it[2];
        int u_par = dsu.findParent(u), v_par = dsu.findParent(v);
        if(u_par == v_par) continue;

        dsu.unionBySize(u,v);
        cost+=w;
        st.push_back({u,v}); 
    }

    cout<<"The Spanning Tree Edges are :"<<endl;
    for(auto it : st)
        cout<<it.first<<"->"<<it.second<<endl;
        
    return cost;
}

// ====================================
// Main Function with Multiple Test Cases
// ====================================
int main() {
    vector<pair<int, vector<vector<int>>>> testCases;

    // ---------- Test Case 1 ----------
    {
        int n = 4;
        vector<vector<int>> edges = {
            {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
        };
        testCases.push_back({n, edges});
    }

    // ---------- Test Case 2 ----------
    {
        int n = 5;
        vector<vector<int>> edges = {
            {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}
        };
        testCases.push_back({n, edges});
    }

    // ---------- Test Case 3 ----------
    {
        int n = 3;
        vector<vector<int>> edges = {
            {0, 1, 1}, {1, 2, 2}, {0, 2, 3}
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

        cout << "Number of vertices: " << n << "\n";
        cout << "Edges (u, v, weight):\n";
        for (auto &e : edges)
            cout << e[0] << " " << e[1] << " " << e[2] << "\n";

        int mstWeight = kruskalMST(n, edges);
        cout << "MST Total Weight: " << mstWeight << "\n\n";
    }

    return 0;
}
