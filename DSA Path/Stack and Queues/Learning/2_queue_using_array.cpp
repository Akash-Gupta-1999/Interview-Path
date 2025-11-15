#include <bits/stdc++.h>
using namespace std;

/*
    Circular Queue Implementation (Without size variable)
    -----------------------------------------------------
    Intuition:
    - In a circular queue, front and rear wrap around using modulo (%).
    - Full condition:  (rear + 1) % capacity == front
        → means the next position of rear would overwrite front.
    - Empty condition: front == -1
        → no element in queue.
    - This design wastes 1 slot to distinguish between full and empty.
*/

class CircularQueue {
    int capacity;
    int *q;
    int front, rear;

public:
    CircularQueue(int cap) {
        capacity = cap;
        q = new int[capacity];
        front = -1;
        rear = -1;
    }

    void push(int num) {
        // Check if full
        if ((rear + 1) % capacity == front) {
            cout << "Queue is full, cannot push " << num << endl;
            return;
        }

        // First element case
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        q[rear] = num;
    }

    void pop() {
        // Empty check
        if (front == -1) {
            cout << "Queue is empty, cannot pop" << endl;
            return;
        }

        // If only one element
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    int top() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return q[front];
    }

    void print() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << q[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

// Driver Code
int main() {
    CircularQueue q(5); // can store max 4 elements (one wasted)

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50); 
    q.push(60); // This should fail (queue full)

    q.print();

    q.pop();
    q.pop();
    q.print();

    cout << "Front element = " << q.top() << endl;

    q.push(60);
    q.push(70);
    q.print();

    return 0;
}
