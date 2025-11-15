#include<bits/stdc++.h>
using namespace std;

vector<int> construct_lps(string pat,int n){
    vector<int> lps(n);
    int len = 0, i = 1;
    lps[0] = 0;
    while(i<n){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else if(len == 0){
            lps[i] = 0;
            i++;
        }else   
            len = lps[len-1];
    }
    return lps;
}

vector<int> kmp(string pat, string txt){
    vector<int> ans;
    int m = txt.size(), n = pat.size(), i=0,j = 0;
    vector<int> lps = construct_lps(pat,n);
    while(i<m){
        if(txt[i] == pat[j]){
            i++;
            j++;
            if(j == n){
                ans.push_back(i-j);
                j = lps[j-1];
            }
        }else{
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return ans;
}

int main() {
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = kmp(pat, txt);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}