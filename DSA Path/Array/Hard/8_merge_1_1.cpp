#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr1, vector<int>& arr2, int n, int m){
    int i = n-1, j = 0;
    while(i>=0 && j<m && arr1[i] > arr2[j]){
        swap(arr1[i],arr2[j]);
        i--;
        j++;
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

int main(){
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}