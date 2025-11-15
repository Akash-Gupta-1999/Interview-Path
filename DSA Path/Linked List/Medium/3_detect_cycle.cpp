#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to detect cycle using Floyd’s Cycle Detection
bool hasCycle(ListNode *head) {
    ListNode *hare = head, *tort = head;
    while (hare != NULL && hare->next != NULL) {
        hare = hare->next->next;
        tort = tort->next;
        if (hare == tort)
            return true;
    }
    return false;
}

// Helper function to print if cycle exists
void testCycle(ListNode* head, string testName) {
    cout << testName << ": ";
    if (hasCycle(head))
        cout << "Cycle detected ✅" << endl;
    else
        cout << "No cycle ❌" << endl;
}

int main() {
    // Test Case 1: List with no cycle: 1 -> 2 -> 3 -> 4
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    testCycle(head1, "Test Case 1 (No Cycle)");

    // Test Case 2: List with a cycle: 1 -> 2 -> 3 -> 4 -> 2 ...
    ListNode* head2 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    head2->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;  // Creates a cycle
    testCycle(head2, "Test Case 2 (With Cycle)");

    return 0;
}
