// GCD/ HCF : Greatest Common Divisor/Highest Common Factor
//  n1 = 12, n2 = 16
//Factors of n1 = 1,2,3,4,6,12
//Factors of n2 = 1,2,4,8,16
//Common and greatest is 4

#include<bits/stdc++.h>
using namespace std;

int cus_gcd(int n1,int n2){
    int ans = 1;
    for(int i = min(n1,n2); i>=1;i--){
        if(n1%i == 0 && n2%i == 0){
            ans = i;
            break;
        }
    }
    return ans;
}

//O(log min(n1,n2))
//Euclidean Algorithm: gcd(a,b) = gcd(a%b,b)  if a>b

int euc(int n1,int n2){
    if(n1 == 0 || n2 == 0)
        return max(n1,n2);
    if(n1>n2)
        euc(n1%n2,n2);
    else    
        euc(n2%n1,n1);
}

int main(){
    int n1=12, n2 = 16;
    cout<<cus_gcd(n1,n2)<<endl;
    cout<<gcd(n1,n2)<<endl;
    cout<<euc(n1,n2)<<endl;
}