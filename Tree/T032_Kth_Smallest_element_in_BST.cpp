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

// Inorder of BST is always in sorted order.

// TC - O(N);
// SC - O(N) - auxilary;
int func(TreeNode *root, int &count, int k)
{

    if (!root)
    {
        count++; // increase the count.
        return -1;
    }

    int left = func(root->left, count, k);
    if (left >= 0)
        return left;

    if (count == k) // reached the desired element.
        return root->val;

    int right = func(root->right, count, k);
    if (right >= 0)
        return right;

    return -1;
}

int kthSmallest(TreeNode *root, int k)
{

    int count = 0;
    return func(root, count, k);
}

// can also be done using morris traversal.

int kthSmallest(TreeNode *root, int k)
{

    int count = 0;
    int ans;

    while (root)
    {

        if (root->left == NULL)
        {
            count++;
            if (count == k)
                ans = root->val;
            root = root->right;
        }
        else
        {

            TreeNode *prev = root->left;

            while (prev->right && prev->right != root)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = root;
                root = root->left;
            }
            else
            {
                prev->right = NULL;

                count++;
                if (count == k)
                    ans = root->val;
                root = root->right;
            }
        }
    }

    return ans;
}