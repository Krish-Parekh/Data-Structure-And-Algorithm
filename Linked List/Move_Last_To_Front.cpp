#include "BaseClass.cpp"

node * moveLast(node * head)
{
    node* temp = head;
    node* prev = NULL;
    while(temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->next = head;
    head = temp;
    return temp;
}

int main()
{
    node * head = takeInput();
    node * res = moveLast(head);
    printLL(res);
}