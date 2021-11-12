#include "BaseClass.cpp"

int len(node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

int Yintersection(node *head1, node *head2)
{
    int l1 = len(head1);
    int l2 = len(head2);
    node *ptr1;
    node *ptr2;
    int d = 0;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr2 = head1;
        ptr1 = head2;
    }
    while (ptr1 != NULL and d--)
    {
        if (ptr1 == NULL)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
    }

    while (ptr1 != NULL and ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main()
{
    node *l1 = takeInput();
    node *l2 = takeInput();
    int res = Yintersection(l1, l2);
    cout << "Y intersection at " << res;
}