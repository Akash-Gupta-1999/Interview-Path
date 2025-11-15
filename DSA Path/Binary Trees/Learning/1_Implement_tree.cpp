#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class tree {
public:
    node* root;
    int size;
    tree() {
        root = NULL;
        size = 0;
    }

    void insert(int num) {
        node* newnode = new node(num);
        if (!root) {
            root = newnode;
            size++;
            return;
        }
        node* temp = root;
        while (true) {
            if (temp->val >= num) {
                if (temp->left)
                    temp = temp->left;
                else {
                    temp->left = newnode;
                    size++;
                    break;
                }
            } else {
                if (temp->right)
                    temp = temp->right;
                else {
                    temp->right = newnode;
                    size++;
                    break;
                }
            }
        }
    }

    void print() {
        if (!root) {
            cout << "Tree is empty\n";
            return;
        }
        queue<node*> q;
        q.push(root);
        while (!q.empty()) {
            node* temp = q.front(); q.pop();
            cout << temp->val << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
};

int main() {
    tree t;

    // Insert values
    t.insert(10);
    t.insert(5);
    t.insert(15);
    t.insert(3);
    t.insert(7);
    t.insert(12);
    t.insert(18);

    cout << "Level order traversal: ";
    t.print();  // Expected: 10 5 15 3 7 12 18

    cout << "Tree size: " << t.size << endl; // Expected: 7

    return 0;
}
