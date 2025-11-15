#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

// 🔧 FUNCTION TO IMPLEMENT
Node* deleteAllOccurrences(Node* head, int key) {
    // Implement your logic here
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            Node *prevptr = temp->prev, *nextptr = temp->next;
            if(temp == head)
                head = head->next;
            if(prevptr) prevptr->next = nextptr;
            if(nextptr) nextptr->prev = prevptr;
            temp = nextptr;
        }else temp = temp->next;
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

// Run single test case
void runTest(vector<int> values, int key) {
    Node* head = createDLL(values);
    cout << "Original DLL: ";
    printDLL(head);

    head = deleteAllOccurrences(head, key);
    
    cout << "After deleting key " << key << ": ";
    printDLL(head);
    cout << "-----------------------------\n";
}

int main() {
    // 🔹 Test case 1: Multiple occurrences
    runTest({10, 20, 10, 30, 10, 40}, 10);

    // 🔹 Test case 2: No occurrence
    runTest({1, 2, 3, 4}, 5);

    // 🔹 Test case 3: All nodes to be deleted
    runTest({7, 7, 7, 7}, 7);

    // 🔹 Test case 4: Delete from head and tail
    runTest({9, 2, 3, 4, 9}, 9);

    // 🔹 Test case 5: Empty list
    runTest({}, 1);

    return 0;
}
