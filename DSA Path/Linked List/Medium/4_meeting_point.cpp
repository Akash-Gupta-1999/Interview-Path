#include <bits/stdc++.h>
using namespace std;

// Definition of singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to detect the start of the cycle
ListNode* detectCycle(ListNode *head) {
    ListNode *hare = head, *tort = head;

    // Phase 1: Detect if a cycle exists
    while (hare != NULL && hare->next != NULL) {
        hare = hare->next->next;
        tort = tort->next;
        if (hare == tort) break;
    }

    // If no cycle
    if (hare == NULL || hare->next == NULL) return NULL;

    // Phase 2: Find start of the cycle
    ListNode* temp = head;
    while (temp != hare) {
        temp = temp->next;
        hare = hare->next;
    }

    return temp;
}

// Utility to print the result
void testCycleDetection(ListNode* head, string testName) {
    ListNode* cycleStart = detectCycle(head);
    cout << testName << ": ";
    if (cycleStart)
        cout << "Cycle starts at node with value = " << cycleStart->val << " ✅" << endl;
    else
        cout << "No cycle found ❌" << endl;
}

int main() {
    // Test Case 1: No cycle
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    testCycleDetection(head1, "Test Case 1 (No Cycle)");

    // Test Case 2: Cycle starting at node with value 2
    ListNode* head2 = new ListNode(10);
    ListNode* node2 = new ListNode(20);
    ListNode* node3 = new ListNode(30);
    ListNode* node4 = new ListNode(40);
    head2->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates cycle back to node2
    testCycleDetection(head2, "Test Case 2 (Cycle at 20)");

    return 0;
}
