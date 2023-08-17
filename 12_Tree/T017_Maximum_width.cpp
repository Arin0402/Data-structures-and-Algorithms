#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-width-of-binary-tree/
// easy

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int width(TreeNode *root)
{

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    int ans = 0;

    while (!q.empty())
    {

        int size = q.size();
        int min = q.front().second; // THis is important to avoid overflow

        int left = 0;
        int right = 0;

        for (int i = 0; i < size; i++)
        {

            auto p = q.front();
            q.pop();

            TreeNode *node = p.first;
            int index = p.second - min; // THis is important to avoid overflow

            if (i == 0)
                left = index;
            if (i == size - 1)
                right = index;

            if (node->left)
                q.push({node->left, (long long)2 * index + 1});
            if (node->right)
                q.push({node->right, (long long)2 * index + 2});
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int widthOfBinaryTree(TreeNode *root)
{

    return width(root);
}