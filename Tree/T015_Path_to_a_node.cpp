// https://www.interviewbit.com/problems/path-to-given-node/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool Path(TreeNode *root, int B, vector<int> &ans)
{

    if (!root)
        return false;

    ans.push_back(root->val);
    if (root->val == B)
        return true;

    if (Path(root->left, B, ans))
        return true;
    if (Path(root->right, B, ans))
        return true;

    ans.pop_back();

    return false;
}
vector<int> solve(TreeNode *A, int B)
{

    vector<int> ans;
    Path(A, B, ans);
    return ans;
}
