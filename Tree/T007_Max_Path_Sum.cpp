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

int maxSum(TreeNode *root, int &ans)
{

    if (!root)
        return 0;

    int leftSum = max(0, maxSum(root->left, ans)); // maximum is taken to avoid negative sum.
    int rightSum = max(0, maxSum(root->right, ans));

    ans = max(ans, root->val + leftSum + rightSum);

    return root->val + max(leftSum, rightSum);
}
int maxPathSum(TreeNode *root)
{

    int ans = INT_MIN;
    maxSum(root, ans);

    return ans;
}