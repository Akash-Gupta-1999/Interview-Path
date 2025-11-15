#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> st;

    void push(int val) {
        if (!st.empty())
            st.push({val, min(val, st.top().second)});
        else
            st.push({val, val});
    }

    void pop() {
        if (!st.empty()) st.pop();
    }

    int top() {
        if (!st.empty()) return st.top().first;
        throw runtime_error("Stack is empty");
    }

    int getMin() {
        if (!st.empty()) return st.top().second;
        throw runtime_error("Stack is empty");
    }
};

int main() {
    MinStack ms;

    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << "Current Min: " << ms.getMin() << endl; // -3
    ms.pop();
    cout << "Top: " << ms.top() << endl;           // 0
    cout << "Current Min: " << ms.getMin() << endl; // -2

    ms.push(-5);
    cout << "Top: " << ms.top() << endl;           // -5
    cout << "Current Min: " << ms.getMin() << endl; // -5

    return 0;
}
