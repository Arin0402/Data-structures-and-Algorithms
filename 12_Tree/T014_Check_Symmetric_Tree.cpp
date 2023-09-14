#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/symmetric-tree/1

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

    // right == left and left == right

    bool helper(Node *root1, Node *root2)
    {
        // either both or node
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;

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