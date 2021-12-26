#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

BinaryTreeNode<int> *takeInputDFS()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInputDFS();
    BinaryTreeNode<int> *rightChild = takeInputDFS();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int> *takeInputBFS()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        int leftChildData;
        cout << "Enter LeftChild of " << front->data << " :";
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            q.push(leftChild);
        }

        int rightChildData;
        cout << "Enter rightChild of " << front->data << " :";
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}

void printDFS(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    printDFS(root->left);
    printDFS(root->right);
    cout << root->data << " ";
}

void printBFS(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        cout << front->data << ":";
        q.pop();
        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << " , ";
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R:" << front->right->data;
            q.push(front->right);
        }
        cout << endl;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInputBFS();
    printBFS(root);
    return 0;
}