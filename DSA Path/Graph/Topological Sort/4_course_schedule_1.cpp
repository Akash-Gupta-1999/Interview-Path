#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int c = 0;
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
        c++;
        for (int v : adj[node]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    return c == numCourses;
}

int main() {
    // ---------- Testcase 1 ----------
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1, 0}}; 
        cout << "Can finish (TC1): " << canFinish(numCourses, prerequisites) << endl; 
        // Expected: 1 (true) → Course 0 → Course 1
    }

    // ---------- Testcase 2 ----------
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1, 0}, {0, 1}}; 
        cout << "Can finish (TC2): " << canFinish(numCourses, prerequisites) << endl; 
        // Expected: 0 (false) → cycle exists
    }

    // ---------- Testcase 3 ----------
    {
        int numCourses = 4;
        vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}}; 
        cout << "Can finish (TC3): " << canFinish(numCourses, prerequisites) << endl; 
        // Expected: 1 (true) → 0 → 1 → 2 → 3
    }

    // ---------- Testcase 4 ----------
    {
        int numCourses = 3;
        vector<vector<int>> prerequisites = {{0, 1}, {1, 2}, {2, 0}}; 
        cout << "Can finish (TC4): " << canFinish(numCourses, prerequisites) << endl; 
        // Expected: 0 (false) → cycle 0 → 1 → 2 → 0
    }

    // ---------- Testcase 5 ----------
    {
        int numCourses = 5;
        vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 3}}; 
        cout << "Can finish (TC5): " << canFinish(numCourses, prerequisites) << endl; 
        // Expected: 1 (true) → 0 → 1/2 → 3 → 4
    }

    return 0;
}
