#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subarraySumMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n), nse(n);
        stack<int> st;

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // Next Smaller (take >= to avoid double counting)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans += 1LL * arr[i] * left * right;
        }
        return ans;
    }

    long long subarraySumMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n), nge(n);
        stack<int> st;

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // Next Greater (take <= to avoid double counting)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            ans += 1LL * arr[i] * left * right;
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subarraySumMaxs(nums) - subarraySumMins(nums);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> testcases = {
        {1,2,3},        // Expected: 4
        {1,3,3},        // Expected: 4
        {4,-2,-3,4,1},  // Expected: 59
        {1},            // Expected: 0
        {2,2,2}         // Expected: 0
    };

    for (auto &tc : testcases) {
        cout << "Input: ";
        for (int x : tc) cout << x << " ";
        cout << "\nOutput: " << sol.subArrayRanges(tc) << "\n\n";
    }
    return 0;
}
