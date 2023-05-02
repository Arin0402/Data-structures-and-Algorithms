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
        left = right = NULL;
    }
};

class Solution
{
public:
    // return true/false denoting whether the tree is Symmetric or not

    bool helper(Node *root1, Node *root2)
    {

        if (!root1 || !root2)
            return root1 == root2;

        if (root1->data != root2->data)
            return false;

        if (helper(root1->left, root2->right) == false)
            return false;
        if (helper(root1->right, root2->left) == false)
            return false;

        return true;
    }

    bool isSymmetric(struct Node *root)
    {
        if (!root)
            return true;

        return helper(root->left, root->right);
    }
};