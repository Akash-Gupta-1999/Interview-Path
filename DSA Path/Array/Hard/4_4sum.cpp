#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j= i+1;j<nums.size();j++){
            if(j>i + 1 && nums[j] == nums[j-1]) continue;
            int k = j+1, l = nums.size()-1;
            while(k<l){
                long long sum = nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum == target){
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k-1] == nums[k]) k++;
                    while(k<l && nums[l+1] == nums[l]) l--;
                }
                else if(sum > target)
                    l--;
                else
                    k++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = fourSum(arr, target);
    for(auto it : ans){
        for(auto it1 : it)
            cout<<it1<<" ";
        cout<<endl;
    }
}