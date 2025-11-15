#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to remove the nth node from the end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, *slow = head;
    for (int i = 0; i <= n; i++) {
        if (fast == NULL) return head->next;
        fast = fast->next;
    }
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from array
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to delete linked list memory
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test case 1: Remove 2nd from end from [1,2,3,4,5]
    vector<int> vals1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(vals1);
    cout << "Original list: ";
    printList(head1);
    head1 = removeNthFromEnd(head1, 2);
    cout << "After removing 2nd from end: ";
    printList(head1);
    freeList(head1);

    // Test case 2: Remove 1st from end from [1]
    vector<int> vals2 = {1};
    ListNode* head2 = createList(vals2);
    cout << "\nOriginal list: ";
    printList(head2);
    head2 = removeNthFromEnd(head2, 1);
    cout << "After removing 1st from end: ";
    printList(head2);
    freeList(head2);

    // Test case 3: Remove 3rd from end from [1,2,3,4,5]
    vector<int> vals3 = {1, 2, 3, 4, 5};
    ListNode* head3 = createList(vals3);
    cout << "\nOriginal list: ";
    printList(head3);
    head3 = removeNthFromEnd(head3, 5);
    cout << "After removing 5th (head) from end: ";
    printList(head3);
    freeList(head3);

    return 0;
}
