#include<bits/stdc++.h>
using namespace std;

string convert_to_binary(int x){
    string res = "";
    while(x!=0){
        res += to_string(x%2);
        x/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int convert_to_decimal(string val){
    int res = 0, pw = 1;
    for(int i = val.size()-1;i>=0;i--){
        if(val[i] == '1')
            res+=pw;
        pw*=2;
    }
    return res;
}

int main(){
    int x = 13;
    cout<<convert_to_binary(x)<<endl;
    string val = "110110";
    cout<<convert_to_decimal(val)<<endl;
}