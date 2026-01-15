#include<bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& arr, int left, int right){
    if(left>=right)
        return;
    int pivot = arr[right];
    int swap_pos=left;
    for(int i=left;i<right;i++){
        if(arr[i] < pivot){
            swap(arr[i],arr[swap_pos]);
            swap_pos++;
        }
    }
    swap(arr[right],arr[swap_pos]);
    quick_sort(arr,left,swap_pos-1);
    quick_sort(arr,swap_pos+1,right);
}

int main(){
    vector<int> arr = {1,4,2,3,8,5,4,6,2,5,6,4,1,2,3,4,6,3};
    quick_sort(arr,0,arr.size()-1);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}