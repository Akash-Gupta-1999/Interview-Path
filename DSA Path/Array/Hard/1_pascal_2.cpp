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

int main(){
    int n = 10;
    vector<int> ans = pascal_triangle(n);
    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl; 
}

// 1    0c0
// 11   1c0, 1c1
// 121  2c0,2c1,2c2
//1331
//14641