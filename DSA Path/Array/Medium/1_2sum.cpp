#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int val = target - nums[i];
            if(umap.find(val) != umap.end()){
                ans = {i,umap[val]};
                break;
            }
            else{
                umap[nums[i]] = i;
            }
        }
        return ans;
    }

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(arr, target);
    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}