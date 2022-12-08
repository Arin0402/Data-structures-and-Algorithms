#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// iterative
vector<int> Iterative(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<pair<TreeNode *, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while (!q.empty())
    {

        auto p = q.front();
        q.pop();

        TreeNode *node = p.first;
        int y = p.second;

        mp[y] = node->val;

        if (node->left)
            q.push({node->left, y + 1});
        if (node->right)
            q.push({node->right, y + 1});
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

// recursive
void Recursive(TreeNode *root, vector<int> &ans, int level)
{

    if (!root)
        return;

    if (ans.size() == level)
        ans.push_back(root->val);

    Recursive(root->right, ans, level + 1);
    Recursive(root->left, ans, level + 1);
}
vector<int> rightSideView(TreeNode *root)
{
    // return Iterative(root);

    vector<int> ans;

    Recursive(root, ans, 0);
    return ans;
}