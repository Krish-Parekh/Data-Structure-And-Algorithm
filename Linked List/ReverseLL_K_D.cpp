#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        int i = 0;
        node *prev = NULL;
        node *cur = head;
        node *nxt = NULL;
        
        while(cur != NULL && i<k){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            i++;
        }
        
        if(nxt != NULL){
            head->next = reverse(nxt, k);
        }
        
        return prev;
    }
};