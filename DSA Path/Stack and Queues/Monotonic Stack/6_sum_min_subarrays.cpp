#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n), right(n);
    stack<pair<int,int>> st;
    const int mod = 1000000007;

    // left[i] = number of consecutive elements to the LEFT (including self)
    //           where nums[i] is the minimum
    // use '>' so we stop at equal (avoid double count on left side)
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (!st.empty() && st.top().first > nums[i]) {
            count += st.top().second;
            st.pop();
        }
        st.push({nums[i], count});
        left[i] = count;
    }

    while (!st.empty()) st.pop();

    // right[i] = number of consecutive elements to the RIGHT (including self)
    //            where nums[i] is the minimum
    // use '>=' so equal elements are handled on the left side only
    for (int i = n - 1; i >= 0; i--) {
        int count = 1;
        while (!st.empty() && st.top().first >= nums[i]) {
            count += st.top().second;
            st.pop();
        }
        st.push({nums[i], count});
        right[i] = count;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + (1LL * left[i] * right[i] % mod) * nums[i] % mod) % mod;
    }

    return (int)ans;
}

int main() {
    vector<vector<int>> testcases = {
        {3, 1, 2, 4},       // expected = 17
        {11, 81, 94},       // expected = 176
        {2, 9, 7, 8, 3, 4, 6, 1}, // a bit bigger example
        {1, 1, 1, 1}        // all same numbers
    };

    for (auto &tc : testcases) {
        cout << "Array: ";
        for (int x : tc) cout << x << " ";
        cout << "\nSum of Subarray Minimums = " << sumSubarrayMins(tc) << "\n\n";
    }

    return 0;
}
