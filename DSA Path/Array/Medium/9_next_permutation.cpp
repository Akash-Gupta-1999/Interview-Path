#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        int n = nums.size(), temp = -1;
        bool flag = false;
        for(int i = n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                temp = i;
                break;
            }
        }
        if(temp == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        sort(nums.begin()+temp+1,nums.end());
        for(int i = temp+1;i<n;i++){
            if(nums[i] > nums[temp]){
                swap(nums[temp],nums[i]);
                break;
            }
        }
    }

int main()
{
    vector<int> ans = {2, 1, 5, 4, 3, 0, 0};
    nextPermutation(ans);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}