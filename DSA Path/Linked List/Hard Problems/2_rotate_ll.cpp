#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

// Rotates the list to the right by k places
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Find length and tail
    int length = 1;
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
        length++;
    }
    ListNode* tail = temp;

    // Effective rotations
    k %= length;
    if (k == 0) return head;

    // Find new tail: (length - k - 1) steps from head
    temp = head;
    for (int i = 0; i < length - k - 1; i++) {
        temp = temp->next;
    }

    // New head
    ListNode* newHead = temp->next;
    temp->next = NULL;
    tail->next = head;

    return newHead;
}

// Utility: Create list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Utility: Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Test case 1: Normal case
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    cout << "Original: ";
    printList(head1);
    head1 = rotateRight(head1, 2);
    cout << "Rotate by 2: ";
    printList(head1);

    // Test case 2: k > length
    ListNode* head2 = createList({1, 2, 3});
    cout << "\nOriginal: ";
    printList(head2);
    head2 = rotateRight(head2, 5);
    cout << "Rotate by 5: ";
    printList(head2);

    // Test case 3: k = 0
    ListNode* head3 = createList({10, 20, 30});
    cout << "\nOriginal: ";
    printList(head3);
    head3 = rotateRight(head3, 0);
    cout << "Rotate by 0: ";
    printList(head3);

    // Test case 4: Single element
    ListNode* head4 = createList({42});
    cout << "\nOriginal: ";
    printList(head4);
    head4 = rotateRight(head4, 3);
    cout << "Rotate by 3: ";
    printList(head4);

    // Test case 5: Empty list
    ListNode* head5 = createList({});
    cout << "\nOriginal: (empty)\n";
    head5 = rotateRight(head5, 4);
    cout << "Rotate by 4: ";
    printList(head5);

    return 0;
}
