#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{

public:
    T data;
    node *next;

    node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename V>
class Stack
{
    node<V> * head;
    int top = 0;
public:
    Stack()
    {
        this->head = NULL;
    }
    int size()
    {
        return top;
    }

    bool isEmpty()
    {
        return top == 0;
    }

    void push(V data)
    {
        if(head == NULL)
        {
            head = new node<V>(data);
        }
        else
        {
            node<V> * newNode = new node<V>(data);
            newNode->next = head;
            head = newNode;
        }
        top++;
    }

    V pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        else
        {
            node<V> * toDelete = head;
            V deleteData = head->data;
            head = head->next;
            delete toDelete;
            return deleteData;
        }
        top--;
    }
};

int main()
{
    Stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << s1.size() << endl;
    while (!s1.isEmpty())
    {
        cout << s1.pop() << endl;
    }
    
    return 0;
}