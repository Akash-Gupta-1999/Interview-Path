#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    int cnt1=0, cnt2=0,el1 = INT_MIN,el2 = INT_MIN; // atmost only 2 elements can be in an array with more than n/3 frequency
    for(int i=0;i<nums.size();i++){
        if(cnt1 == 0 && nums[i]!= el2){
            el1 = nums[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && nums[i]!=el1){
            el2 = nums[i];
            cnt2 = 1;
        }
        else if(nums[i] == el1)
            cnt1++;
        else if(nums[i] == el2)
            cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == el1)
            cnt1++;
        else if(nums[i] == el2)
            cnt2++;
    }
    if(cnt1 > nums.size()/3)
        ans.push_back(el1);
    if(cnt2 > nums.size()/3)
        ans.push_back(el2);
    return ans;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 3, 3, 2, 1, 2, 4};
    vector<int> ans = majorityElement(arr);
    for(auto it : ans)
        cout << it << " ";
    cout<<endl;
    return 0;
}