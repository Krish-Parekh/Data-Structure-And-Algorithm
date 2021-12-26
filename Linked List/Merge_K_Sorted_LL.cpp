#include "BaseClass.cpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

node *mergeKSorted(node *arr[], int K)
{

    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < K; i++)
    {
        node *head = arr[i];
        while (head != NULL)
        {
            p.push(head->data);
            head = head->next;
        }
    }
    node *dummy = new node(-1);
    node *head = dummy;
    while (p.size() != 0)
    {
        head->next = new node(p.top());
        p.pop();
        head = head->next;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    int k = n;
    node *arr[n];
    int i = 0;
    while (n != 0)
    {
        node *head = takeInput();
        arr[i] = head;
        i++;
        n--;
    }
    node *result = mergeKSorted(arr, k);
    printLL(result);
}