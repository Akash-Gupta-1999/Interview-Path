#include <bits/stdc++.h>

using namespace std;

vector <int> FindUnion(int arr1[], int arr2[], int n, int m) {
    vector<int> union_arr;
    int i=0, j=0;
    while(i<n && j<m){
        if(arr1[i] <= arr2[j]){
            if(union_arr.empty())
                union_arr.push_back(arr1[i]);
            else if(arr1[i] != union_arr.back())
                union_arr.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i] > arr2[j]){
            if(union_arr.empty())
                union_arr.push_back(arr2[j]);
            else if(arr2[j] != union_arr.back())
                union_arr.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        if(arr1[i] != union_arr.back())
            union_arr.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        if(arr2[j] != union_arr.back())
            union_arr.push_back(arr2[j]);
        j++;
    }
    return union_arr;
}

int main() {
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}