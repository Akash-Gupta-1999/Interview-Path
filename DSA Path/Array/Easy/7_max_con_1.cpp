#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, max_count = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == 1){
            count++;
            max_count = max(max_count,count);
        }else{
            count = 0;
        }
    }
    return max_count;
}

int main()
{
    vector<int> a = {1,1,0,1,1,1};
    int ans = findMaxConsecutiveOnes(a);
    cout << "Max Consecutive 1's are : " << ans << endl;
    return 0;
}