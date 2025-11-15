#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    // Build adjacency list
    vector<vector<pair<int,int>>> adj(n);
    for (auto &f : flights) {
        adj[f[0]].push_back({f[1], f[2]}); // u -> v with cost
    }

    // Min-heap: {cost, node, stops}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src, 0}); // cost=0, src node, 0 stops

    // Track best (cost, stops) to reach a node
    vector<int> dist(n, INT_MAX);
    vector<int> stops(n, INT_MAX);

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int cost = cur[0], node = cur[1], step = cur[2];

        // If destination reached within allowed stops → return cost
        if (node == dst) return cost;

        // If stops exceed K, skip
        if (step > K) continue;

        for (auto &[nei, price] : adj[node]) {
            int newCost = cost + price;

            // Push into PQ if either:
            // 1) Found cheaper cost, or
            // 2) Reached with fewer stops
            if (newCost < dist[nei] || step < stops[nei]) {
                dist[nei] = newCost;
                stops[nei] = step;
                pq.push({newCost, nei, step + 1});
            }
        }
    }

    return -1;
}

int main() {
    // ---------- Testcase 1 ----------
    {
        int n = 3;
        vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
        int src = 0, dst = 2, K = 1;
        cout << "Cheapest Price (TC1): " << findCheapestPrice(n, flights, src, dst, K) << endl;
        // Expected: 200 (0->1->2)
    }

    // ---------- Testcase 2 ----------
    {
        int n = 4;
        vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,3,100},{0,3,500}};
        int src = 0, dst = 3, K = 1;
        cout << "Cheapest Price (TC2): " << findCheapestPrice(n, flights, src, dst, K) << endl;
        // Expected: 500 (direct, since 0->1->2->3 requires 2 stops > K)
    }

    // ---------- Testcase 3 ----------
    {
        int n = 4;
        vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,3,100},{0,3,500}};
        int src = 0, dst = 3, K = 2;
        cout << "Cheapest Price (TC3): " << findCheapestPrice(n, flights, src, dst, K) << endl;
        // Expected: 300 (0->1->2->3)
    }

    // ---------- Testcase 4 (Unreachable) ----------
    {
        int n = 3;
        vector<vector<int>> flights = {{0,1,200}};
        int src = 0, dst = 2, K = 1;
        cout << "Cheapest Price (TC4): " << findCheapestPrice(n, flights, src, dst, K) << endl;
        // Expected: -1 (no path to node 2)
    }

    return 0;
}
