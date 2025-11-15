#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = -200, y = 77;
    x = x^y;
    y = x^y;
    x = x^y;
    cout<<x<<" "<<y<<endl;
}