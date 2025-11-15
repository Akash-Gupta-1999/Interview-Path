#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, val, freq;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), freq(1), prev(NULL), next(NULL) {}
};

struct DLL {
    Node* head;
    Node* tail;
    int size;
    DLL() {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node* n) {
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
        size++;
    }
    void removeNode(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        size--;
    }
    Node* removeLast() {
        if(size==0) return NULL;
        Node* last = tail->prev;
        removeNode(last);
        return last;
    }
};

class LFUCache {
    int capacity, curSize, minFreq;
    unordered_map<int, Node*> keyNode;    // key -> node
    unordered_map<int, DLL*> freqList;    // freq -> list of nodes
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;
        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        } else {
            if(curSize == capacity) {
                DLL* list = freqList[minFreq];
                Node* toRemove = list->removeLast();
                keyNode.erase(toRemove->key);
                curSize--;
            }
            Node* newNode = new Node(key, value);
            minFreq = 1;
            if(freqList.find(minFreq) == freqList.end())
                freqList[minFreq] = new DLL();
            freqList[minFreq]->addFront(newNode);
            keyNode[key] = newNode;
            curSize++;
        }
    }
    
private:
    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        freqList[oldFreq]->removeNode(node);
        if(oldFreq == minFreq && freqList[oldFreq]->size == 0)
            minFreq++;
        node->freq++;
        if(freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new DLL();
        freqList[node->freq]->addFront(node);
    }
};

// -------- test ----------
int main() {
    LFUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n"; // returns 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << "\n"; // returns -1
    cout << cache.get(3) << "\n"; // returns 3
    cache.put(4, 4);              // evicts key 1
    cout << cache.get(1) << "\n"; // returns -1
    cout << cache.get(3) << "\n"; // returns 3
    cout << cache.get(4) << "\n"; // returns 4

    return 0;
}
