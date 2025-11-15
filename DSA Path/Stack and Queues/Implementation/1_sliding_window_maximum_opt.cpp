#include <bits/stdc++.h>
using namespace std;

// Optimal O(n) solution using Monotonic Deque
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;   // stores indices, values are nums[dq[i]]
    vector<int> ans;

    for(int i=0; i<nums.size(); i++) {
        // 1. Remove index if it’s out of the current window
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();

        // 2. Maintain decreasing order of values in deque
        // Pop all smaller values from the back
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        // 3. Push current index
        dq.push_back(i);

        // 4. Window starts forming when i >= k-1
        if(i >= k-1)
            ans.push_back(nums[dq.front()]); // max element of window
    }

    return ans;
}

int main() {
    vector<vector<int>> testCases = {
        {1,3,-1,-3,5,3,6,7},   // mixed positives/negatives
        {9,9,9,9,9},           // all equal
        {1,2,3,4,5},           // increasing
        {5,4,3,2,1},           // decreasing
        {1},                   // single element
        {1,3,1,2,0,5}          // random
    };
    vector<int> ks = {3, 2, 2, 3, 1, 3};

    for(int t=0; t<testCases.size(); t++) {
        vector<int> nums = testCases[t];
        int k = ks[t];
        cout << "Test " << t+1 << ": nums = ";
        for(int x: nums) cout << x << " ";
        cout << " k = " << k << "\n";

        vector<int> res = maxSlidingWindow(nums, k);
        cout << "Output: ";
        for(int x: res) cout << x << " ";
        cout << "\n\n";
    }
    return 0;
}
