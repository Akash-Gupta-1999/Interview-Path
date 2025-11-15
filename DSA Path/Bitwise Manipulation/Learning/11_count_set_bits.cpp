#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 11, count = 0;
    while(x){
        count++;
        x = x&(x-1);
    }
    cout<<count<<endl;
    // Method 2
    x = 11, count = 0;
    while(x>0){
        count+=x&1; 
        x = x >> 1;
    }
    cout<<count<<endl;
}