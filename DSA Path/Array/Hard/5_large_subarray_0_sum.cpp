#include <bits/stdc++.h>
using namespace std;

int max_subarray_0(vector<int>& nums){
    unordered_map<int,int> umap;
    int max_length = 0;
    int prefixsum = 0;
    for(int i=0;i<nums.size();i++){
        prefixsum+=nums[i];
        if(prefixsum == 0){
            max_length = max(max_length, i + 1);
        }
        if(umap.find(prefixsum) != umap.end()){
            max_length = max(max_length, i - umap[prefixsum]);
        }
        else
            umap[prefixsum] = i;
    }
    return max_length;
}

int main()
{
    vector<int> a = {2, 0, -2};
    int ans = max_subarray_0(a);
    cout << "Max contiguous subarray with value 0 is : " << ans << endl;
    return 0;
}