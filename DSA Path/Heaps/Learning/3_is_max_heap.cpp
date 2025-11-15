#include <bits/stdc++.h>
using namespace std;

// Function to check if an array is a max-heap
bool isMaxHeap(const vector<int>& arr) {
    int n = arr.size();

    /*
      Internal node condition:
      - A node at index i is internal if left child exists
        i.e., 2*i + 1 < n
      - Solve: i < (n-1)/2

      Equivalent forms:
        i <= (n-2)/2   <=>   i < (n-1)/2   <=>   i < n/2
    */

    for (int i = 0; i < (n - 1) / 2; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        // If parent is smaller than left child → violates max-heap
        if (left < n && arr[i] < arr[left]) return false;

        // If parent is smaller than right child → violates max-heap
        if (right < n && arr[i] < arr[right]) return false;
    }
    return true;
}

int main() {
    // Testcases
    vector<vector<int>> testcases = {
        {90, 15, 10, 7, 12, 2},       // should be max-heap
        {9, 15, 10, 7, 12, 2},        // not a max-heap
        {100, 50, 30, 20, 10, 15},    // should be max-heap
        {10, 9, 8, 7, 6, 5},          // should be max-heap
        {10, 20, 5, 6, 1},            // not a max-heap
    };

    for (int i = 0; i < testcases.size(); i++) {
        cout << "Testcase " << i + 1 << ": ";
        if (isMaxHeap(testcases[i])) 
            cout << "YES, it is a max-heap" << endl;
        else 
            cout << "NO, not a max-heap" << endl;
    }

    return 0;
}
