#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// Approach 1;
// find the path to the two nodes seperately .
// Then traverse the paths untill the node is not same.

// TC - o(N) + O(N) (to find path for two nodes);
// SC - o(N) + O(N) (to store path for two nodes);
bool PathToNode(TreeNode *root, int x, vector<TreeNode *> &nodes)
{

    if (!root)
        return false;
    nodes.push_back(root);

    if (root->val == x)
        return true;

    if (PathToNode(root->left, x, nodes))
        return true;
    if (PathToNode(root->right, x, nodes))
        return true;

    nodes.pop_back();

    return false;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    vector<TreeNode *> nodes1, nodes2;

    PathToNode(root, p->val, nodes1); // First node path.
    PathToNode(root, q->val, nodes2); // second node path.

    TreeNode *lowestAncestor;

    // Traverse untill the node is node same.
    for (int i = 0; i < min(nodes1.size(), nodes2.size()); i++)
    {
        if (nodes1[i] == nodes2[i])
            lowestAncestor = nodes1[i];
        else
            break;
    }

    return lowestAncestor;
}

// Approach 2 - Recursive;
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (!root)
        return NULL;

    if (root == p || root == q)
        return root; // value matched.

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
        return root; // both p and q are found beneath the current node;

    if (left)
        return left; // only one of p and q is found;
    if (right)
        return right; // only one of p and q is found;

    return NULL;
}
