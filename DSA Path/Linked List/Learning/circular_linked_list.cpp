#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* next;
    int num;
    node(int num){
        this->next = NULL;
        this->num = num;
    }
};

class linkedlist{
    node *head, *tail;
    int length;

    public:
    linkedlist(){
        head = NULL;
        tail = NULL;
        length = 0;    
    }

    void insert(int num){
        node* newnode = new node(num);
        if(head == NULL){
            head = newnode;
            newnode->next = head;
            tail = head;
        }
        else{
            node* ptr = head;
            while(ptr->next!=head)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
        length++;
    }

    void print(){
        node* ptr = head;
        while(ptr->next!=head){
            cout<<"->"<<ptr->num;
            ptr=ptr->next;
        }
        cout<<"->"<<ptr->num;
        cout<<endl;
    }

    void insertatpos(int num, int pos){
        node* newnode = new node(num);
        if(pos == 1){
            newnode->next = head;
            head = newnode;
            tail->next = head;
            length++;
            return;
        }
        pos--;
        node* ptr = head;
        while(pos != 1){
            if(ptr->next == head)
            {
                cout<<"INvalid Position:: Such a position is not Available"<<endl;
                return;
            }
            ptr = ptr->next;
            pos--;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
        if(ptr == tail)
            tail = newnode;
        length++;
    }

    void deletionatpos(int pos){
        if(pos > length){
            cout<<"INvalid Position:: Such a position is not Available"<<endl;
            return;
        }

        if(pos == 1){
            head = head->next;
            tail->next = head;
        }
        else{
            pos--;
            node*ptr = head;
            while(pos != 1){
                ptr = ptr->next;
                pos--;
            }
            ptr->next = ptr->next->next;
            if(ptr->next == tail)
                tail = ptr;
        }
        length--;
    }

    int getlength(){
        return length;
    }

    void reverse(){
        node *prev = NULL,*next = NULL;
        node* curr = head;
        while(curr->next != head){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        head->next = curr;
        tail = head;
        head = curr;
    }

};

int main(){
    linkedlist ll;
    ll.insert(2);
    ll.insert(7);
    ll.insert(3);
    ll.insert(111);
    ll.insertatpos(56,4);
    ll.insertatpos(0,1);
    ll.insertatpos(999,7);
    ll.print();
    // ll.reverse();
    ll.print();
    ll.insertatpos(1000,10);
    ll.print();
    ll.deletionatpos(1);
    ll.print();
    cout<<ll.getlength()<<endl;
    ll.deletionatpos(6);
    ll.deletionatpos(10);
    ll.print();
    ll.deletionatpos(3);
    ll.print();
    ll.reverse();
    ll.print();
}