#include "BaseClass.cpp"

node *remove_duplicates(node *head)
{
    
    node * prev = NULL;
    node * temp = head;
    unordered_map<int, bool> m;
    while(temp)
    {
        if(m[temp->data])
        {
            prev->next = temp->next;
        }else{
            m[temp->data] = true;
            prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    node *head = takeInput();
    node *res = remove_duplicates(head);
    printLL(res);
}