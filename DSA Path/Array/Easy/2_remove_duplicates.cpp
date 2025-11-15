#include<bits/stdc++.h>
using namespace std;

void remove_duplicates(vector<int>& nums){
    int idx = 1,temp = nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=temp){
            nums[idx] = nums[i];
            temp = nums[i];
            idx++;
        }
    }
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    remove_duplicates(nums);
    for(auto it : nums)
        cout<<it<<" ";
    cout<<endl;
}