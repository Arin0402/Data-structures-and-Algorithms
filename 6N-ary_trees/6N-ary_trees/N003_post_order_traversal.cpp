// https://leetcode.com/explore/learn/card/n-ary-tree/130/traversal/926/
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
    vector<int> postorder(Node *root)
    {
        vector<int> res;
        postOrder(root, res);
        return res;
    }

    void postOrder(Node *root, vector<int> &res)
    {
        if (root == NULL)
            return;

        for (auto x : root->children)
        {
            postOrder(x, res);
        }

        res.push_back(root->val);
    }
};

// iterative
class Solution
{
public:
    vector<int> postorder(Node *root)
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

            for (int i = 0; i < root->children.size(); i++)
            {
                st.push(root->children[i]);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};