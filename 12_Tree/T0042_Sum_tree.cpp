// https://practice.geeksforgeeks.org/problems/s    um-tree/1
#include <bits/stdc++.h>
using namespace std;

// easy

struct Node
{
    int data;
    Node *left, *right;
};

// TC - O(n)
class Solution
{
public:
    int helper(Node *root)
    {

        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->data;

        int left = helper(root->left);
        int right = helper(root->right);

        if (root->data == left + right)
            return root->data + left + right;
        else
            return 0;
    }

    bool isSumTree(Node *root)
    {

        int val = helper(root);

        return val;
    }
};