#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// use preorder traversal to move simultaneouly in both the trees.

bool isSameTree(TreeNode *p, TreeNode *q)
{
    // either both or no one should be NULL
    if(!p && !q) return true;
    if(!p || !q) return false;

    if (p->val != q->val)
        return false;

    if (isSameTree(p->left, q->left) == false)
        return false;
    if (isSameTree(p->right, q->right) == false)
        return false;

    return true;
}
