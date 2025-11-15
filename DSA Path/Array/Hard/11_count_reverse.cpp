#include<bits/stdc++.h>
using namespace std;

int countreverse(vector<int>& left, vector<int>& right){
    int count = 0, i = 0, j = 0;
    while(i<left.size() && j<right.size()){
        if((long long)left[i] > 2LL * right[j]){
            count += left.size() - i;
            j++;
        }else 
            i++;
    }
    return count;
}

int merge(vector<int>& nums, int left,int mid, int right){
    vector<int> left_arr,right_arr;
    int count = 0;
    for(int i=left;i<=mid;i++)
        left_arr.push_back(nums[i]);
    for(int i=mid+1;i<=right;i++)
        right_arr.push_back(nums[i]);
    count = countreverse(left_arr,right_arr);
    int i=0,j=0,k=left;
    while(i<left_arr.size() && j<right_arr.size()){
        if(left_arr[i] <= right_arr[j]){
            nums[k] = left_arr[i];
            i++;
        }else{
            nums[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while(i<left_arr.size()){
        nums[k] = left_arr[i];
        i++;
        k++;
    }
    while(j<right_arr.size()){
        nums[k] = right_arr[j];
        j++;
        k++;
    }
    return count;
}

int mergesort(vector<int>& nums, int left, int right){
    if(left>=right) return 0;
    int mid = left + (right-left)/2;
    int count = mergesort(nums,left,mid);
    count += mergesort(nums,mid+1,right);
    count += merge(nums,left,mid,right);
    return count;
}

int reversePairs(vector<int>& nums) {
    return mergesort(nums,0,nums.size()-1);
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = reversePairs(a);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}