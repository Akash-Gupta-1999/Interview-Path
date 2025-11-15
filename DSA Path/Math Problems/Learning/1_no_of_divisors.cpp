#include<bits/stdc++.h>
using namespace std;

void divisors(int n){
    vector<int> div;
    //0(sqrt(n))
    for(int i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            div.push_back(i);
            div.push_back(n/i);
        }
    }
    //O(no.of.factors * log no.of.factors)
    sort(div.begin(),div.end());
    //O(no.of.factors)
    for(auto it : div)
        cout<<it<<" ";
    cout<<endl;
}

int main(){
    int n = 63;
    divisors(n);
}