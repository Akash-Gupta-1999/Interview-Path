#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        // Pop all smaller or equal prices and accumulate their spans
        while(!st.empty() && price >= st.top().first){
            span += st.top().second;
            st.pop();
        }
        // Push current price with its span
        st.push({price, span});
        return span;
    }
};

int main() {
    // Testcase 1
    vector<int> prices1 = {100, 80, 60, 70, 60, 75, 85};
    StockSpanner sp1;
    cout << "Test 1 -> Prices: ";
    for(int p : prices1) cout << p << " ";
    cout << "\nOutput spans: ";
    for(int p : prices1) cout << sp1.next(p) << " ";
    cout << "\n\n";

    // Testcase 2: strictly increasing prices
    vector<int> prices2 = {10, 20, 30, 40, 50};
    StockSpanner sp2;
    cout << "Test 2 -> Prices: ";
    for(int p : prices2) cout << p << " ";
    cout << "\nOutput spans: ";
    for(int p : prices2) cout << sp2.next(p) << " ";
    cout << "\n\n";

    // Testcase 3: strictly decreasing prices
    vector<int> prices3 = {50, 40, 30, 20, 10};
    StockSpanner sp3;
    cout << "Test 3 -> Prices: ";
    for(int p : prices3) cout << p << " ";
    cout << "\nOutput spans: ";
    for(int p : prices3) cout << sp3.next(p) << " ";
    cout << "\n\n";

    // Testcase 4: all same prices
    vector<int> prices4 = {100, 100, 100, 100};
    StockSpanner sp4;
    cout << "Test 4 -> Prices: ";
    for(int p : prices4) cout << p << " ";
    cout << "\nOutput spans: ";
    for(int p : prices4) cout << sp4.next(p) << " ";
    cout << "\n\n";

    return 0;
}
