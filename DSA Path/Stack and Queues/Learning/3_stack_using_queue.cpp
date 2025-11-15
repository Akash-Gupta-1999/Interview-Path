#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {}

    void push(int x) {
        int s = q.size();
        q.push(x);
        // rotate: move all old elements behind the new one
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

// Driver code with test cases
int main() {
    MyStack st;

    cout << "Pushing elements: 5, 10, 15\n";
    st.push(5);
    st.push(10);
    st.push(15);

    cout << "Top element = " << st.top() << endl; // 15

    cout << "Popped = " << st.pop() << endl; // 15
    cout << "Top element = " << st.top() << endl; // 10

    cout << "Popped = " << st.pop() << endl; // 10
    cout << "Popped = " << st.pop() << endl; // 5

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // Yes

    cout << "Trying pop on empty stack: " << st.pop() << endl;

    return 0;
}
