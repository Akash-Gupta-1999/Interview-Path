#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int key, val;
    node* next;
    node* prev;
    node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
};

class LRUCache {
public:
    unordered_map<int, node*> hash;
    int capacity;
    int size;
    node* head; // most recently used
    node* tail; // least recently used

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end())
            return -1;
        node* cur = hash[key];
        moveToHead(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()) {
            node* cur = hash[key];
            cur->val = value;
            moveToHead(cur);
            return;
        }

        node* newnode = new node(key, value);

        if(size == capacity) {
            // evict least recently used (tail)
            hash.erase(tail->key);
            removeNode(tail);
            size--;
        }

        addToHead(newnode);
        hash[key] = newnode;
        size++;
    }

private:
    void addToHead(node* n) {
        n->prev = NULL;
        n->next = head;
        if(head) head->prev = n;
        head = n;
        if(!tail) tail = n;
    }

    void removeNode(node* n) {
        if(n->prev) n->prev->next = n->next;
        else head = n->next;
        if(n->next) n->next->prev = n->prev;
        else tail = n->prev;
    }

    void moveToHead(node* n) {
        removeNode(n);
        addToHead(n);
    }
};

// ---------- test ----------
int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n"; // 1
    cache.put(3, 3);              // evicts 2
    cout << cache.get(2) << "\n"; // -1
    cache.put(4, 4);              // evicts 1
    cout << cache.get(1) << "\n"; // -1
    cout << cache.get(3) << "\n"; // 3
    cout << cache.get(4) << "\n"; // 4

    return 0;
}
