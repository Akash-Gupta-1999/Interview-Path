#include<bits/stdc++.h>
using namespace std;

int upper_bound(vector<int>& nums,int left,int right, int target){
   if(left>right)
        return nums.size();
    int mid = left + (right-left)/2;
    if(nums[mid] > target)
        return min(mid,upper_bound(nums,left,mid-1,target));
    else
        return upper_bound(nums,mid+1,right,target);
}

//iterative approach

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,2,3};
    int target = 2;
    cout<<"Idx of the Element is "<<upper_bound(arr,0,arr.size()-1,target)<<endl;
}