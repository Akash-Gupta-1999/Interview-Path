#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    
    for (int i = 2*n - 1; i >= 0; i--) {
        int num = nums[i % n];
        while (!st.empty() && st.top() <= num)
            st.pop();
        if (!st.empty())
            ans[i % n] = st.top();
        st.push(num);
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,1};
    vector<int> result = nextGreaterElements(nums);
    
    cout << "Result for nums = {1,2,1}: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Extra test case
    nums = {5,4,3,2,1};
    result = nextGreaterElements(nums);
    cout << "Result for nums = {5,4,3,2,1}: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Extra test case
    nums = {1,2,3,4,3};
    result = nextGreaterElements(nums);
    cout << "Result for nums = {1,2,3,4,3}: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
