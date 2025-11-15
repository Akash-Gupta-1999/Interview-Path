#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Recursive function to reverse the linked list
ListNode* rev_rec(ListNode* prev, ListNode* curr) {
    if (curr == NULL)
        return prev;
    ListNode* next = curr->next;
    curr->next = prev;
    return rev_rec(curr, next);
}

// Wrapper function
ListNode* reverseList(ListNode* head) {
    return rev_rec(NULL, head);
}

// Helper to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // Test case: create list 10 -> 20 -> 30 -> 40
    vector<int> vals = {10, 20, 30, 40};
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    // Reverse using recursion
    ListNode* reversedHead = reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}
