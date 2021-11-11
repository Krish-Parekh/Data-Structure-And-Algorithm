#include "BaseClass.cpp"

node *createCircular()
{
    node *head = NULL;
    node *tail = NULL;
    int data;
    cout << "Enter your head element "
         << " ";
    cin >> data;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == NULL and tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    tail->next = head;
    return head;
}

bool checkIfCircular(node *head)
{
    node *temp = head;
    while (temp)
    {
        if (temp->next == head)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main()
{
    node *head = takeInput();
    string res = checkIfCircular(head) ? "Yes it's circular" : "No it's not circular";
    cout << res << endl;
}