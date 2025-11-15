#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    string ans = "1";
    if(n == 1) return ans;
    for(int i = 2;i<=n;i++){
        string temp = "";
        int j=0;
        while(j<ans.size()){
            char ch = ans[j];
            int count = 0;
            while(j < ans.size() && ans[j] == ch){
                count++;
                j++;
            }
            temp += to_string(count) + ch;
        }
        ans = temp;
    }
    return ans;
}

int main() {
    vector<int> testcases = {1, 2, 3, 4, 5, 6, 10};

    for(int n : testcases){
        cout << "n = " << n << " --> " << countAndSay(n) << endl;
    }

    return 0;
}
