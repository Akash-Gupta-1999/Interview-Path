#include <bits/stdc++.h>
using namespace std;

/*
    ✅ Segment Tree for Range Sum Queries + Point Updates

    Intuition:
    - A segment tree is a binary tree where each node represents
      the sum of a segment (range) of the array.
    - Root node represents the sum of the entire array.
    - Each internal node represents the sum of a subarray (left+right child).
    - This allows:
        - Building in O(n)
        - Querying sum in O(log n)
        - Updating a value in O(log n)
*/
class SegmentTree {
public:
    vector<int> st;  // array to store the segment tree
    int n;           // size of the original array

    // Constructor
    SegmentTree(int n) {
        this->n = n;
        st.assign(4*n, 0); // 4*n space is enough to safely store tree
    }

    // ---------------- BUILD ----------------
    /*
        Build the tree recursively.
        i   = current tree node index
        arr = original array
        low, high = range of this node in the array

        Intuition:
        - If low == high → leaf node → directly store arr[low]
        - Else:
            - Split into [low..mid] and [mid+1..high]
            - Recursively build left and right children
            - Current node = sum of left + right
    */
    void helper_build(int i, vector<int>& arr, int low, int high) {
        if (low == high) {
            st[i] = arr[low]; // leaf node
        } else {
            int mid = low + (high-low)/2;
            helper_build(2*i+1, arr, low, mid);       // left child
            helper_build(2*i+2, arr, mid+1, high);    // right child
            st[i] = st[2*i+1] + st[2*i+2];            // merge results
        }
    }

    void build(vector<int>& arr) {
        helper_build(0, arr, 0, n-1);
    }

    // ---------------- QUERY SUM ----------------
    /*
        Query sum in range [l, r].
        i   = current tree node index
        low, high = range of this node in the array

        Intuition:
        - 3 cases:
            1. No Overlap → return 0
            2. Complete Overlap → return st[i]
            3. Partial Overlap → split into children
    */
    int helper_sum(int l, int r, int low, int high, int i) {
        if (r < low || l > high) return 0;            // no overlap
        if (l <= low && high <= r) return st[i];      // complete overlap
        int mid = low + (high-low)/2;                 // partial overlap → split
        return helper_sum(l, r, low, mid, 2*i+1) +
               helper_sum(l, r, mid+1, high, 2*i+2);
    }

    int sum(int l, int r) {
        return helper_sum(l, r, 0, n-1, 0);
    }

    // ---------------- UPDATE ----------------
    /*
        Update arr[idx] = val.
        i   = current tree node index
        low, high = range of this node

        Intuition:
        - If leaf node (low == high == idx) → update value
        - Else:
            - Go left if idx in left half
            - Else go right
            - After updating child, recompute st[i] = left+right
    */
    void helper_update(vector<int>& arr, int low, int high, int i, int idx, int val) {
        if (low == high) {            // leaf node
            st[i] = val;
            arr[idx] = val;           // also update original array
        } else {
            int mid = low+(high-low)/2;
            if (idx <= mid) helper_update(arr, low, mid, 2*i+1, idx, val);
            else helper_update(arr, mid+1, high, 2*i+2, idx, val);
            st[i] = st[2*i+1] + st[2*i+2]; // update parent node
        }
    }

    void update(vector<int>& arr, int idx, int val) {
        helper_update(arr, 0, n-1, 0, idx, val);
    }

    // Print the internal tree array
    void print() {
        for (int i=0;i<st.size();i++)
            cout<<st[i]<<" ";
        cout<<endl;
    }
};

int main() {
    vector<int> arr = {3,8,7,6,-2,-8,4,9};
    SegmentTree st(arr.size());
    st.build(arr);

    cout << "Initial Segment Tree:\n";
    st.print();

    cout << "\n=== Testcases ===\n";

    // Full sum
    cout << "Sum(0,7) = " << st.sum(0,7) << " (Expected: 27)\n";

    // Range sums
    cout << "Sum(2,4) = " << st.sum(2,4) << " (Expected: 11)\n";
    cout << "Sum(0,3) = " << st.sum(0,3) << " (Expected: 24)\n";
    cout << "Sum(4,7) = " << st.sum(4,7) << " (Expected: 3)\n";

    // Point update
    st.update(arr, 3, 10);  // arr[3] = 10
    cout << "\nAfter update arr[3] = 10\n";
    cout << "Sum(2,4) = " << st.sum(2,4) << " (Expected: 15)\n";
    cout << "Sum(0,7) = " << st.sum(0,7) << " (Expected: 31)\n";

    // Another update
    st.update(arr, 0, 5);  // arr[0] = 5
    cout << "\nAfter update arr[0] = 5\n";
    cout << "Sum(0,3) = " << st.sum(0,3) << " (Expected: 30)\n";
    cout << "Sum(0,7) = " << st.sum(0,7) << " (Expected: 33)\n";

    // Edge cases
    cout << "\nEdge case queries:\n";
    cout << "Sum(0,0) = " << st.sum(0,0) << " (Expected: 5)\n";
    cout << "Sum(7,7) = " << st.sum(7,7) << " (Expected: 9)\n";
    cout << "Sum(5,6) = " << st.sum(5,6) << " (Expected: -4)\n";

    return 0;
}
