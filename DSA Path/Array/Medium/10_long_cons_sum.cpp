#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if(n == 0)
        return 0;
    unordered_set<int> st;
    for(int i=0;i<n;i++)
        st.insert(a[i]);
    int count, max_count = 1;
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            count = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x++;
                count++;
                max_count = max(max_count, count);
            }
        }
    }
    return max_count;
}

int main()
{
    vector<int> a = {5, 100, 200, 1, 3, 2, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}