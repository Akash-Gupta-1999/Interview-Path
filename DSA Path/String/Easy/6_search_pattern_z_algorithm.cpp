#include<bits/stdc++.h>
using namespace std;

vector<int> z_algo(string& pat){
    int n = pat.size();
    vector<int>z(n,0);
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && pat[r] == pat[r-l])
                r++;
            z[i] = r-l;
            r--;
        }else{
            if(z[i-l] < r-i+1)
                z[i] = z[i-l];
            else{
                l = i;
                while(r<n && pat[r] == pat[r-l])
                    r++;
                z[i] = r-l;
                r--;
            }
        }
    }
    return z; 
}

vector<int> search(string pat, string txt){
    string str = pat + '$' + txt;
    vector<int> z = z_algo(str);
    vector<int> ans;
    for(int i = pat.size()+1;i<str.size();i++){
        if(z[i] == pat.size())
            ans.push_back(i-pat.size()-1);
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