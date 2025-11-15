#include <bits/stdc++.h>
using namespace std;

// Function to sort a nearly k-sorted array
void sortNearlyKSorted(vector<int>& arr, int k) {
    // Min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    int n = arr.size();
    int idx = 0;

    // Step 1: Insert first k+1 elements in heap
    for (int i = 0; i <= k && i < n; i++) {
        pq.push(arr[i]);
    }

    // Step 2: Process remaining elements
    for (int i = k + 1; i < n; i++) {
        // Extract minimum element and place in correct position
        arr[idx++] = pq.top();
        pq.pop();

        // Push current element
        pq.push(arr[i]);
    }

    // Step 3: Extract remaining heap elements
    while (!pq.empty()) {
        arr[idx++] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<pair<vector<int>, int>> testcases = {
        {{6, 5, 3, 2, 8, 10, 9}, 3},   // Nearly 3-sorted
        {{10, 9, 8, 7, 4, 70, 60, 50}, 4}, // Nearly 4-sorted
        {{1, 2, 3, 4, 5}, 2},          // Already sorted
        {{3, 1, 2}, 2}                 // Nearly 2-sorted
    };

    for (int i = 0; i < testcases.size(); i++) {
        auto arr = testcases[i].first;
        int k = testcases[i].second;

        cout << "Testcase " << i+1 << ": k = " << k << "\n";
        cout << "Original: ";
        for (int x : arr) cout << x << " ";
        cout << "\n";

        sortNearlyKSorted(arr, k);

        cout << "Sorted:   ";
        for (int x : arr) cout << x << " ";
        cout << "\n\n";
    }

    return 0;
}
