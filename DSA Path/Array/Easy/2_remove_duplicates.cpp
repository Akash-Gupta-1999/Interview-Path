#include<bits/stdc++.h>
using namespace std;

void remove_duplicates(vector<int>& nums){
    int idx = 1,last = nums[0],unique_count = 1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=last){
            last = nums[i];
            swap(nums[idx],nums[i]);
            idx++;
            unique_count++;
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