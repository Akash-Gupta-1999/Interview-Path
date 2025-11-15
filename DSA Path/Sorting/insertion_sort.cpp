#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j]; //no swapping as then it will become bubble sort
            j--;
        }
        arr[j+1] = key; //inserting key at right place
    }
}

int main(){
    vector<int> arr = {1,4,2,3,8,5,4,6,2,5,6,4,1,2,3,4,6,3};
    insertion_sort(arr);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}