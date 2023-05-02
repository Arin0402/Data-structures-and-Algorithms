#include <bits/stdc++.h>
using namespace std;

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
// Brute force is to get inorder traversal which will give sotrted array and find two elements using two pointer technique.

class BSTIterator
{

    stack<TreeNode *> st;
    bool reverse; // if reverse is false , then it is from starting. i.e  left root right.  (sorted ascending)
                  // if reverse is true , then it is from end. i.e  right root left. (sorted descending)
public:
    BSTIterator(TreeNode *root, bool isReverse)
    {

        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {

        TreeNode *tp = st.top();
        st.pop();

        if (!reverse)
            pushAll(tp->right);
        else
            pushAll(tp->left);

        return tp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void pushAll(TreeNode *root)
    {

        while (root)
        {
            st.push(root);
            if (reverse)
                root = root->right;
            else
                root = root->left;
        }
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {

        if (!root)
            return false;

        BSTIterator l(root, false); // at the start of the inorder traversal.
        BSTIterator r(root, true);  // at the end of the inorder traversal.

        int left = l.next();  // points to first element of the inorder traversal;
        int right = r.next(); // points to last element of the inorder traversal;

        // Two pointer technique.
        while (left < right)
        {
            if (left + right == k)
                return true;
            else if (left + right < k)
                left = l.next();
            else
                right = r.next();
        }

        return false;
    }
};