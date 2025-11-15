#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

// Custom comparator for min-heap
class comp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // min-heap by value
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;

        // Push all list heads into heap
        for (ListNode* head : lists) {
            if (head != nullptr) pq.push(head);
        }

        // Dummy node to simplify result list construction
        ListNode* dummynode = new ListNode();
        ListNode* tail = dummynode;

        // Process heap
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();

            tail->next = top;
            tail = top;

            if (top->next) {
                pq.push(top->next);
            }
        }

        return dummynode->next;
    }
};

// Utility function to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    ListNode* dummy = new ListNode();
    ListNode* tail = dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy->next;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    Solution sol;

    // Testcases
    vector<vector<int>> inputs = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    vector<ListNode*> lists;
    for (auto& arr : inputs) {
        lists.push_back(createList(arr));
    }

    cout << "Merging K sorted lists:\n";
    for (int i = 0; i < lists.size(); i++) {
        cout << "List " << i+1 << ": ";
        printList(lists[i]);
    }

    ListNode* merged = sol.mergeKLists(lists);

    cout << "\nMerged List: ";
    printList(merged);

    return 0;
}
