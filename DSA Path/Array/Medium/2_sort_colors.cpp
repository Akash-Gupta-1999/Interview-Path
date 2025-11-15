#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        int ptr_z = 0, ptr_tw = nums.size()-1, i = 0;
        while(i<=ptr_tw){
            if(nums[i] == 0){
                swap(nums[i],nums[ptr_z]);
                ptr_z++;
                i++;
            }
            else if(nums[i] == 2){
                swap(nums[i],nums[ptr_tw]);
                ptr_tw--;
            }
            else
                i++;
        }
    }

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortColors(arr);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
