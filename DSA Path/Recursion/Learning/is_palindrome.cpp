#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string s,int i,int n){
    if(i>n-1)
        return true;
    if(s[i] == s[n-1])
        return is_palindrome(s,++i,--n);
    return false;
}

int main(){
    string s = "abbba";
    cout<<is_palindrome(s,0,s.size())<<endl;
}