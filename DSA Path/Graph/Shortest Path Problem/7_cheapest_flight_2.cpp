#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for (auto &f : flights)
        adj[f[0]].push_back({f[1], f[2]});

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // queue: {node, cost, stops}
    queue<tuple<int,int,int>> q;
    q.push({src, 0, 0});

    while (!q.empty()) {
        auto [node, cost, stops] = q.front();
        q.pop();
        if (stops > k) continue; // too many stops

        for (auto &[v, w] : adj[node]) {
            if (cost + w < dist[v]) {
                dist[v] = cost + w;
                q.push({v, cost + w, stops + 1});
            }
        }
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    // ---------- Testcase 1 ----------
    {
        int n = 4;
        vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,3,100},{0,3,500}};
        int src = 0, dst = 3, k = 1;
        cout << "TC1: " << findCheapestPrice(n, flights, src, dst, k) << endl;
        // Expected: 500 (since with at most 1 stop, cheapest is 0->3 direct)
    }

    // ---------- Testcase 2 ----------
    {
        int n = 4;
        vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,3,100},{0,3,500}};
        int src = 0, dst = 3, k = 2;
        cout << "TC2: " << findCheapestPrice(n, flights, src, dst, k) << endl;
        // Expected: 300 (0->1->2->3 is allowed within 2 stops)
    }

    // ---------- Testcase 3 (Disconnected) ----------
    {
        int n = 3;
        vector<vector<int>> flights = {{0,1,200}};
        int src = 0, dst = 2, k = 1;
        cout << "TC3: " << findCheapestPrice(n, flights, src, dst, k) << endl;
        // Expected: -1 (no path exists)
    }

    // ---------- Testcase 4 (Your tricky case) ----------
    {
        int n = 6;
        vector<vector<int>> flights = {
            {0,1,10},{1,4,10},{0,2,1},{2,3,1},{3,4,1},{4,5,1}
        };
        int src = 0, dst = 5, k = 2;
        cout << "TC4: " << findCheapestPrice(n, flights, src, dst, k) << endl;
        // Expected: 21 (0->1->4->5). 
        // Path 0->2->3->4->5 = cost 4 but requires 3 stops ❌ (not allowed)
    }

    return 0;
}
