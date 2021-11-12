#include "BaseClass.cpp"

void removeLoop(node* head)
{
    // solution 1
        node * fast = head;
        node * slow = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                fast = head;
                while(slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                slow->next = NULL;
                break;
            }
        }while(slow && fast && fast->next);
    
    
    // Solution 2 
        unordered_map<node*,bool> m;
        while(head!=NULL)
        {
            if(m[head->next] == true)
            {
                head->next = NULL;
                break;
            }else{
                m[head] = true;
                head = head->next;
            }
        }
}

int main()
{
    node *head = takeInput();
    removeLoop(head);
}