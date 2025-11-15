#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

Node* findtail(Node* head){
    while(head->next != NULL)
        head = head->next;
    return head;
}

vector<pair<int, int>> findPairsWithSum(Node* head, int target) {
    if(head == NULL)
        return {};
    Node* tail = findtail(head);
    vector<pair<int, int>> result;

    while (head && tail && head != tail && head->prev != tail) {
        int sum = head->data + tail->data;
        if (sum == target) {
            result.push_back({head->data, tail->data});
            head = head->next;
            tail = tail->prev;
        } else if (sum < target) {
            head = head->next;
        } else {
            tail = tail->prev;
        }
    }

    return result;
}

// Helper: Create DLL from vector
Node* createDLL(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* current = head;
    for (int i = 1; i < vals.size(); ++i) {
        Node* newNode = new Node(vals[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return head;
}

// Helper: Print DLL
void printDLL(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

// Run a single test case
void runTest(vector<int> vals, int target) {
    Node* head = createDLL(vals);
    cout << "DLL: ";
    printDLL(head);
    cout << "Target Sum: " << target << endl;

    vector<pair<int, int>> pairs = findPairsWithSum(head, target);
    cout << "Pairs with sum " << target << ": ";
    if (pairs.empty()) cout << "None";
    for (auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << "\n-----------------------------\n";
}

int main() {
    // 🔹 Test case 1
    runTest({1, 2, 4, 5, 6, 8, 9}, 7);  // Expected: (1,6), (2,5)

    // 🔹 Test case 2
    runTest({1, 2, 3, 4, 5}, 10);       // Expected: (5,5) not valid — should return none

    // 🔹 Test case 3
    runTest({1, 3, 5, 7, 9}, 12);       // Expected: (3,9), (5,7)

    // 🔹 Test case 4
    runTest({}, 5);                    // Expected: None

    // 🔹 Test case 5
    runTest({2, 2, 2, 2}, 4);           // Expected: (2,2), multiple times

    return 0;
}
