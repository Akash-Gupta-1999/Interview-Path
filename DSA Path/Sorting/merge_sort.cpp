#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,int left, int mid, int right){
    vector<int> left_arr,right_arr;
    for(int i=left;i<=mid;i++)
        left_arr.push_back(arr[i]);
    for(int i=mid+1;i<=right;i++)
        right_arr.push_back(arr[i]);
    
    int i = 0, j = 0, k = left;
    while(i<left_arr.size() && j<right_arr.size()){
        if(left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            i++;
        }
        else{
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while(i<left_arr.size()){
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while(j<right_arr.size()){
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr,int i, int j){
    if(i>=j)
        return;
    int mid = i + (j-i)/2;
    merge_sort(arr,i,mid);
    merge_sort(arr,mid+1,j);
    merge(arr,i,mid,j);
}

int main(){
    vector<int> arr = {1,4,2,3,8,5,4,6,2,5,6,4,1,2,3,4,6,3};
    merge_sort(arr,0,arr.size()-1);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}