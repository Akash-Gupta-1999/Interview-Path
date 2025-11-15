#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int>& arr, int exp){
    vector<int> count(10,0),output(arr.size(),0);
    for(int i=0;i<arr.size();i++)
        count[(arr[i]/exp)%10]++;
    for(int i = 1;i<10;i++)
        count[i]+=count[i-1];
    for(int i=arr.size()-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    arr = output;
}

void radix_sort(vector<int>& arr){
    int large = *max_element(arr.begin(),arr.end());
    for(int exp = 1;large/exp > 0;exp*=10){
        count_sort(arr,exp);
    }
}

int main(){
    vector<int> arr = {802, 2, 24, 45, 66, 170, 75, 90};
    radix_sort(arr);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}