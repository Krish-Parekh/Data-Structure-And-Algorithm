#include <iostream>
using namespace std;

class Node{
    public: 

    int val;
    Node * next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }   
};

void display(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

void insertAtEnd(Node *& head, int val){
    if(head == NULL){
        Node *temp = new Node(val);
        head = temp;
        return;
    }
    Node *n = head;
    while(n->next != NULL){
        n = n->next;
    }
    Node *temp = new Node(val);
    n->next = temp; 
}

Node* reverseLL_Iterative(Node * head){
    Node *prev = NULL;
    Node *cur = head;
    Node *nxt = cur->next;
    
    while(cur != NULL){
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

Node *reverseLL_Recursive(Node *head){
    if(head == NULL || head->next ==NULL){
        return head;
    }
    Node *ll = reverseLL_Recursive(head->next);
    head->next->next = head;
    head->next = NULL; 

    return ll;
}

int main(){

    Node *head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtEnd(head, 8);
    insertAtEnd(head, 9);
    display(head);

    Node * reverseLL_i = reverseLL_Iterative(head);
    display(reverseLL_i);

    Node * reverseLL_r = reverseLL_Recursive(reverseLL_i);
    display(reverseLL_r);
    return 0;
}