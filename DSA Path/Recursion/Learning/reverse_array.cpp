#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>& arr,int i,int n){
    if(i>n-1)
        return;
    swap(arr[i],arr[n-1]);
    reverse(arr,++i,--n);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    reverse(arr,0,arr.size());
    for(auto it:arr)
        cout<<it<<" ";
    cout<<endl;
}