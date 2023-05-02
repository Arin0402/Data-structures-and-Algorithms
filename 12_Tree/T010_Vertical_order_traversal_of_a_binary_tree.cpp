#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};

vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{

    // Level order Traversal to traverse.
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while (!q.empty())
    {

        int size = q.size();

        for (int i = 0; i < size; i++)
        {

            auto p = q.front();
            q.pop();

            TreeNode *node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(node->val);

            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }
    }
    // create ans vector.
    vector<vector<int>> ans;

    for (auto p : nodes)
    {

        vector<int> col;

        for (auto q : p.second)
        {

            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}
vector<vector<int>> verticalTraversal(TreeNode *root)
{

    return verticalOrderTraversal(root);
}