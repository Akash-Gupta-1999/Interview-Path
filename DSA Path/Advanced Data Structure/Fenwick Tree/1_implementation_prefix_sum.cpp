#include<bits/stdc++.h>
using namespace std;

class fenwicktree{
    public:
        int n;
        vector<int> ft;
        
        // Constructor: initialize Fenwick Tree with n elements
        fenwicktree(int n){
            this->n = n;
            ft.assign(n+1,0); // 1-based internal indexing
        }

        // Update: add `val` at index i (0-based external, converted to 1-based inside)
        void update(int i,int val){
            i++; // shift to 1-based
            while(i <= n){
                ft[i] += val;           // add value to this node
                i += (i & -i);          // move to next responsible node
                // Intuition: (i & -i) gives the lowest set bit,
                // so we jump to the parent interval that includes this index
            }
        }

        // Build tree from an array in O(n log n)
        void buildtree(vector<int> arr){
            for(int i = 0; i < n; i++){
                this->update(i, arr[i]);
            }
        }

        // Query prefix sum from [0..i]
        int query(int i){
            i++; // shift to 1-based
            int sum = 0;
            while(i > 0){
                sum += ft[i];           // add contribution of this Fenwick node
                i -= (i & -i);          // move to ancestor (remove lowest set bit)
                // Intuition: each node stores sum of a "range",
                // and by removing the lowest set bit we climb upwards to cover all ranges
            }
            return sum;
        }
        
        // Range sum query [l..r]
        int range(int l, int r){
            // Prefix sum till r minus prefix sum till l-1
            return query(r) - (l > 0 ? query(l - 1) : 0);
        }
};

int main(){
    // Example array
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = arr.size();
    fenwicktree ft(n);

    // Build the Fenwick Tree
    ft.buildtree(arr);

    cout << "Initial prefix sums:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Sum [0.." << i << "] = " << ft.query(i) << endl;
    }

    // Range query example
    cout << "\nRange sum [2..4] = " << ft.range(2, 4) << endl;

    // Update example: arr[3] += 2
    cout << "\nUpdating arr[3] += 2" << endl;
    ft.update(3, 2);

    cout << "New prefix sums:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Sum [0.." << i << "] = " << ft.query(i) << endl;
    }

    cout << "\nNew range sum [2..4] = " << ft.range(2, 4) << endl;

    return 0;
}
