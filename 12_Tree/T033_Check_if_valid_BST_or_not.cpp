#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/check-for-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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

// Approach 1
//  using property that inorder traversal of BST is in sorted order.
bool check(TreeNode *root, TreeNode **prev)
{

    if (!root)
        return true;

    if (check(root->left, prev) == false)
        return false; // not valid, return false.

    if (*prev != NULL && root->val <= (*prev)->val)
        return false; // root val is smaller or equal to previous node.

    (*prev) = root; // update previous.

    if (check(root->right, prev) == false)
        return false;

    return true;
}
bool isValidBST(TreeNode *root)
{

    TreeNode *prev = NULL; // pass prev node for compairing the root with previous node.
    return check(root, &prev);
}

// Approach 2
// range based checking.

bool check(TreeNode *root, long int min, long int max)
{

    if (!root)
        return true;
    if (root->val <= min || root->val >= max)
        return false;

    return check(root->left, min, root->val) && check(root->right, root->val, max);
}
bool isValidBST(TreeNode *root)
{

    return check(root, LONG_MIN, LONG_MAX);
}