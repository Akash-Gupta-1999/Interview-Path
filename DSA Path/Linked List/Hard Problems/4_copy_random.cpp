#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(NULL), random(NULL) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    // Step 1: Clone nodes and insert after each original node
    Node* temp = head;
    while (temp != NULL) {
        Node* newnode = new Node(temp->val);
        newnode->next = temp->next;
        temp->next = newnode;
        temp = newnode->next;
    }

    // Step 2: Set random pointers for cloned nodes
    temp = head;
    while (temp != NULL) {
        Node* newptr = temp->next;
        if (temp->random != NULL)
            newptr->random = temp->random->next;
        else
            newptr->random = NULL;
        temp = newptr->next;
    }

    // Step 3: Separate the original and cloned lists
    Node* newhead = NULL;
    temp = head;
    while (temp != NULL) {
        Node* newptr = temp->next;
        if (temp == head)
            newhead = newptr;
        temp->next = newptr->next;
        temp = temp->next;
        if (temp != NULL)
            newptr->next = temp->next;
    }

    return newhead;
}

// Helper to print list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Val: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << "\n";
        temp = temp->next;
    }
    cout << "---------------------\n";
}

int main() {
    // Create example list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Set random pointers
    head->random = head->next->next; // 1 -> 3
    head->next->random = head;       // 2 -> 1
    head->next->next->random = head->next; // 3 -> 2

    cout << "Original List:\n";
    printList(head);

    Node* cloned = copyRandomList(head);

    cout << "Cloned List:\n";
    printList(cloned);

    // Extra Test Case: Single node with self-random
    Node* single = new Node(10);
    single->random = single;
    cout << "Single Node Original:\n";
    printList(single);

    Node* clonedSingle = copyRandomList(single);
    cout << "Single Node Cloned:\n";
    printList(clonedSingle);

    // Edge case: Empty list
    Node* empty = NULL;
    Node* clonedEmpty = copyRandomList(empty);
    if (!clonedEmpty) cout << "Empty list cloned successfully as NULL\n";

    return 0;
}
