#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int num;
    node* next;
    node(int num) {
        this->num = num;
        this->next = NULL;
    }
};

class Stack {
    node* head = NULL;
    int size = 0;

public:
    void push(int num) {
        node* newnode = new node(num);
        newnode->next = head;
        head = newnode;
        size++;
    }

    void pop() {
        if (head == NULL) {
            cout << "No element to pop\n";
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;    // ✅ free memory
        size--;
    }

    int top() {
        if (head == NULL) {
            cout << "Stack is empty\n";
            return -1; // or throw
        }
        return head->num;
    }

    void print() {
        node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->num << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    int getSize() { return size; }
    bool empty() { return head == NULL; }
};

int main() {
    Stack s1;
    s1.pop();
    s1.push(4);
    s1.push(100);
    s1.push(1003);
    s1.push(-45);
    s1.print();  // -45 1003 100 4
    s1.pop();
    s1.print();  // 1003 100 4
    cout << "Top: " << s1.top() << endl;
    cout << "Size: " << s1.getSize() << endl;
}
