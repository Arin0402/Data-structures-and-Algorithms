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

// Approach 1;
// Top Down
// O(n^2)
int height(TreeNode *root)
{
    if (!root)
        return 0;

    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

int diameter(TreeNode *root, int &ans)
{

    if (!root)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    ans = max(left + right, ans);

    diameter(root->left, ans);
    diameter(root->right, ans);

    return ans + 1;
}

// Approach 2
// Bottom Up Approach. DFS

int height(TreeNode *root, int &ans)
{

    if (!root)
        return 0;

    int left = height(root->left, ans);
    int right = height(root->right, ans);

    ans = max(left + right, ans);

    return 1 + max(left, right);
}
int diameter(TreeNode *root)
{

    int ans = 0;
    height(root, ans);
    return ans + 1;
}