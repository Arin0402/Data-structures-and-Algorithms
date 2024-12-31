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
Node *inOrderSuccessor(Node *root, Node *x)
{

    Node *succ = NULL;
    while (root)
    {

        if (root->data > x->data)
        {
            succ = root;
            root = root->left;
        }
        else
        {
            root = root->right; 
        }
    }

    return succ;
} 