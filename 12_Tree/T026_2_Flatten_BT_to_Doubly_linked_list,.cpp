// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
// https://www.youtube.com/watch?v=nGNoTdav5bQ
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
    }
};

class Solution
{
public:
    // Function to convert binary tree to doubly linked list and return it.

    void func(Node *root, Node **head, Node **prev)
    {
        if (!root)
            return;

        func(root->left, head, prev);

        if (*prev == NULL)
            *head = root;
        else
        {
            (*prev)->right = root;
            root->left = *prev;
        }

        *prev = root;

        func(root->right, head, prev);
    }

    Node *bToDLL(Node *root)
    {

        Node *prev = NULL;
        Node *head = NULL;
        func(root, &head, &prev);

        return head;
    }
};