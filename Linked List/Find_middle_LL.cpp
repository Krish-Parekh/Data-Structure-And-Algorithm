#include "BaseClass.cpp"

node * middle(node * head)
{
    node * slow = head;
    node * fast = head;
    while(fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    node * head = takeInput();
    node * res = middle(head);
    printLL(res);
}