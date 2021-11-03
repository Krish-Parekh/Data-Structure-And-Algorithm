#include "BaseClass.cpp"

bool DetectLoop(node *head)
{
    node *fast = head;
    node *slow = head;
    while (slow != NULL and fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    node *head = takeInput();
    if (DetectLoop(head))
    {
        cout << "Yes it has Loop";
    }
    else
    {
        cout << "No Linked List is clear" << endl;
    }
}