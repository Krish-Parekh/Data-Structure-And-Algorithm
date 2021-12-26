#include "BaseClass.cpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int listlen(node * head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}

int nthNodeFromEnd(node * head , int k){
    int len = listlen(head);
    int find = len - k;
    node * temp = head;
    for(int i = 0 ; i < find ; i++){
        temp = temp->next;
    }
    return temp->data;
}

int main(){
    node * head = takeInput();
    int k;
    cin >> k;
    int ans = nthNodeFromEnd(head , k);
    cout << ans << endl;
}