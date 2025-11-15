#include<bits/stdc++.h>
using namespace std;


//ceil = lower bound
int lower_bound(vector<int>& nums,int left,int right, int target){
   if(left>right)
        return nums.size();
    int mid = left + (right-left)/2;
    if(nums[mid] >= target)
        return min(mid,lower_bound(nums,left,mid-1,target));
    else
        return lower_bound(nums,mid+1,right,target);
}

//floor
int floor(vector<int>& nums,int left,int right, int target){
   if(left>right)
        return -1;
    int mid = left + (right-left)/2;
    if(nums[mid] <= target)
        return max(mid,floor(nums,mid+1,right,target));
    else
        return floor(nums,left,mid-1,target);
}

int main(){
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int target = 5;

    int floor_idx = floor(arr, 0, arr.size() - 1, target);
    int ceil_idx = lower_bound(arr, 0, arr.size() - 1, target);

    if (floor_idx != -1)
        cout << "Floor of the Element is " << arr[floor_idx] << endl;
    else
        cout << "No Floor exists for " << target << endl;

    if (ceil_idx != arr.size())
        cout << "Ceil of the Element is " << arr[ceil_idx] << endl;
    else
        cout << "No Ceil exists for " << target << endl;
}