#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

//  if both children sum is less than parent, make children's value to parent's value.
//  recursively go left and right. Traversal type: DFS.
//  when coming back up the tree, take children sum and replace it in parent.
//  at any point we reach null, just return (base case)
//  Intuition: while going down, increase the children values so we make sure to never fall short, then all we have to do is sum both children and replace it in parent.

void change(TreeNode *root)
{

    if (!root)
        return;

    if (!root->left && !root->right)
        return; // leaf node.

    int tot = 0; // sum of left and right child.
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;

    if (tot < root->data)
    { // sum is lesser than the current root value.
        if (root->left)
            root->left->data = root->data; // change values of the children nodes.
        if (root->right)
            root->right->data = root->data;
    }

    change(root->left);
    change(root->right);

    tot = 0; // sum of left and right child.
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;

    root->data = tot; // change the value of current root.
}
