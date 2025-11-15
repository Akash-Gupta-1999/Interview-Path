#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Efficient middle node function (Tortoise and Hare)
ListNode* middleNode(ListNode* head) {
    ListNode *hare = head, *tort = head;
    while (hare != nullptr && hare->next != nullptr) {
        hare = hare->next->next;
        tort = tort->next;
    }
    return tort;
}

// Helper function to create a linked list from an array
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

// Helper function to print a linked list from a given node
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test case 1: Odd number of elements
    vector<int> vals1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(vals1);
    cout << "Original List 1: ";
    printList(head1);
    ListNode* mid1 = middleNode(head1);
    cout << "Middle node from List 1: ";
    printList(mid1); // Expected: 3 4 5

    // Test case 2: Even number of elements
    vector<int> vals2 = {10, 20, 30, 40, 50, 60};
    ListNode* head2 = createList(vals2);
    cout << "\nOriginal List 2: ";
    printList(head2);
    ListNode* mid2 = middleNode(head2);
    cout << "Middle node from List 2: ";
    printList(mid2); // Expected: 40 50 60

    // Test case 3: Single element
    vector<int> vals3 = {99};
    ListNode* head3 = createList(vals3);
    cout << "\nOriginal List 3: ";
    printList(head3);
    ListNode* mid3 = middleNode(head3);
    cout << "Middle node from List 3: ";
    printList(mid3); // Expected: 99

    // Clean-up memory (optional in short programs, but good practice)
    // You can add functions to delete lists if needed
    return 0;
}
