#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to insert at the end of the linked list
void insertAtTail(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new Node(val);
}

// Segregate 0s, 1s, and 2s in the linked list
Node* segregate(Node* head) {
    Node *dummynode_0 = new Node(-1), *temp_0 = dummynode_0;
    Node *dummynode_1 = new Node(-1), *temp_1 = dummynode_1;
    Node *dummynode_2 = new Node(-1), *temp_2 = dummynode_2;
    
    while(head != NULL) {
        if(head->val == 0) {
            temp_0->next = head;
            temp_0 = temp_0->next;
        } else if(head->val == 1) {
            temp_1->next = head;
            temp_1 = temp_1->next;
        } else {
            temp_2->next = head;
            temp_2 = temp_2->next;
        }
        head = head->next;
    }

    // Connect all sublists
    temp_0->next = dummynode_1->next ? dummynode_1->next : dummynode_2->next;
    temp_1->next = dummynode_2->next;
    temp_2->next = NULL;

    return dummynode_0->next;
}

// Main function with test case
int main() {
    Node* head = NULL;

    // Example input: 1 -> 2 -> 0 -> 1 -> 2 -> 0 -> 1
    int values[] = {1, 2, 0, 1, 2, 0, 1};
    for (int val : values)
        insertAtTail(head, val);

    cout << "Original List: ";
    printList(head);

    head = segregate(head);

    cout << "Segregated List: ";
    printList(head);

    return 0;
}
