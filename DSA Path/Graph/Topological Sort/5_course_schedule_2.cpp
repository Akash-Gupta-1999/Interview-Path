#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> topoOrder;
    vector<int> indegree(numCourses, 0);
    queue<int> q;
    vector<vector<int>> adj(numCourses);

    // Build adjacency list
    for (auto it : prerequisites) {
        adj[it[1]].push_back(it[0]);
    }

    // Compute indegree
    for (int i = 0; i < numCourses; i++) {
        for (int v : adj[i])
            indegree[v]++;
    }

    // Push courses with no prerequisites
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    // Process courses
    while (!q.empty()) {
        int node = q.front(); 
        q.pop();
        topoOrder.push_back(node);
        for (int v : adj[node]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    if (topoOrder.size() != numCourses) return {}; // cycle detected
    return topoOrder;
}

int main() {
    // ---------- Testcase 1 ----------
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1, 0}};
        vector<int> result = findOrder(numCourses, prerequisites);
        cout << "Order (TC1): ";
        for (int x : result) cout << x << " ";
        cout << endl; 
        // Expected: 0 1
    }

    // ---------- Testcase 2 ----------
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
        vector<int> result = findOrder(numCourses, prerequisites);
        cout << "Order (TC2): ";
        for (int x : result) cout << x << " ";
        cout << endl; 
        // Expected: empty (cycle)
    }

    // ---------- Testcase 3 ----------
    {
        int numCourses = 4;
        vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
        vector<int> result = findOrder(numCourses, prerequisites);
        cout << "Order (TC3): ";
        for (int x : result) cout << x << " ";
        cout << endl; 
        // Expected: 0 1 2 3 or 0 2 1 3
    }

    // ---------- Testcase 4 ----------
    {
        int numCourses = 3;
        vector<vector<int>> prerequisites = {{0, 1}, {1, 2}, {2, 0}};
        vector<int> result = findOrder(numCourses, prerequisites);
        cout << "Order (TC4): ";
        for (int x : result) cout << x << " ";
        cout << endl; 
        // Expected: empty (cycle)
    }

    // ---------- Testcase 5 ----------
    {
        int numCourses = 5;
        vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 3}};
        vector<int> result = findOrder(numCourses, prerequisites);
        cout << "Order (TC5): ";
        for (int x : result) cout << x << " ";
        cout << endl; 
        // Expected: 0 1 2 3 4 (or 0 2 1 3 4)
    }

    return 0;
}
