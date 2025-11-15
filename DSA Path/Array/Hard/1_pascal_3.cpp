#include<bits/stdc++.h>
using namespace std;

vector<int> pascal_triangle(int n){
    vector<int> ans = {1};
    for(int i=1;i<n;i++){          // x, x * (n-i)/i, ....... : n is 1 indexed , and total n items
        int val = ans[i-1]*(n-i);
        val/=i;
        ans.push_back(val);
    }
    return ans;
}
// My method
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal;
    int i = 0;
    pascal.push_back({1});
    i++;
    while(i<numRows){
        pascal.push_back({1});
        if(i!=1){
            for(int k=1;k<pascal[i-1].size();k++){
                pascal[i].push_back(pascal[i-1][k-1] + pascal[i-1][k]);
            }
        }
        pascal[i].push_back(1);
        i++;
    }
    return pascal;
}

int main(){
    int n = 10;
    vector<vector<int>> ans(n);
    for(int i = 1;i<=n;i++){
        vector<int> row = pascal_triangle(i);
        ans.push_back(row);
    }
    for(auto it : ans){
        for(auto i : it)
            cout<<i<<" ";
        cout<<endl;
    }
    // My method
    ans =  generate(n);
    for(auto it : ans){
        for(auto i : it)
            cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl; 
}

// 1    0c0
// 11   1c0, 1c1
// 121  2c0,2c1,2c2
//1331
//14641