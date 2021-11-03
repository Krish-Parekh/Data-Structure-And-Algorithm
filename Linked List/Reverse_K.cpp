#include "BaseClass.cpp"
node *reverseK(node *head, int k)
{
    int count = 0;
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr = NULL;
    while (currptr != NULL and count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = reverseK(nextptr, k);
    }
    return prevptr;
}

int main()
{
    node *head = takeInput();
    int kSize;
    cout << "Enter Size of K : "
         << " ";
    cin >> kSize;
    node *res = reverseK(head, kSize);
    printLL(res);
}