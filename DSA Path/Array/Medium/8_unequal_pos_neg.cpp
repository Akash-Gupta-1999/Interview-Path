#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size(),0);
    vector<int> pos,neg;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=0){
            pos.push_back(nums[i]);
        }
        else{
            neg.push_back(nums[i]);
        }
    }
    int i=0,j=0,k=0;
    while(i<pos.size() && j<neg.size()){
        if(k%2==0){
            ans[k] = pos[i];
            k++;
            i++;
        }
        else{
            ans[k] = neg[j];
            k++;
            j++;
        }
    }
    while(i<pos.size()){
        ans[k] = pos[i];
        i++;
        k++;
    }
    while(j<neg.size()){
        ans[k] = neg[j];
        j++;
        k++;
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