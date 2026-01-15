#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr,int i, int n){
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    if(left_child<n && arr[largest] < arr[left_child])
        largest = left_child;
    if(right_child<n && arr[largest] < arr[right_child])
        largest = right_child;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n); // recursively call again to heapify the subtree to make a max heap again
    }
}

void heap_sort(vector<int>& arr){
    int n = arr.size();
    for(int i = n/2 - 1;i>=0;i--)
        heapify(arr,i,n);
    for(int i = n-1;i>=0;i--){  // not to call heap_sort again as tree is already heapify, just heapify the subtree recursively
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
}

int main(){
    vector<int> arr = {1,4,2,3,8,5,4,6,2,5,6,4,1,2,3,4,6,3};
    heap_sort(arr);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}