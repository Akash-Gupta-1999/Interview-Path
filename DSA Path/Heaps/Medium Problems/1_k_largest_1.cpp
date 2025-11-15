#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using max-heap of all elements
int findKthLargest_maxHeap(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (int num : nums) pq.push(num);

    int ans = -1;
    while (k > 0) {
        ans = pq.top();
        pq.pop();
        k--;
    }
    return ans;
}

// Approach 2: Using min-heap of size k (optimized)
int findKthLargest_minHeap(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num : nums) {
        pq.push(num);
        if (pq.size() > k) pq.pop();
    }
    return pq.top();
}

int main() {
    vector<pair<vector<int>, int>> testcases = {
        {{3, 2, 1, 5, 6, 4}, 2},       // 2nd largest = 5
        {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4}, // 4th largest = 4
        {{10, 7, 11, 5, 8}, 3},        // 3rd largest = 8
        {{1}, 1},                      // only element = 1
        {{9, 8, 7, 6, 5}, 5}           // 5th largest = 5
    };

    for (int i = 0; i < testcases.size(); i++) {
        auto nums = testcases[i].first;
        int k = testcases[i].second;

        cout << "Testcase " << i+1 << ": nums = [ ";
        for (int x : nums) cout << x << " ";
        cout << "], k = " << k << "\n";

        cout << "  Max-Heap approach: " << findKthLargest_maxHeap(nums, k) << "\n";
        cout << "  Min-Heap approach: " << findKthLargest_minHeap(nums, k) << "\n\n";
    }

    return 0;
}
