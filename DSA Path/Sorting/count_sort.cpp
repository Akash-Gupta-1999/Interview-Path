#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int>& arr){
    int n1 = *max_element(arr.begin(),arr.end());
    vector<int> count(n1+1,0),output(arr.size(),0);
    for(int i=0;i<arr.size();i++)
        count[arr[i]]++;
    for(int i = 1;i<=n1;i++)
        count[i]+=count[i-1];
    for(int i=arr.size()-1;i>=0;i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    arr = output;
}

int main(){
    vector<int> arr = {1,4,2,3,8,5,4,6,2,5,6,4,1,2,3,4,6,3};
    count_sort(arr);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}