#include "BaseClass.cpp"

node *revLL(node *head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr = NULL;
    while (currptr)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

node *addOne(node *head)
{
    head = revLL(head);
    node *temp = head;
    bool seen = true;
    while(temp and seen)
    {   
        if(temp->next == NULL and temp->data == 9)
        {
            temp->data = 1;
            node * carry = new node(0);
            carry->next = head;
            head = carry;
            temp = temp->next;
        }
        else if(temp->data == 9)
        {
            temp->data = 0;
            temp = temp->next;
        }
        else
        {
            temp->data = temp->data + 1;
            seen = false;
        }
    }
    return revLL(head);
}

int main()
{
    node *head = takeInput();
    node *res = addOne(head);
    printLL(res);
}