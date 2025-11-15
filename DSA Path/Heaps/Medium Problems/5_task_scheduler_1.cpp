#include <bits/stdc++.h>
using namespace std;

// Simulation using max-heap
int leastIntervalPQ(vector<char>& tasks, int n) {
    unordered_map<char,int> freq;
    for (char t : tasks) freq[t]++;

    // max-heap (most frequent task first)
    priority_queue<int> pq;
    for (auto &p : freq) pq.push(p.second);

    int time = 0;
    while (!pq.empty()) {
        vector<int> temp;
        int cycle = n + 1; // window size

        while (cycle-- > 0 && !pq.empty()) {
            int cnt = pq.top(); pq.pop();
            if (--cnt > 0) temp.push_back(cnt);
            time++; // execute one task or idle
        }

        for (int c : temp) pq.push(c);

        if (!pq.empty()) time += cycle + 1; 
        // add idle slots if tasks are still left
    }
    return time;
}

int main() {
    vector<pair<vector<char>, int>> testcases = {
        {{'A','A','A','B','B','B'}, 2},   // Expected: 8
        {{'A','A','A','B','B','B'}, 0},   // Expected: 6
        {{'A','B','C','D','E','F'}, 2},   // Expected: 6
        {{'A','A','A','A','B','B','C','C'}, 2} // Expected: 10
    };

    for (int i = 0; i < testcases.size(); i++) {
        auto tasks = testcases[i].first;
        int n = testcases[i].second;

        cout << "Testcase " << i+1 << " (cooldown = " << n << "):\n";
        cout << "Tasks: ";
        for (char t : tasks) cout << t << " ";
        cout << "\n";

        int ans = leastIntervalPQ(tasks, n);
        cout << "Least Interval: " << ans << "\n\n";
    }

    return 0;
}
