#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                if(count)
                    count--;
                else
                    return false;
            }
        }
        if(nums[0] < nums[nums.size()-1] && count == 0)
            return false;
        return true;
    }

int main(){
    vector<int> nums = {2,1,3,4};
    cout<<check(nums)<<endl;
}