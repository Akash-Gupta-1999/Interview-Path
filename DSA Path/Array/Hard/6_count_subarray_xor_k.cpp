#include <bits/stdc++.h>
using namespace std;

int max_subarray_k(vector<int>& nums, int k){
    int count = 0, prefixor = 0;
    unordered_map<int,int> umap;
    for(int i=0;i<nums.size();i++){
        prefixor^=nums[i];
        if(prefixor == k)
            count+=1;
        count+=umap[prefixor^k];
        umap[prefixor]++;
    }
    return count;
}

int main()
{
    int k = 6;
    vector<int> a = {4, 2, 2, 6, 4};
    int ans = max_subarray_k(a,k);
    cout << "Max contiguous subarray with xor value k is : " << ans << endl;
    return 0;
}