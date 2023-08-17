#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-search-tree-iterator/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
    }
};

// TC - O(1) - average
// SC - O(H) - stack space.

class BSTIterator
{

    stack<TreeNode *> st;

    void pushAll(TreeNode *root)
    { // to push all the left elements in the stack.

        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root); // push all the left element sin the stack;
    }

    int next()
    {

        TreeNode *node = st.top(); // top element will be the ans;
        st.pop();

        pushAll(node->right);
        return node->val;
    }

    bool hasNext()
    {

        return !st.empty(); // if stack is not empty then it will be the true;
    }
};