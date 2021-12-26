#include "BaseClass.cpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

node * deleteRightGreater(node * head){
    node * temp = head;
    node * prev = NULL;
    while(temp!=NULL){
        node * next = temp->next;
        if(next!=NULL and next->data < temp->data){
            if(prev == NULL){
                prev = temp;
            }else{
                prev->next = next;
            }
        }else{
            prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    node * head = takeInput();
    node * res  = deleteRightGreater(head);
    printLL(res);
}