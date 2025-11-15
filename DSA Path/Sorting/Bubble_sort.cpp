#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& arr){
    int n = arr.size();
    bool swapped = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

int main(){
    vector<int> arr = {1,4,2,3,8,5,4,6,2,5,6,4,1,2,3,4,6,3};
    bubble_sort(arr);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}