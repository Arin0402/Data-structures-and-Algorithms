#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    int small, large;

    small = min(p->val, q->val);
    large = max(p->val, q->val);

    while (root)
    {
        
        // The element which lies in the range of small and large is our LCA
        if (root->val >= small && root->val <= large)
            return root;

        else if (root->val > small && root->val > large)
            root = root->left;
        else
            root = root->right;
    }

    return NULL;
}
