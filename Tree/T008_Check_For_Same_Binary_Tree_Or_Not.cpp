#include <bits/stdc++.h>
using namespace std;

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

    if (p == NULL || q == NULL)
    {
        // return true if match, else false.
        return p == q;
    }

    if (p->val != q->val)
        return false;

    if (isSameTree(p->left, q->left) == false)
        return false;
    if (isSameTree(p->right, q->right) == false)
        return false;

    return true;
}
