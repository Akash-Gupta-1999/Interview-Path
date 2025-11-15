#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int swap_ptr = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[swap_ptr],nums[i]);
            swap_ptr++;
        }
    }
}

int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for(auto it : nums)
        cout<<it<<" ";
    cout<<endl;
}