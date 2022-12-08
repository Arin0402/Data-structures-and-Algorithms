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

// Recursive - O(logn);
TreeNode *searchBST(TreeNode *root, int val)
{

    if (!root)
        return NULL;

    if (root->val == val)
        return root; // value found;

    if (root->val > val)
    { // if root value is greater value , then search for left;
        TreeNode *res = searchBST(root->left, val);
        if (res)
            return res; // node found, so return;
    }
    else
    {
        TreeNode *res = searchBST(root->right, val);
        if (res)
            return res;
    }

    return NULL;
}

// iterative - O(logn);
TreeNode *searchBST(TreeNode *root, int val)
{

    while (root && root->val != val)
    {
        root = root->val > val ? root->left : root->right;
    }

    return root;
}