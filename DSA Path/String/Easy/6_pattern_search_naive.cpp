#include<bits/stdc++.h>
using namespace std;

vector<int> search(string pat, string txt){
    vector<int> ans;
    int m = txt.size(), n = pat.size();
    for(int i=0;i<=m-n;i++){
        int j = 0;
        while(j<n && txt[i+j] == pat[j])
            j++;
        if(j == n)
            ans.push_back(i);
    }
    return ans;
}

int main() {
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = search(pat, txt);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}