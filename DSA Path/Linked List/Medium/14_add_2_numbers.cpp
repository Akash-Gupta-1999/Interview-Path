#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

// Helper function: Convert vector to linked list
ListNode* createList(const vector<int>& vals) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Helper function: Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Run a single test case
void runTest(vector<int> l1_vals, vector<int> l2_vals) {
    ListNode* l1 = createList(l1_vals);
    ListNode* l2 = createList(l2_vals);

    cout << "Input List 1: ";
    printList(l1);
    cout << "Input List 2: ";
    printList(l2);

    ListNode* result = addTwoNumbers(l1, l2);
    cout << "Result: ";
    printList(result);
    cout << "-----------------------------\n";
}

int main() {
    // Test case 1: 342 + 465 = 807
    runTest({2, 4, 3}, {5, 6, 4});

    // Test case 2: 99 + 1 = 100
    runTest({9, 9}, {1});

    // Test case 3: 0 + 0 = 0
    runTest({0}, {0});

    // Test case 4: 9999 + 1 = 10000
    runTest({9, 9, 9, 9}, {1});

    // Test case 5: Different lengths without carry
    runTest({1, 2}, {3, 4, 5});

    return 0;
}
