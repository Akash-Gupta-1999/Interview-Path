#include<bits/stdc++.h>
using namespace std;

class RobinKarp{
    int base = 31;
    int mod = 1e9 + 7;
    vector<int> hash;
    vector<int> power;

    int add(int a, int b){
        a +=b;
        if(a>=mod)
            a -=mod;
        return a;
    }

    int sub(int a, int b){
        a -=b;
        if(a<0)
            a +=mod;
        return a;
    }

    int mul(int a,int b){
        return (int)(((1LL) * a * b)%mod);
    }

    int chartoint(char ch){
        return ch - 'a' + 1; 
    }

    public:
        RobinKarp(string& s){
            int n = s.size();
            hash.resize(n);
            power.resize(n);
            hash[0] = chartoint(s[0]);
            power[0] = 1;
            for(int i=1;i<n;i++){
                hash[i] = add(mul(hash[i-1],base),chartoint(s[i]));
                power[i] = mul(base,power[i-1]);
            }
        }

        int getsubhash(int l, int r){
            int h = hash[r];
            if(l>0){
                h = sub(h,mul(hash[l-1],power[r-l+1]));
            }
            return h;
        }
};


vector<int> search(string pat, string txt){
    RobinKarp pathash(pat);
    RobinKarp txthash(txt);
    vector<int> ans;
    int m = pat.size(), n = txt.size();
    int h = pathash.getsubhash(0,m-1);
    for(int i=0;i<=n-m;i++){
        int txt_subhash = txthash.getsubhash(i,i+m-1);
        if(h == txt_subhash)
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