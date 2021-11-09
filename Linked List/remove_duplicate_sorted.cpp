#include "BaseClass.cpp"
node *removeDuplicates(node *head)
{
    // Solution 1 
    // TC : O(N^2)
    node * slow = head;
    node * fast = head;
    while(slow && fast && fast->next)
    {
        fast = slow->next;
        while(fast)
        {
            if(slow->data == fast->data)
            {
                fast = fast->next;
            }else{
                break;
            }
        }
        slow->next = fast;
        slow = slow->next;
    }
    return head;

    // Solution 2
    // TC : O(N)
    node * slow = head;
    node * fast;
    while(slow and slow->next)
    {
        if(slow->data == slow->next->data)
        {
            fast = slow->next->next;
            if(fast == NULL)
            {
                slow->next = NULL;
                break;
            }
            slow->next = fast;
        }
        else if(slow->data != slow->next->data)
        {
            slow = slow->next;
        }
    }
    return head;
}
int main()
{
    node *head = takeInput();
    node *res = removeDuplicates(head);
    printLL(res);
}