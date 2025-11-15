#include <bits/stdc++.h>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to delete the middle node of a linked list
ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Remove the middle node
    prev->next = slow->next;
    delete slow; // free memory
    return head;
}

// Helper to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Helper to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper to free memory
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test case 1: Odd-length list
    vector<int> vals1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(vals1);
    cout << "Original List 1: ";
    printList(head1);
    head1 = deleteMiddle(head1);
    cout << "After deleting middle: ";
    printList(head1);
    freeList(head1);

    // Test case 2: Even-length list
    vector<int> vals2 = {10, 20, 30, 40};
    ListNode* head2 = createList(vals2);
    cout << "\nOriginal List 2: ";
    printList(head2);
    head2 = deleteMiddle(head2);
    cout << "After deleting middle: ";
    printList(head2);
    freeList(head2);

    // Test case 3: Single node
    vector<int> vals3 = {99};
    ListNode* head3 = createList(vals3);
    cout << "\nOriginal List 3: ";
    printList(head3);
    head3 = deleteMiddle(head3);
    cout << "After deleting middle: ";
    printList(head3);
    freeList(head3);

    // Test case 4: Two nodes
    vector<int> vals4 = {1, 2};
    ListNode* head4 = createList(vals4);
    cout << "\nOriginal List 4: ";
    printList(head4);
    head4 = deleteMiddle(head4);
    cout << "After deleting middle: ";
    printList(head4);
    freeList(head4);

    return 0;
}
