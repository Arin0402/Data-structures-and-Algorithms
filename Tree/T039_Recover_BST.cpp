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

// Approach 1;
// find inorder, sort it and store it.
// find the two values which are not at their position by compairing with sorted array.
// TC - O(n) (traversal) + O(nlogn) (sorting) + O(n) (compairing)
// Sc - O(n) (storing)

// Approach 2;
// file T033 - check if bst or not - approach 1;
// find out the two nodes which are faulty by compairing it wit prev node.
// swap the values of the nodes.

void check(TreeNode *root, TreeNode **prev, TreeNode **first, TreeNode **second)
{

    if (!root)
        return;

    check(root->left, prev, first, second);

    if (*prev != NULL && root->val <= (*prev)->val)
    {

        if (*first == NULL)
            *first = *prev; // prev node will be the faulty for the first time.
        *second = root;     // second time the node itself will be faulty.
    }

    (*prev) = root; // update previous.

    check(root->right, prev, first, second);
}

void swap(TreeNode *first, TreeNode *second)
{

    int t = first->val;
    first->val = second->val;
    second->val = t;
}
void recoverTree(TreeNode *root)
{

    TreeNode *prev = NULL; // pass prev node for compairing the root with previous node.
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    check(root, &prev, &first, &second);

    swap(first, second);
}