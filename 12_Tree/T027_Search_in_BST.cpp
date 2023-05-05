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

// Recursive - O(logn);
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if(!root) return NULL;

        if(root->val == val) return root;

        if(root->val > val) return searchBST(root->left, val);
        return searchBST(root->right, val);

    }
};
// iterative - O(logn);
TreeNode *searchBST(TreeNode *root, int val)
{

    while (root && root->val != val)
    {
        root = root->val > val ? root->left : root->right;
    }

    return root;
}