#include "BaseClass.cpp"

// Recursive Solution
node * reverseLLR(node * head){
    if(head->next == NULL || head == NULL)
    {
        return head;
    }
    node* rev = reverseLLR(head->next);
    head->next->next = head;
    head->next = NULL;
    return rev;
}

// Iterative Solution
node * reverseLL(node * head)
{
    node * prev = NULL;
    node * curr = head;
    node * next = NULL;
    
    while (curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

int main()
{
    node * head = takeInput();
    node * res = reverseLLR(head);
    printLL(res);

    return 0;
}