#include<bits/stdc++.h>
using namespace std;

void is_prime(int n){
    int cnt=0;
    //0(sqrt(n))
    for(int i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            cnt+=2;
        }
    }
    if(cnt>2)
        cout<<"Its not prime"<<endl;
    else    
        cout<<"It is a prime"<<endl;
}

int main(){
    int n = 13;
    is_prime(n);
}