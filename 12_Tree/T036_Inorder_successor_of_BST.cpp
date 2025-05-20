#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// O(H)
int inOrderSuccessor(Node *root, Node *x)
{

    int succ = -1;

    // find the x
    while (root != x)
    {
        if (root->data > x->data)
        {
            succ = root->data;
            root = root->left;
        }
        else
            root = root->right;
    }

    // if nothing is present on the rigt then the x's parent is the inorder successor
    if (root->right == NULL)
        return succ;

    // go to right
    root = root->right;

    // The left most element of the right subtree
    while (root->left)
        root = root->left;

    succ = root->data;

    return succ;
}