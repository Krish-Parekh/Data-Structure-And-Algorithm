#include "BaseClass.cpp"
#include <iostream>
using namespace std;
int multiplyLL(node *head1, node *head2)
{
    int prod1 = 0;
    int prod2 = 0;
    node * temp1 = head1;
    node * temp2 = head2;
    
    while(temp1 != NULL){
        prod1 = (prod1 * 10) + temp1->data;
        temp1 = temp1->next;
    }
    while(temp2!=NULL){
        prod2 = (prod2 * 10) + temp2->data;
        temp2 = temp2->next;
    }
    return prod1 * prod2;
}

int main()
{

    node *head1 = takeInput();
    node *head2 = takeInput();
    int result = multiplyLL(head1, head2);
    cout << "Multiplication : " << result << endl;
}