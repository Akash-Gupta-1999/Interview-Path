#include<bits/stdc++.h>
using namespace std;

void bucket_sort(vector<float>& arr){
    vector<vector<float>> buckets(10);
    for(int i=0;i<arr.size();i++){
        int num = arr[i]*10;
        buckets[num].push_back(arr[i]);
    }
    for(int i=0;i<10;i++)
        sort(buckets[i].begin(),buckets[i].end());
    int i = 0;
    for(auto it : buckets){
        for(float num : it){
            arr[i] = num;
            i++;
        }
    }
}

int main(){
    vector<float> arr = {0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94};
    bucket_sort(arr);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}