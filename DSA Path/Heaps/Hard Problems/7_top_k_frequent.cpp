#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Min-Heap
- Count frequencies.
- Keep a min-heap of size k.
- Time: O(n log k), Space: O(n).
*/
vector<int> topKFrequent_heap(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(int num : nums) freq[num]++;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto& [num, f] : freq) {
        pq.push({f, num});
        if(pq.size() > k) pq.pop();
    }

    vector<int> result;
    while(!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

/*
Approach 2: Bucket Sort
- Count frequencies.
- Bucket[i] = list of numbers with frequency i.
- Traverse from high freq to low freq.
- Time: O(n), Space: O(n).
*/
vector<int> topKFrequent_bucket(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(int num : nums) freq[num]++;

    int n = nums.size();
    vector<vector<int>> buckets(n+1);
    for(auto& [num, f] : freq) {
        buckets[f].push_back(num);
    }

    vector<int> result;
    for(int i = n; i >= 0 && result.size() < k; i--) {
        for(int num : buckets[i]) {
            result.push_back(num);
            if(result.size() == k) break;
        }
    }
    return result;
}

int main() {
    vector<int> nums;
    int k;

    // Testcase 1
    nums = {1,1,1,2,2,3}; k = 2;
    auto ans1 = topKFrequent_heap(nums, k);
    auto ans1b = topKFrequent_bucket(nums, k);
    cout << "Heap TC1: "; for(int x: ans1) cout << x << " "; cout << "\n";
    cout << "Bucket TC1: "; for(int x: ans1b) cout << x << " "; cout << "\n";
    // Expected: [1,2]

    // Testcase 2
    nums = {1}; k = 1;
    auto ans2 = topKFrequent_heap(nums, k);
    auto ans2b = topKFrequent_bucket(nums, k);
    cout << "Heap TC2: "; for(int x: ans2) cout << x << " "; cout << "\n";
    cout << "Bucket TC2: "; for(int x: ans2b) cout << x << " "; cout << "\n";
    // Expected: [1]

    // Testcase 3
    nums = {4,4,4,5,5,6}; k = 2;
    auto ans3 = topKFrequent_heap(nums, k);
    auto ans3b = topKFrequent_bucket(nums, k);
    cout << "Heap TC3: "; for(int x: ans3) cout << x << " "; cout << "\n";
    cout << "Bucket TC3: "; for(int x: ans3b) cout << x << " "; cout << "\n";
    // Expected: [4,5]

    // Testcase 4
    nums = {7,7,7,8,8,9,9,9,9}; k = 3;
    auto ans4 = topKFrequent_heap(nums, k);
    auto ans4b = topKFrequent_bucket(nums, k);
    cout << "Heap TC4: "; for(int x: ans4) cout << x << " "; cout << "\n";
    cout << "Bucket TC4: "; for(int x: ans4b) cout << x << " "; cout << "\n";
    // Expected: [9,7,8] (order may vary)

    // Testcase 5
    nums = {1,2,3,4,5}; k = 5;
    auto ans5 = topKFrequent_heap(nums, k);
    auto ans5b = topKFrequent_bucket(nums, k);
    cout << "Heap TC5: "; for(int x: ans5) cout << x << " "; cout << "\n";
    cout << "Bucket TC5: "; for(int x: ans5b) cout << x << " "; cout << "\n";
    // Expected: [1,2,3,4,5]
}
