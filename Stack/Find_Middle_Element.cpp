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

    V findMid()
    {
        if(head == NULL)
        {
            return -1;
        }
        else if(head->next == NULL)
        {
            return head->data;
        }
        node<V>* slow = head;
        node<V>* fast = head;
        
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void removeMid()
    {
        if(head == NULL)
        {
            return ;
        }
        else if(head->next == NULL)
        {
            cout << "Stack is empty" << endl;
            delete head;
            return;
        }
        node<V>* prev = NULL;
        node<V>* slow = head;
        node<V>* fast = head;
        
        while(slow && fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        node<V>* todelete = slow;
        prev->next = slow->next;
        delete todelete;
    }
};

int main()
{
    Stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout << s1.size() << endl;
    cout << s1.findMid() << endl;
    s1.removeMid();
    s1.removeMid();
    s1.removeMid();
    s1.removeMid();
    while (!s1.isEmpty())
    {
        cout << s1.pop() << " ";
    }
    return 0;
}