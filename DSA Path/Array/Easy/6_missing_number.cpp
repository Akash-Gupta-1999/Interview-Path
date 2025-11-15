#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {

    //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}

int xor_missingNumber(vector<int>&a, int N){
    int xor1=a[0], xor2=0;
    for(int i=1;i<a.size();i++)
        xor1^=a[i];
    for(int i = 1;i<=N;i++){
        xor2^=i;
    }
    return xor1^xor2;
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    int xor_ans = xor_missingNumber(a, N);
    cout << "The missing number is: " << xor_ans << endl;
    return 0;
}