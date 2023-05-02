// https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

// Good question.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right, *next;
};

class Solution
{
public:
    void Helper(Node *root, Node **next)
    {

        if (root)
        {

            Helper(root->right, next);

            root->next = *next;

            *next = root;

            Helper(root->left, next);
        }
    }

    void populateNext(Node *root)
    {

        Node *next = NULL;
        Helper(root, &next);
    }
};