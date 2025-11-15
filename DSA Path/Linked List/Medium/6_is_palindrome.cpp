#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Reverse a linked list
ListNode* reverse(ListNode* head) {
    ListNode *curr = head, *prev = NULL, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Check if linked list is a palindrome
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    ListNode *hare = head, *tort = head;

    // Step 1: Find the middle of the list
    while (hare != NULL && hare->next != NULL) {
        hare = hare->next->next;
        tort = tort->next;
    }

    // Step 2: Reverse second half
    ListNode *head1 = reverse(tort);

    // Step 3: Compare first half and reversed second half
    ListNode* first = head;
    ListNode* second = head1;
    while (second != NULL) {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}

// Helper to create list from vector
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

// Run test case
void runTest(vector<int> vals, string testName) {
    ListNode* head = createList(vals);
    cout << testName << ": ";
    if (isPalindrome(head))
        cout << "Palindrome ✅" << endl;
    else
        cout << "Not a Palindrome ❌" << endl;
}

int main() {
    runTest({1, 2, 3, 2, 1}, "Test 1 (Odd Palindrome)");
    runTest({1, 2, 2, 1}, "Test 2 (Even Palindrome)");
    runTest({1, 2, 3, 4}, "Test 3 (Not a Palindrome)");
    runTest({1}, "Test 4 (Single Node)");
    runTest({}, "Test 5 (Empty List)");

    return 0;
}
