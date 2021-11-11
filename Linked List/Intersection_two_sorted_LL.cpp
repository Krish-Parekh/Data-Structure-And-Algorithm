#include "BaseClass.cpp"

node * find_intersection(node * l1 , node * l2)
{
    node * dummy = new node(-1);
    node * dh = dummy;
    node * temp1 = l1;
    node * temp2 = l2;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data == temp2->data)
        {
            // dummy->next = new node(temp1->data) or
            dummy->next = temp1;
            dummy = dummy->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data)
        {
            temp1 = temp1->next;
        }else{
            temp2 = temp2->next;
        }
    }
    return dh->next;
}

int main()
{
    node * l1 = takeInput();
    node * l2 = takeInput();
    node * res = find_intersection(l1,l2); 
    printLL(res);
}