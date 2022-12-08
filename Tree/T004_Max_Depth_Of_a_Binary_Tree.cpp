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

// Recursive
int maxDepth(TreeNode *root)
{

    if (root == NULL)
        return 0;

    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);

    return 1 + max(left_height, right_height);
}

// Iterative.
// Using Level Order Traversal.
int maxDepth(TreeNode *root)
{

    int max_height = 0;

    if (!root)
        return max_height;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {

        int size = q.size();

        if (size > 0)
            max_height++;
        vector<int> lvl;

        for (int i = 0; i < size; i++)
        {

            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    return max_height;
}