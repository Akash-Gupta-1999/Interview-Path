#include <bits/stdc++.h>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;

    // Contribution as maximum
    stack<int> st;
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
            int j = st.top(); st.pop();
            int left = st.empty() ? j + 1 : j - st.top();
            int right = i - j;
            ans += (long long) nums[j] * left * right;
        }
        st.push(i);
    }

    // Contribution as minimum
    while (!st.empty()) st.pop();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
            int j = st.top(); st.pop();
            int left = st.empty() ? j + 1 : j - st.top();
            int right = i - j;
            ans -= (long long) nums[j] * left * right;
        }
        st.push(i);
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    cout << subArrayRanges(nums) << endl; // Output: 4

    nums = {1,3,3};
    cout << subArrayRanges(nums) << endl; // Output: 4

    nums = {4,-2,-3,4,1};
    cout << subArrayRanges(nums) << endl; // Output: 59
}
