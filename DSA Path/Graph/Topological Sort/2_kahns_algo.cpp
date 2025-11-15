#include <bits/stdc++.h>
using namespace std;

// Function to return list containing vertices in Topological order (Kahn's Algorithm)
vector<int> topoSort(int V, const vector<vector<int>>& adj) {
    vector<int> topoOrder;
    vector<int> indegree(V,0);
    queue<int> q;
    for(int i=0;i<V;i++){
        for(auto it : adj[i]) 
            indegree[it]++;
    }
    for(int i=0;i<V;i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
        topoOrder.push_back(node);
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
        cout << "Topological Sort (Kahn, TC1): ";
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
        cout << "Topological Sort (Kahn, TC2): ";
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
        cout << "Topological Sort (Kahn, TC3): ";
        for (int node : result) cout << node << " ";
        cout << endl;
    }

    return 0;
}
