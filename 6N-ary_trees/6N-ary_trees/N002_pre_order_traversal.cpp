// https://leetcode.com/explore/learn/card/n-ary-tree/130/traversal/925/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

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

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    void preorder(Node *root, vector<int> &res)
    {
        if (root == NULL)
            return;
        res.push_back(root->val);
        for (auto x : root->children)
        {
            preorder(x, res);
        }
    }
};

/// iterative
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        if (root == NULL)
            return {};
        vector<int> res;
        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {
            root = st.top();
            st.pop();
            res.push_back(root->val);

            for (int i = root->children.size() - 1; i >= 0; i--)
            {
                st.push(root->children[i]);
            }
        }
        return res;
    }
};