#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int,int> freq;
    priority_queue<int> pq;
    int i = 0, n = nums.size();

    // Build first window
    while(i<n && i<k){
        freq[nums[i]]++;
        pq.push(nums[i]);
        i++;
    }
    ans.push_back(pq.top());

    // Slide the window
    while(i<n){
        // Remove outgoing element
        freq[nums[i-k]]--;
        if(freq[nums[i-k]] == 0) freq.erase(nums[i-k]);

        // Add new element
        freq[nums[i]]++;
        pq.push(nums[i]);

        // Clean up invalid elements from heap
        while(!pq.empty() && (freq.find(pq.top()) == freq.end() || freq[pq.top()] == 0))
            pq.pop();

        ans.push_back(pq.top());
        i++;
    }
    return ans;
}

// -------- MAIN with test cases --------
int main() {
    vector<vector<int>> testNums = {
        {1,3,-1,-3,5,3,6,7},   // mix +/-
        {9, 10, 9, -7, -4, -8, 2, -6}, // duplicates + negatives
        {1},                   // single element
        {4,4,4,4,4},           // all same elements
        {10,9,8,7,6,5,4,3,2,1} // strictly decreasing
    };

    vector<int> testK = {3, 5, 1, 2, 4};

    for (int t = 0; t < testNums.size(); t++) {
        cout << "Test " << t+1 << ": nums = ";
        for (int x : testNums[t]) cout << x << " ";
        cout << ", k = " << testK[t] << endl;

        vector<int> result = maxSlidingWindow(testNums[t], testK[t]);
        cout << "Output: ";
        for (int x : result) cout << x << " ";
        cout << "\n\n";
    }

    return 0;
}
