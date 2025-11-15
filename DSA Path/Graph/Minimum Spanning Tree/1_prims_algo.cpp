#include <bits/stdc++.h>
using namespace std;

// ====================================
// Function: primsAlgorithm
// ====================================
// Parameters:
//   n - number of vertices
//   adj - adjacency list where adj[u] = {{v, weight}, ...}
// Returns:
//   Total weight of the Minimum Spanning Tree (MST)
// ====================================
int primsAlgorithm(int n, vector<vector<pair<int, int>>>& adj) {
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    vector<int> visited(n,0);
    vector<pair<int,int>> st;
    int cost = 0;
    pq.push({0,-1,0});
    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        int d = it[0], parent = it[1], node = it[2];
        visited[node] = 1;
        cost+=d;
        if(parent!=-1) st.push_back({parent,node});
        for(auto &[v,w] : adj[node]){
            if(!visited[v]) pq.push({w,node,v});
        }
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
    vector<pair<int, vector<vector<pair<int, int>>>>> testCases;

    // ---------- Test Case 1 ----------
    {
        int n = 5;
        vector<vector<pair<int, int>>> adj(n);
        adj[0].push_back({1, 2});
        adj[0].push_back({3, 6});
        adj[1].push_back({0, 2});
        adj[1].push_back({2, 3});
        adj[1].push_back({3, 8});
        adj[1].push_back({4, 5});
        adj[2].push_back({1, 3});
        adj[2].push_back({4, 7});
        adj[3].push_back({0, 6});
        adj[3].push_back({1, 8});
        adj[4].push_back({1, 5});
        adj[4].push_back({2, 7});
        testCases.push_back({n, adj});
    }

    // ---------- Test Case 2 ----------
    {
        int n = 4;
        vector<vector<pair<int, int>>> adj(n);
        adj[0].push_back({1, 10});
        adj[0].push_back({2, 6});
        adj[0].push_back({3, 5});
        adj[1].push_back({0, 10});
        adj[1].push_back({3, 15});
        adj[2].push_back({0, 6});
        adj[2].push_back({3, 4});
        adj[3].push_back({0, 5});
        adj[3].push_back({1, 15});
        adj[3].push_back({2, 4});
        testCases.push_back({n, adj});
    }

    // ---------- Test Case 3 ----------
    {
        int n = 3;
        vector<vector<pair<int, int>>> adj(n);
        adj[0].push_back({1, 1});
        adj[1].push_back({0, 1});
        adj[1].push_back({2, 2});
        adj[2].push_back({1, 2});
        testCases.push_back({n, adj});
    }

    // Run test cases
    for (int t = 0; t < testCases.size(); t++) {
        cout << "Test Case " << t + 1 << ":\n";
        int n = testCases[t].first;
        auto adj = testCases[t].second;
        cout << "Number of vertices: " << n << "\n";
        cout << "Edges:\n";
        for (int i = 0; i < n; i++) {
            for (auto &p : adj[i]) {
                if (i < p.first) // print once per undirected edge
                    cout << i << " -- " << p.first << " (" << p.second << ")\n";
            }
        }
        cout << "Output (MST Weight): " << primsAlgorithm(n, adj) << "\n\n";
    }

    return 0;
}
