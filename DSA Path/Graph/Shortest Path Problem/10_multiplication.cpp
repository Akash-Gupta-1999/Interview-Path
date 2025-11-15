#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    const int MOD = 100000;
    vector<int> dist(MOD, INT_MAX);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (num == end) return dist[num];

        for (int val : arr) {
            int next = (num * val) % MOD;
            if (dist[num] + 1 < dist[next]) {
                dist[next] = dist[num] + 1;
                q.push(next);
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> testArrays = {
        {2, 5, 7},
        {3, 4, 65},
        {2, 3},
        {7}
    };
    vector<int> starts = {3, 7, 3, 5};
    vector<int> ends   = {30, 66175, 99999, 99999};

    for (int t = 0; t < testArrays.size(); t++) {
        cout << "Test Case " << t + 1 << ":\n";
        cout << "arr = [ ";
        for (auto x : testArrays[t]) cout << x << " ";
        cout << "], start = " << starts[t] << ", end = " << ends[t] << "\n";

        int ans = minimumMultiplications(testArrays[t], starts[t], ends[t]);
        cout << "Minimum Multiplications = " << ans << "\n\n";
    }

    return 0;
}
