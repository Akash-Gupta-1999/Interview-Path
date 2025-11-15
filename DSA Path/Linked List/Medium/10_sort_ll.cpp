#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

// Merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    // Create a dummy node to serve
    // as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (left && right) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (left->val <= right->val) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (left) {
        temp->next = left;
    } else {
        temp->next = right;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}

Node* findmiddle(Node* head){
    Node *fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        if(fast != NULL)
            slow = slow->next;
    }
    return slow;
}

// Merge sort on linked list
Node* mergesort(Node* head) {
    if (!head || !head->next) 
        return head;
    Node* middle = findmiddle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = NULL;
    left = mergesort(left);
    right = mergesort(right);
    return merge(left, right);
}

// Sort linked list
Node* sortList(Node* head) {
    return mergesort(head);
}

// Utility function to print list
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility to create list from vector
Node* createList(const vector<int>& values) {
    if (values.empty()) return NULL;
    Node* head = new Node(values[0]);
    Node* curr = head;
    for (size_t i = 1; i < values.size(); i++) {
        curr->next = new Node(values[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    vector<int> vals = {4, 2, 1, 3};
    Node* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
