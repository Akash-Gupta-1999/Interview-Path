#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int min_element_idx = i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[min_element_idx])
                min_element_idx = j;
        }
        swap(arr[i],arr[min_element_idx]);       
    }
}

int main(){
    vector<int> arr = {1,4,2,3,8,5,4,6,2,5,6,4,1,2,3,4,6,3};
    selection_sort(arr);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}