#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = nums[0];
    for(int i=1;i<nums.size();i++)
        ans^=nums[i];
    return ans;
}

int main()
{
    vector<int> a = {4,1,2,1,2};
    int ans = singleNumber(a);
    cout << "Missing Number is : " << ans << endl;
    return 0;
}