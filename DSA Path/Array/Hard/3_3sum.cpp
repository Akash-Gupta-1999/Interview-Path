#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> arr){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i+1, k = arr.size()-1;
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum > 0)
                k--;
            else if(sum < 0)
                j++;
            else{
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
                while(j<k && arr[j-1] == arr[j]) j++;
                while(j<k && arr[k+1] == arr[k]) k--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = triplets(arr);
    for(auto it : ans){
        for(auto it1 : it)
            cout<<it1<<" ";
        cout<<endl;
    }
}