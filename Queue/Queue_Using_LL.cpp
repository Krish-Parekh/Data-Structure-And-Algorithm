#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class node
{
public:
    T data;
    node<T> *next;

    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template<typename V>
class Queue{
    node<V> *head;
    node<V> *tail;
    int size;
    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
int getSize() { 
    return size; 
}
bool isEmpty() {
    return size == 0;
}
void enqueue(V data){
    node<V> * newNode = new node<V>(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = tail->next;
    }
    size++;
}
V dequeue(){
    int res = head->data;
    node<V> *todelete = head;
    head = head->next;
    delete todelete;
    size--;
    return res;
}
int front() {
    return head->data;
}
};
int main(){
    Queue<int>s;
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    cout << s.front() <<endl;
    cout << s.dequeue() <<endl;
    cout << s.dequeue() <<endl;
    cout << s.dequeue() <<endl;
    cout << s.getSize() <<endl;
    cout << s.isEmpty() <<endl;
}