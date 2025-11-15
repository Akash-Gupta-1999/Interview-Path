#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* next;
    node* prev;
    int num;
    node(int num){
        this->next = NULL;
        this->prev = NULL;
        this->num = num;
    }
};

class linkedlist{
    node* head;
    node* tail;
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
        }
        else{
            node* ptr = head;
            while(ptr->next!=NULL)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->prev = ptr;
        }
        tail = newnode;
        length++;
    }

    void print(){
        node* ptr = head;
        cout<<"Forward: ";
        while(ptr!=NULL){
            cout<<"->"<<ptr->num;
            ptr=ptr->next;
        }
        cout<<":::::::::::::::::::"<<"Backward: ";
        ptr = tail;
        while(ptr!=NULL){
            cout<<"->"<<ptr->num;
            ptr=ptr->prev;
        }
        cout<<endl;
    }

    void insertatpos(int num, int pos){
        node* newnode = new node(num);
        if(pos == 1){
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            length++;
            return;
        }
        pos--;
        node* ptr = head;
        while(pos != 1){
            if(ptr == NULL)
            {
                cout<<"INvalid Position:: Such a position is not Available"<<endl;
                return;
            }
            ptr = ptr->next;
            pos--;
        }
        if(ptr->next != NULL){
            newnode->next = ptr->next;
            newnode->prev = ptr;
            ptr->next->prev = newnode;
            ptr->next = newnode;
        }
        else{
            ptr->next = newnode;
            newnode->prev = ptr;
            tail = newnode;
        }
        length++;
    }

    void deletionatpos(int pos){
        if(pos > length){
            cout<<"INvalid Position:: Such a position is not Available"<<endl;
            return;
        }

        if(pos == 1){
            head = head->next;
            head->prev = NULL;
        }
        else{
            pos--;
            node*ptr = head;
            while(pos != 1){
                ptr = ptr->next;
                pos--;
            }
            if(ptr->next->next != NULL){
                ptr->next = ptr->next->next;
                ptr->next->prev = ptr;
            }
            else{
                ptr->next = ptr->next->next;
                tail = ptr;
            }
        }
        length--;
    }

    int getlength(){
        return length;
    }

    void reverse(){
        node *next = NULL;
        node* curr = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = curr->prev;
            curr->prev = next;
            curr = next;
        }
        next = head;
        head = tail;
        tail = next;
    }

};

int main(){
    linkedlist ll;
    ll.insert(2);
    ll.insert(7);
    ll.insert(3);
    ll.insert(111);
    ll.print();
    ll.insertatpos(56,4);
    ll.print();
    ll.insertatpos(0,1);
    ll.print();
    ll.insertatpos(999,7);
    ll.print();
    ll.reverse();
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