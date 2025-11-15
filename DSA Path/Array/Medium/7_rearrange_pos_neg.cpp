#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size(),0);
    int pos_idx =0, neg_idx = 1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=0){
            ans[pos_idx] = nums[i];
            pos_idx+=2;
        }
        else{
            ans[neg_idx] = nums[i];
            neg_idx+=2;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31};
    nums = rearrangeArray(nums);
    for(auto it : nums)
        cout<<it<<" ";
    cout<<endl;
}