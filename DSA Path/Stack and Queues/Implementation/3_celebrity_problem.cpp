#include <bits/stdc++.h>
using namespace std;

int celebrity(const vector<vector<int>>& M) {
    int n = M.size();
    int top = 0, bottom = n-1;
    int cand = 0;
    while(top<bottom){
        if(M[top][bottom] == 1)
            top++;
        else if(M[bottom][top] == 1)
            bottom--;
        else{
            top++;
            bottom--;
        }
    }
    if(top>bottom)
        return -1;
    cand = top;
    for(int i=0;i<n;i++){
        if(i==cand)
            continue;
        if(M[i][cand] != 1 || M[cand][i] == 1)
            return -1;
    }
    return cand;
}

int main() {
    vector<vector<int>> M1 = {
        {0,1,1},
        {0,0,0},
        {0,1,0}
    };
    cout << "Test1: " << celebrity(M1) << "\n"; // expected 1

    vector<vector<int>> M2 = {
        {0,1,0},
        {0,0,1},
        {1,0,0}
    };
    cout << "Test2: " << celebrity(M2) << "\n"; // expected -1

    vector<vector<int>> M3 = {
        {0}
    };
    cout << "Test3: " << celebrity(M3) << "\n"; // expected 0

    vector<vector<int>> M4 = {
        {0,0,1,0},
        {1,0,1,1},
        {0,0,0,0},
        {1,1,1,0}
    };
    cout << "Test4: " << celebrity(M4) << "\n"; // expected 2

    return 0;
}
