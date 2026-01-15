#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt1 = 0,cnt2=0; // count
    int el1,el2; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && v[i]!=el1) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (el1 == v[i]) cnt1++;
        else if (el2 == v[i]) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    //checking if the stored element
    // is the majority element:
    cnt1 = cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        else if(v[i]==el2) cnt2++;
    }
    vector<int> res;
    if (cnt1 > (n / 3)) res.push_back(el1);
    if (cnt2 > (n / 3)) res.push_back(el2);
    return res;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    vector<int> ans = majorityElement(arr);
    cout << "The majority element are: ";
    for(int x:ans)
        cout << x << ",";
    cout<<endl;
    return 0;
}