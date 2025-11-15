#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
// using iterative is best by reversing the list as it will help us in optimizing stack space
int add_rec(Node* head){
    if(head == NULL)
        return 1;
    int carry = add_rec(head->next);
    int rem = (head->data + carry)/10;
    head->data = (head->data + carry)%10;
    return rem;
}

Node *addOne(Node* head){
    int carry = add_rec(head);
    if(carry != 0){
        Node *newnode = new Node(carry);
        newnode->next = head;
        head = newnode;
    }
    return head;
}

int main() {
  
  	// Create a hard-coded linked list:
    // 1 -> 9 -> 9 -> 9
    Node *head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);

    head = addOne(head);
  
    printList(head);

    return 0;
}