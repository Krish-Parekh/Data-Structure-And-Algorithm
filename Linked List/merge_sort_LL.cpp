#include "BaseClass.cpp"

node *mergeTwoSorted(node *fh, node *sh)
{
    node *finalhead = NULL;
    node *finaltail = NULL;
    node *h1 = fh;
    node *h2 = sh;

    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }
    while (h1 and h2)
    {
        if (h1->data < h2->data)
        {
            if (finalhead == NULL)
            {
                finalhead = h1;
                finaltail = h1;
            }
            else
            {
                finaltail->next = h1;
                finaltail = finaltail->next;
            }
            h1 = h1->next;
        }
        else if (h1->data > h2->data)
        {
            if (finalhead == NULL)
            {
                finalhead = h2;
                finaltail = h2;
            }
            else
            {
                finaltail->next = h2;
                finaltail = finaltail->next;
            }
            h2 = h2->next;
        }
    }
    while (h1 != NULL)
    {
        finaltail->next = h1;
        finaltail = finaltail->next;
        h1 = h1->next;
    }
    while (h2 != NULL)
    {
        finaltail->next = h2;
        finaltail = finaltail->next;
        h2 = h2->next;
    }
    return finalhead;
}

node *mergeSort(node *head)
{
    node *temp = head;
    node *slow = head;
    node *fast = head;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (fast and fast->next)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;

    node *fh = mergeSort(head);
    node *sh = mergeSort(slow);
    return mergeTwoSorted(fh, sh);
}

int main()
{
    node *head = takeInput();
    node *res = mergeSort(head);
    printLL(res);
}