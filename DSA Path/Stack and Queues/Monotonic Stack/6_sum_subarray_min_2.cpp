#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> pse(n), nse(n); // store indices, not counts
        stack<int> st;

        // Previous Smaller Element (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top(); // index of prev smaller
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element (smaller OR equal)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top(); // index of next smaller
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];   // distance to prev smaller
            long long right = nse[i] - i; // distance to next smaller
            ans = (ans + arr[i] * left % MOD * right % MOD) % MOD;
        }
        return (int)ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testcases = {
        {3,1,2,4},       // Expected: 17
        {11,81,94,43,3}, // Expected: 444
        {1,2,3},         // Expected: 10
        {71,55,82,55},   // Expected: 593
        {5},             // Single element
        {2,2,2},         // All same elements
    };

    for (auto &tc : testcases) {
        cout << "Input: ";
        for (int x : tc) cout << x << " ";
        cout << "\nOutput: " << sol.sumSubarrayMins(tc) << "\n\n";
    }

    return 0;
}
