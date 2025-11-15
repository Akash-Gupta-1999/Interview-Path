#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> dist(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto it : times)
        adj[it[0]].push_back({it[1],it[2]});
    dist[k] = 0;
    pq.push({0,k});
    while(!pq.empty()){
        auto [d,node] = pq.top(); pq.pop();
        for(auto &[v,w] : adj[node]){
            if(dist[node] + w < dist[v]){
                dist[v] = dist[node] + w;
                pq.push({dist[v],v});
            }
        }
    }
    int ans = *max_element(dist.begin()+1, dist.end());
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    // ---------- Testcase 1 ----------
    {
        int n = 4, k = 2;
        vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
        cout << "TC1: " << networkDelayTime(times,n,k) << endl; // Expected: 2
    }

    // ---------- Testcase 2 ----------
    {
        int n = 3, k = 1;
        vector<vector<int>> times = {{1,2,1},{2,3,2},{1,3,4}};
        cout << "TC2: " << networkDelayTime(times,n,k) << endl; // Expected: 3
    }

    // ---------- Testcase 3 ----------
    {
        int n = 3, k = 1;
        vector<vector<int>> times = {{1,2,1}};
        cout << "TC3: " << networkDelayTime(times,n,k) << endl; // Expected: -1 (node 3 unreachable)
    }

    // ---------- Testcase 4 ----------
    {
        int n = 5, k = 1;
        vector<vector<int>> times = {{1,2,2},{1,3,5},{2,3,1},{3,4,2},{4,5,1}};
        cout << "TC4: " << networkDelayTime(times,n,k) << endl; // Expected: 6
    }

    return 0;
}
