#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-depth-of-binary-tree/1

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive
int maxDepth(TreeNode *root)
{

    if (root == NULL)
        return 0;

    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);

    return 1 + max(left_height, right_height);
}
