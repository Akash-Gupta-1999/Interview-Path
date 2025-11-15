#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode* prev = tail->next;
    ListNode* curr = head;
    ListNode* next = NULL;

    while (prev != tail) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return tail; // new head after reversal
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1 || !head || !head->next)
        return head;

    ListNode* headptr = head;
    ListNode* tailptr = head;
    ListNode* dummynode = new ListNode();
    dummynode->next = head;
    ListNode* prevend = dummynode;

    int count = 1;
    while (tailptr) {
        if (count == k) {
            ListNode* nextstart = tailptr->next;
            reverse(headptr, tailptr);
            prevend->next = tailptr;
            prevend = headptr;
            headptr = tailptr = nextstart;
            count = 1;
        } else {
            count++;
            tailptr = tailptr->next;
        }
    }
    prevend->next = headptr;
    return dummynode->next;
}

// Utility to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (size_t i = 1; i < vals.size(); i++) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

// Utility to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Test case 1
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    cout << "Original: ";
    printList(head1);
    head1 = reverseKGroup(head1, 2);
    cout << "Reversed in groups of 2: ";
    printList(head1);

    // Test case 2
    ListNode* head2 = createList({1, 2, 3, 4, 5});
    cout << "\nOriginal: ";
    printList(head2);
    head2 = reverseKGroup(head2, 3);
    cout << "Reversed in groups of 3: ";
    printList(head2);

    // Test case 3 - k > length of list
    ListNode* head3 = createList({1, 2});
    cout << "\nOriginal: ";
    printList(head3);
    head3 = reverseKGroup(head3, 5);
    cout << "Reversed in groups of 5 (unchanged): ";
    printList(head3);

    // Test case 4 - k = 1 (unchanged)
    ListNode* head4 = createList({1, 2, 3});
    cout << "\nOriginal: ";
    printList(head4);
    head4 = reverseKGroup(head4, 1);
    cout << "Reversed in groups of 1 (unchanged): ";
    printList(head4);

    return 0;
}
