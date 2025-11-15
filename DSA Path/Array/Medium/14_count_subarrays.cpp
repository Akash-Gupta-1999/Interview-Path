#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int prefsum = 0,count = 0;
        for(int i=0;i<nums.size();i++){
            prefsum+=nums[i];
            if(prefsum == k)
                count++;
            count+=umap[prefsum-k];
            umap[prefsum]+=1;
        }
        return count;
    }

int main()
{
    vector arr = {1,1,1};
    int k = 2;
    int cnt = subarraySum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}