#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
    }
};

// TC - O(logn)
void insert(TreeNode *root, int val)
{

    while (root)
    {

        if (root->val < val)
        {

            if (root->right)
                root = root->right; // if there exists a right, got to right.
            else
            { // else insert.
                TreeNode *newnode = new TreeNode(val);
                root->right = newnode;
                break;
            }
        }
        else
        {
            if (root->left)
                root = root->left;
            else
            {
                TreeNode *newnode = new TreeNode(val);
                root->left = newnode;
                break;
            }
        }
    }
}

TreeNode *insertIntoBST(TreeNode *root, int val)
{

    if (!root)
    {
        return new TreeNode(val);
    }

    insert(root, val);
    return root;
}