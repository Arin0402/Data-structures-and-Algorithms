#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int data;
    Node *left = NULL, *right = NULL;

    Node(int val)
    {
        data = val;
    }
};

void inorder(Node *curr, Node *&prev)
{
    // Base case
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

// Function to flatten binary tree using
// level order traversal
Node *flatten(Node *parent)
{
    // Dummy Node
    Node *dummy = new Node(-1);

    // Pointer to previous element
    Node *prev = dummy;

    // Calling in-order traversal
    inorder(parent, prev);

    prev->left = NULL;
    prev->right = NULL;
    Node *ret = dummy->right;

    // Delete dummy Node
    delete dummy;
    return ret;
}
