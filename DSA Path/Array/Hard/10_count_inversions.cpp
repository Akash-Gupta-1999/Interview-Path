#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& a, int left,int mid, int right){
    vector<int> left_arr,right_arr;
    int count = 0;
    for(int i=left;i<=mid;i++)
        left_arr.push_back(a[i]);
    for(int i=mid+1;i<=right;i++)
        right_arr.push_back(a[i]);
    int i = 0, j = 0, k = left;
    while(i<left_arr.size() && j<right_arr.size()){
        if(left_arr[i] > right_arr[j]){
            count += left_arr.size() - i;
            a[k] = right_arr[j];
            j++;
        }else{
            a[k] = left_arr[i];
            i++;
        }
        k++;
    }
    while(i<left_arr.size()){
        a[k] = left_arr[i];
        i++;
        k++;
    }
    while(j<right_arr.size()){
        a[k] = right_arr[j];
        j++;
        k++;
    }
    return count;
}

int mergesort(vector<int>& a, int left, int right){
    if(left>=right)
        return 0;
    int mid = left + (right-left)/2;
    int count = 0;
    count += mergesort(a,left,mid);
    count += mergesort(a,mid+1,right);
    count += merge(a,left,mid,right);
    return count;
}

int numberOfInversions(vector<int>& a, int n){
    return mergesort(a,0,n-1);
}

int main(){
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}