// https://leetcode.com/explore/learn/card/n-ary-tree/130/traversal/915/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// iterative solution
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> curr;
            while (size--)
            {
                root = q.front();
                q.pop();
                curr.push_back(root->val);

                for (auto x : root->children)
                {
                    q.push(x);
                }
            }
            res.push_back(curr);
        }

        return res;
    }
};

// recursive solution
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        traverse(root, res, 0);
        return res;
    }

    void traverse(Node *node, vector<vector<int>> &res, int level)
    {
        if (node == NULL)
            return;
        if (level == res.size())
        {
            res.push_back(vector<int>());
        }
        res[level].push_back(node->val);
        for (auto x : node->children)
        {
            traverse(x, res, level + 1);
        }
    }
};