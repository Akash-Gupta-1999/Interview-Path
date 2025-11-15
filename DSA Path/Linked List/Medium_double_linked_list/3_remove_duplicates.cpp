#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

Node* removeDuplicates(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* temp = head->next;
    while (temp != NULL) {
        Node* prevptr = temp->prev;
        if (prevptr->data == temp->data) {
            // Duplicate found, delete temp
            Node* nextptr = temp->next;
            prevptr->next = nextptr;
            if (nextptr) nextptr->prev = prevptr;
            delete temp;  // Optional: free memory
            temp = nextptr;  // Stay at the same prevptr, advance temp
        } else {
            temp = temp->next;
        }
    }

    return head;
}

// Print DLL
void printDLL(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

// Create DLL from vector
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

// Run a single test case
void runTest(vector<int> vals) {
    Node* head = createDLL(vals);
    cout << "Original DLL: ";
    printDLL(head);

    head = removeDuplicates(head);

    cout << "After removing duplicates: ";
    printDLL(head);
    cout << "-----------------------------\n";
}

int main() {
    // 🔹 Test case 1: With duplicates
    runTest({1, 2, 2, 3, 4, 4, 4, 5});

    // 🔹 Test case 2: No duplicates
    runTest({1, 2, 3, 4, 5});

    // 🔹 Test case 3: All duplicates
    runTest({6, 6, 6, 6, 6});

    // 🔹 Test case 4: Empty list
    runTest({});

    // 🔹 Test case 5: Duplicates at head and tail
    runTest({1, 1, 2, 3, 4, 5, 5});

    return 0;
}
