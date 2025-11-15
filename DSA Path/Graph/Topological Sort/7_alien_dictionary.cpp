#include <bits/stdc++.h>
using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adj; // graph adjacency list
    unordered_map<char, int> indegree;            // indegree of each character

    // Step 1: Initialize all characters
    for (string &word : words) {
        for (char c : word) {
            indegree[c] = 0;
        }
    }

    // Step 2: Build the graph by comparing adjacent words
    for (int i = 0; i < words.size() - 1; i++) {
        string w1 = words[i], w2 = words[i + 1];
        int len = min(w1.size(), w2.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                if (!adj[w1[j]].count(w2[j])) {
                    adj[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                found = true;
                break;
            }
        }

        // Check for invalid case: prefix situation like "abc", "ab"
        if (!found && w1.size() > w2.size()) return "";
    }

    // Step 3: Topological sort (Kahn's Algorithm)
    queue<char> q;
    for (auto &[c, deg] : indegree) {
        if (deg == 0) q.push(c);
    }

    string order;
    while (!q.empty()) {
        char node = q.front(); q.pop();
        order += node;
        for (char neigh : adj[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0) q.push(neigh);
        }
    }

    // Step 4: Check for cycle
    if (order.size() != indegree.size()) return "";

    return order;
}

int main() {
    // ---------- Testcase 1 ----------
    {
        vector<string> words = {"wrt","wrf","er","ett","rftt"};
        cout << "Alien Order (TC1): " << alienOrder(words) << endl;
        // Expected: "wertf"
    }

    // ---------- Testcase 2 ----------
    {
        vector<string> words = {"z","x"};
        cout << "Alien Order (TC2): " << alienOrder(words) << endl;
        // Expected: "zx"
    }

    // ---------- Testcase 3 ----------
    {
        vector<string> words = {"z","x","z"};
        cout << "Alien Order (TC3): " << alienOrder(words) << endl;
        // Expected: "" (cycle)
    }

    // ---------- Testcase 4 ----------
    {
        vector<string> words = {"abc","ab"};
        cout << "Alien Order (TC4): " << alienOrder(words) << endl;
        // Expected: "" (invalid order)
    }

    return 0;
}
