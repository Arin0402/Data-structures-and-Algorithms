#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Same as vertical order traversal but we only need the first elememt of each column.
vector<int> topView(Node *root)
{

    vector<int> ans;

    if (!root)
        return ans;

    queue<pair<Node *, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while (!q.empty())
    {

        auto p = q.front();
        q.pop();

        Node *node = p.first;
        int x = p.second;

        if (!mp[x])
        {
            mp[x] = node->data;
        }

        if (node->left)
            q.push({node->left, x - 1});
        if (node->right)
            q.push({node->right, x + 1});
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}