#include<bits/stdc++.h>
using namespace std;

class stacks{
    int st[100001];
    int idx = -1, size = 0;
    public:
        void push(int num){
            idx++;
            if(idx >= 1000001){
                cout<<"Stack is full u cannot push more"<<endl;
                return;
            }
            st[idx] = num;
            size++;
        }
        void pop(){
            if(idx == -1){
                cout<<"no element to pop"<<endl;
                return;
            }
            idx--;
            size--;
        }
        void print(){
            for(int i=0;i<size;i++)
                cout<<st[i]<<" ";
            cout<<endl;
        }
        int top(){
            return st[idx];
        }
};

int main(){
    stacks s1;
    s1.push(4);
    s1.push(100);
    s1.push(1003);
    s1.push(-45);
    s1.print();
    s1.pop();
    s1.print();
    cout<<s1.top()<<endl;
}