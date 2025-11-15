#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head, *next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Helper function to print the list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if(values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for(int i = 1; i < values.size(); ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // Test Case: Create list 1 -> 2 -> 3 -> 4 -> 5
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    // Reverse the list
    ListNode* reversedHead = reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}
