#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T> *next;
    node<T> *prev;
    node(T data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <typename J>
class Deque
{
private:
    node<J> *front;
    node<J> *rear;

public:
    Deque()
    {
        front = NULL;
        rear = NULL;
    }

    void insert_at_head(J data)
    {
        node<J> *newNode = new node<J>(data);
        if (front == NULL and rear == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            newNode->prev = NULL;
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
    }

    void insert_at_tail(J data)
    {
        node<J> *newNode = new node<J>(data);
        if (front == NULL and rear == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = rear->next;
        }
    }

    J delete_at_head()
    {
        if (front == NULL and rear == NULL)
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        else if (front->next == NULL and rear->next == NULL)
        {
            node<J> *toDelete = front;
            delete front;
            return toDelete->data;
        }
        else
        {
            J ans = front->data;
            node<J> *toDelete = front;
            front = front->next;
            delete toDelete;
            return ans;
        }
    }
    J delete_at_tail()
    {
        if (front == NULL and rear == NULL)
        {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        else if (front->next == NULL and rear->next == NULL)
        {
            node<J> *toDelete = rear;
            delete rear;
            return toDelete->data;
        }
        else
        {
            J ans = rear->data;
            node<J> *toDelete = rear;
            rear = rear->prev;
            delete toDelete;
            return ans;
        }
    }

    void print(){
        node<J> * temp = front;
        while(temp){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Deque<int>dq;
    dq.insert_at_head(8);
    dq.insert_at_head(7);
    dq.insert_at_tail(9);
    dq.insert_at_tail(10);
    dq.print(); 
    return 0;
}