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

node *add_two_ll(node *first, node *second)
{
    first = revLL(first);
    second = revLL(second);
    node *dummy = new node(-1);
    node *dhead = dummy;
    int sum = 0;
    int carry = 0;
    while (first != NULL || second != NULL || carry == 1)
    {
        if (first != NULL)
        {
            sum += first->data;
            first = first->next;
        }
        if (second != NULL)
        {
            sum += second->data;
            second = second->next;
        }
        sum += carry;
        carry = sum / 10;
        dummy->next = new node(sum%10);
        dummy = dummy->next;
        carry = sum / 10;
        sum = 0;
    }
    return revLL(dhead->next);
}

int main()
{
    node *first = takeInput();
    node *second = takeInput();
    node *res = add_two_ll(first, second);
    printLL(res);
}