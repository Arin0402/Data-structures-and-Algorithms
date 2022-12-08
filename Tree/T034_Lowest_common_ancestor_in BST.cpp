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

// TC - O(H) (height of the tree)
// Sc - O(H) (Height of the tree)

// If we get a node for which one node(p or q) lies on the left of the node and one lies on the right, then that will be the answer.
// one of (p or q) can also be equal to the node itself , so node will be the answer.
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (!root)
        return NULL;

    if (root->val >= p->val && root->val <= q->val)
        return root; // p is present on left and q on right.
    if (root->val <= p->val && root->val >= q->val)
        return root; // q is present on left and p on right.

    if (root->val > p->val && root->val > q->val)
    {
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        if (left)
            return left;
    }
    else
    {

        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (right)
            return right;
    }

    return NULL;
}
