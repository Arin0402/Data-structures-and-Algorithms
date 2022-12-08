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

// Sol 1;
// create bst by iterating over the preorder array and compairing it with the root node every time.

// Sol 2;
//  We know inorder is the sorted traversal of a bst, so get the inorder by sorting the preorder and create BST from preorder and inorder (Solution present in back video).

// Sol 3;
// Create a upper bound and insert elements by compairing with it;

TreeNode *create(vector<int> &preorder, int &ind, int bound)
{

    if (ind == preorder.size() || preorder[ind] > bound)
        return NULL;

    TreeNode *root = new TreeNode(preorder[ind++]);
    root->left = create(preorder, ind, root->val);
    root->right = create(preorder, ind, bound);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{

    int ind = 0;

    return create(preorder, ind, INT_MAX);
}
