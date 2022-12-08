#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
    }
};

// Approach 1 - recursive.

void func(TreeNode *root, TreeNode **prev)
{

    if (!root)
        return;

    func(root->right, prev);
    func(root->left, prev);

    root->right = *prev; // assign right to prev;
    root->left = NULL;   // change left = null, as it is gonna be right skewed BT;

    *prev = root; // change prev to root;
}

void flatten(TreeNode *root)
{

    TreeNode *prev = NULL; // node to which the right pointer will be assigned to;

    func(root, &prev);
}

// Aproach 2 - Morris traversal

void flatten(TreeNode *root)
{

    TreeNode *curr = root;

    while (curr)
    {

        if (curr->left)
        { // only proceed if left is not null;

            TreeNode *prev = curr->left;

            while (prev->right)
            {
                prev = prev->right;
            }

            prev->right = curr->right;
            curr->right = curr->left;

            curr->left = NULL;
        }

        curr = curr->right;
    }
}