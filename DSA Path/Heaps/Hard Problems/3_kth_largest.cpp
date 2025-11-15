#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums)
            add(num);
    }
    
    int add(int val) {
        if (pq.size() == k) {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        } else {
            pq.push(val);
        }
        return pq.top();
    }
};

int main() {
    // Testcase 1
    vector<int> nums1 = {4, 5, 8, 2};
    KthLargest kth1(3, nums1);
    cout << kth1.add(3) << "\n";   // Expected: 4
    cout << kth1.add(5) << "\n";   // Expected: 5
    cout << kth1.add(10) << "\n";  // Expected: 5
    cout << kth1.add(9) << "\n";   // Expected: 8
    cout << kth1.add(4) << "\n";   // Expected: 8

    cout << "----\n";

    // Testcase 2
    vector<int> nums2 = {1};
    KthLargest kth2(1, nums2);
    cout << kth2.add(-1) << "\n";  // Expected: 1
    cout << kth2.add(2) << "\n";   // Expected: 2
    cout << kth2.add(-3) << "\n";  // Expected: 2
    cout << kth2.add(4) << "\n";   // Expected: 4

    return 0;
}
