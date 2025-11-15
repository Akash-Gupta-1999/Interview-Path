#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,long long>>> adj(n);
    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    int MOD = 1e9+7;

    for(auto &it : roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();
        if(d > dist[node]) continue; // Skip outdated entries or if u don't need this step then use d instead of dist[node] in below steps so it won't pass in if condition

        for(auto &[v,w] : adj[node]){
            if(dist[node] + w < dist[v]){
                dist[v] = dist[node] + w;
                ways[v] = ways[node];
                pq.push({dist[v], v});
            } else if(dist[node] + w == dist[v]){
                ways[v] = (ways[v] + ways[node]) % MOD;
            }
        }
    }
    return ways[n-1];
}

int main() {
    // ---------- Testcase 1 ----------
    {
        int n = 6;
        vector<vector<int>> roads = {
            {0,1,5},{0,2,1},{1,3,1},{1,5,1},{2,3,2},{2,4,1},{3,4,1}
        };
        cout << "TC1: " << countPaths(n, roads) << " (Expected: 2)" << endl;
    }

    // ---------- Testcase 2 ----------
    {
        int n = 4;
        vector<vector<int>> roads = {
            {0,1,1},{0,2,2},{1,3,1},{2,3,1}
        };
        cout << "TC2: " << countPaths(n, roads) << " (Expected: 2)" << endl;
    }

    // ---------- Testcase 3 ----------
    {
        int n = 3;
        vector<vector<int>> roads = {
            {0,1,3},{1,2,4},{0,2,7}
        };
        cout << "TC3: " << countPaths(n, roads) << " (Expected: 1)" << endl;
    }

    return 0;
}
