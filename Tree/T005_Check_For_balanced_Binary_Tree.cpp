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

// Approach 1
// Top Down Approach.

// To calculate the height of the tree.
int height(TreeNode *root)
{

    if (!root)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}
bool isBalanced(TreeNode *root)
{

    if (!root)
        return true;

    int leftHeight = height(root->left);   // height of left subtree.
    int rightHeight = height(root->right); // height of right subtree.

    if (abs(leftHeight - rightHeight) > 1)
        return false; // if difference in height is >1 then return false.

    if (isBalanced(root->left) == false)
        return false; // if left part returns false, the return false.
    if (isBalanced(root->right) == false)
        return false; // if right part returns false, the return false.

    return true;

    // TC - O(N^2).  O(N) time for calculating height of the tree. This need to be done for every node. so N^2.
}

// Approach 2
// Bottom Up Approach. DFS
// Same concept to calculate the height of the tree.

int Find(TreeNode *root)
{

    if (!root)
        return 0;

    int leftHeight = Find(root->left); // left subtree height.
    if (leftHeight == -1)
        return -1; // left subtree returns -1 so return -1.

    int rightHeight = Find(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return 1 + max(leftHeight, rightHeight);

    // TC- O(N).
}