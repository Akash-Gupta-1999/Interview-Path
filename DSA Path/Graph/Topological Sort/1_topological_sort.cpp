#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& visited,stack<int>& st,int node){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(!visited[it]) dfs(adj,visited,st,it);
    }
    st.push(node);
}

// Function to return list containing vertices in Topological order
vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<int> topoOrder;
    stack<int> st;
    vector<int> visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]) dfs(adj,visited,st,i);
    }
    while(!st.empty()){
        topoOrder.push_back(st.top());
        st.pop();
    }
    return topoOrder;
}

int main() {
    // ---------- Testcase 1 ----------
    {
        int V = 6;
        vector<vector<int>> adj(V);
        adj[5].push_back(0);
        adj[5].push_back(2);
        adj[4].push_back(0);
        adj[4].push_back(1);
        adj[2].push_back(3);
        adj[3].push_back(1);

        vector<int> result = topoSort(V, adj);
        cout << "Topological Sort (TC1): ";
        for (int node : result) cout << node << " ";
        cout << endl;
    }

    // ---------- Testcase 2 ----------
    {
        int V = 4;
        vector<vector<int>> adj(V);
        adj[0].push_back(1);
        adj[1].push_back(2);
        adj[2].push_back(3);

        vector<int> result = topoSort(V, adj);
        cout << "Topological Sort (TC2): ";
        for (int node : result) cout << node << " ";
        cout << endl;
    }

    // ---------- Testcase 3 ----------
    {
        int V = 5;
        vector<vector<int>> adj(V);
        adj[0].push_back(2);
        adj[0].push_back(3);
        adj[1].push_back(3);
        adj[1].push_back(4);

        vector<int> result = topoSort(V, adj);
        cout << "Topological Sort (TC3): ";
        for (int node : result) cout << node << " ";
        cout << endl;
    }

    return 0;
}
