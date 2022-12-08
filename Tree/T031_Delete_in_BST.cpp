//  https://leetcode.com/problems/delete-node-in-a-bst/
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

TreeNode *deleteNode(TreeNode *root, int key)
{

    if (!root)
        return NULL; // Nothing left after deleting.

    if (root->val == key)
        return helper(root); // helper function will return the final node to be pointed to.

    TreeNode *dummy = root; // save root address to return later.

    while (root)
    { // search for the node to be deleted.

        if (root->val > key)
        { // go to left.

            if (root->left != NULL && root->left->val == key)
            {                                    // root->left is node to be deleted.
                root->left = helper(root->left); // helper function will return the final node to be pointed to.
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }

    return dummy;
}

TreeNode *helper(TreeNode *root)
{

    if (root->left == NULL)
        return root->right; // nothing is present on left of the node to deleted.
    else if (root->right == NULL)
        return root->left;

    TreeNode *rightChild = root->right;              // right subtree of the node to be deleted.
    TreeNode *lastright = findLastRight(root->left); // rightmost node of the left subtree of the node to be deleted.

    lastright->right = rightChild; // connect the leftsubtree with the right one.

    return root->left; // left subtree of the node to be deleted.
}

TreeNode *findLastRight(TreeNode *root)
{

    while (root->right)
    {
        root = root->right;
    }

    return root;
}