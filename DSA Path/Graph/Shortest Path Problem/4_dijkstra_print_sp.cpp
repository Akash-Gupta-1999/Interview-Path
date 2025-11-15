#include <bits/stdc++.h>
using namespace std;

// Function to find shortest path from src to dest
vector<int> shortestPath(int V, vector<vector<pair<int,int>>>& adj, int src, int dest) {
    vector<int> path;
    vector<int> parent(V),dist(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<V;i++) parent[i] = i;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,node] = pq.top(); pq.pop();
        for(auto &[v,w] : adj[node]){
            if(dist[node] + w < dist[v]){
                dist[v] = dist[node] + w;
                parent[v] = node;
                pq.push({dist[v],v});
            }
        }
    }
    if(dist[dest] == INT_MAX) return {-1};
    int node = dest;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    reverse(path.begin(),path.end());
    return path;
}

int main() {
    // ---------- Testcase 1 ----------
    {
        int V = 6;
        vector<vector<pair<int,int>>> adj(V);

        // Graph edges: u -> v with weight w
        adj[0].push_back({1, 2});
        adj[0].push_back({4, 1});
        adj[1].push_back({2, 3});
        adj[4].push_back({2, 2});
        adj[4].push_back({5, 4});
        adj[5].push_back({3, 1});

        int src = 0, dest = 3;
        vector<int> path = shortestPath(V, adj, src, dest);
        cout << "Shortest path from " << src << " to " << dest << " (TC1): ";
        for (int node : path) cout << node << " ";
        cout << endl;
    }

    // ---------- Testcase 2 ----------
    {
        int V = 7;
        vector<vector<pair<int,int>>> adj(V);

        adj[0].push_back({1, 4});
        adj[0].push_back({2, 2});
        adj[1].push_back({2, 5});
        adj[1].push_back({3, 10});
        adj[2].push_back({4, 3});
        adj[4].push_back({3, 4});
        adj[3].push_back({5, 11});
        adj[5].push_back({6, 1});

        int src = 0, dest = 6;
        vector<int> path = shortestPath(V, adj, src, dest);
        cout << "Shortest path from " << src << " to " << dest << " (TC2): ";
        for (int node : path) cout << node << " ";
        cout << endl;
    }

    // ---------- Testcase 3 (Disconnected Graph) ----------
    {
        int V = 5;
        vector<vector<pair<int,int>>> adj(V);

        adj[0].push_back({1, 2});
        adj[1].push_back({2, 2});
        // Nodes 3 and 4 are disconnected

        int src = 0, dest = 4;
        vector<int> path = shortestPath(V, adj, src, dest);
        cout << "Shortest path from " << src << " to " << dest << " (TC3): ";
        for (int node : path) cout << node << " ";
        cout << endl;
    }

    return 0;
}
