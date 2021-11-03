#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node*  takeInput()
{
    node *head = NULL;
    node *tail = NULL;
    int data;
    cout << "Enter your head element "
         << " ";
    cin >> data;
    while (data != -1)
    {   
        node * newNode = new node(data);
        if(head == NULL and tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next; 
        }
        cin >> data;
    }
    return head;
}
void printLL(node * head)
{
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}