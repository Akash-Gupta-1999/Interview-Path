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

class Queue {
    node* head = NULL;
    node* tail = NULL;
    int size = 0;

public:
    void push(int num) {
        node* newnode = new node(num);
        if (!head) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }

    void pop() {
        if (!head) {
            cout << "Invalid: nothing in queue\n";
            return;
        }
        node* temp = head;
        head = head->next;
        if (head == NULL) // queue became empty
            tail = NULL;
        delete temp;
        size--;
    }

    int top() {
        if (!head) {
            cout << "Queue is empty\n";
            return -1;
        }
        return head->num;
    }

    void print() {
        node* ptr = head;
        while (ptr) {
            cout << ptr->num << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    int getSize() { return size; }
    bool empty() { return size == 0; }

    ~Queue() {
        while (head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Queue q1;
    q1.pop();  // nothing to pop
    q1.push(4);
    q1.push(100);
    q1.push(1003);
    q1.push(-45);
    q1.print();   // 4 100 1003 -45
    q1.pop();
    q1.print();   // 100 1003 -45
    cout << "Front: " << q1.top() << endl;  // 100
    cout << "Size: " << q1.getSize() << endl; // 3
}
