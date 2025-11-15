#include<bits/stdc++.h>
using namespace std;

class LazySegmentTree{
    public:
        int n;
        vector<int> tree,lazy;
        LazySegmentTree(int n){
            this->n = n;
            tree.assign(4*n,0);
            lazy.assign(4*n,0);
        }

        void helper_build(int i,int low,int high,vector<int>& arr){
            if(low == high)
                tree[i] = arr[low];
            else{
                int mid = low + (high-low)/2;
                helper_build(2*i+1,low,mid,arr);
                helper_build(2*i+2,mid+1,high,arr);
                tree[i] = tree[2*i+1] + tree[2*i+2];
            }
        }

        void build(vector<int>& arr){
            helper_build(0,0,n-1,arr);
        }

        void pushdown(int i,int low,int high){
            if(lazy[i]!=0){
                tree[i] += (high-low+1) * lazy[i];
                if(low!=high){
                    lazy[2*i+1] += lazy[i];
                    lazy[2*i+2] += lazy[i];
                }
                lazy[i] = 0;
            }
        }

        void helper_updaterange(int i,int low,int high,int l,int r,int val){
            pushdown(i,low,high);
            if(r<low || l>high)
                return;
            if(l <= low && high <= r){
                lazy[i] += val;
                pushdown(i,low,high);
                return;
            }
            int mid = low + (high-low)/2;
            helper_updaterange(2*i+1,low,mid,l,r,val);
            helper_updaterange(2*i+2,mid+1,high,l,r,val);
            tree[i] = tree[2*i+1] + tree[2*i+2];
        }

        void updaterange(int l,int r,int val){
            helper_updaterange(0,0,n-1,l,r,val);
        }

        int helper_sumrange(int i,int low,int high,int l,int r){
            pushdown(i,low,high);
            if(l>high || r<low)
                return 0;
            if(l <= low && high <= r)
                return tree[i];
            int mid = low+(high-low)/2;
            return helper_sumrange(2*i+1,low,mid,l,r) + helper_sumrange(2*i+2,mid+1,high,l,r);
        }

        int sumrange(int l,int r){
            return helper_sumrange(0,0,n-1,l,r);
        }
};

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    LazySegmentTree st(n);

    // Build tree
    st.build(arr);

    // Queries
    cout << "Initial sum of [0, 4] = " << st.sumrange(0, 4) << endl; // 15

    // Update range
    st.updaterange(1, 3, 5); // add 5 to every element in [1, 3]
    cout << "After adding 5 to [1, 3], sum of [0, 4] = " << st.sumrange(0, 4) << endl; // 30

    // Partial query
    cout << "Sum of [2, 4] = " << st.sumrange(2, 4) << endl; // 22

    // Another update
    st.updaterange(0, 2, 2); // add 2 to [0, 2]
    cout << "After adding 2 to [0, 2], sum of [0, 4] = " << st.sumrange(0, 4) << endl; // 36

    return 0;
}