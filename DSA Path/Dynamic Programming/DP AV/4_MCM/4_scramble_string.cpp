#include<bits/stdc++.h>
using namespace std;

bool isscramble(string s1,string s2,unordered_map<string,bool> mp){
    if(s1.size()!=s2.size())
        return false;
    int n = s1.size();
    if(n == 0)
        return true;
    if(s1 == s2)
        return true;
    string c_s1 = s1;
    string c_s2 = s2;
    sort(c_s1.begin(),c_s1.end());
    sort(c_s2.begin(),c_s2.end());
    if(c_s1!=c_s2)
        return false;
    string key = s1 + " " + s2;
    if(mp.find(key)!=mp.end())
        return mp[key];
    for(int i = 1;i<n;i++){
        if((isscramble(s1.substr(0,i),s2.substr(0,i),mp) && isscramble(s1.substr(i,n-i),s2.substr(i,n-i),mp))){
            mp[key] = true;
            return mp[key];
        }
        if(isscramble(s1.substr(0,i),s2.substr(n-i,i),mp) && isscramble(s1.substr(i,n-i),s2.substr(0,n-i),mp)){
            mp[key] = true;
            return mp[key];
        }
    }
    mp[key] = false;
    return mp[key];
}

int main(){
    string s1 = "great",s2 = "ergat";
    unordered_map<string,bool> mp;
    cout<<boolalpha<<isscramble(s1,s2,mp);
}