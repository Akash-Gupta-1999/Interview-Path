#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k){
    k%=nums.size();
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = 43;
    rotate(nums, k);
    for(auto it : nums)
        cout<<it<<" ";
    cout<<endl;
}