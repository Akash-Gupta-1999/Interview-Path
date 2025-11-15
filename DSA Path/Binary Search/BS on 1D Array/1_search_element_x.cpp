#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& nums,int left,int right, int target){
    if(left>right)
        return -1;
    int mid = left + (right-left)/2;
    if(nums[mid] == target)
        return mid;
    else if(nums[mid] < target)
        return binary_search(nums,mid+1,right,target);
    return binary_search(nums,left,mid-1,target); 
}

int main(){
    vector<int> arr = {-1,0,3,5,9,12};
    int target = 9;
    cout<<"Idx of the Element is "<<binary_search(arr,0,arr.size()-1,target)<<endl;
}