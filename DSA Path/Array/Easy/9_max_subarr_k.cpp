#include <bits/stdc++.h>
using namespace std;

int max_subarray_k(vector<int>& num, int k){
    unordered_map<int,int> umap;
    int prefsum = 0,max_len = 0;
    for(int i = 0;i<num.size();i++){
        prefsum+=num[i];
        if(prefsum == k)
            max_len = max(max_len, i+1);
        if(umap.find(prefsum-k) != umap.end()){
            max_len = max(max_len,i-umap[prefsum-k]);
        }
        if(umap.find(prefsum) == umap.end())
            umap[prefsum] = i;
    }
    return max_len;
}

int main()
{
    int k = -5;
    vector<int> a = {-5,8,-14,2,4,12};
    int ans = max_subarray_k(a,k);
    cout << "Max contiguous subarray with value k is : " << ans << endl;
    return 0;
}