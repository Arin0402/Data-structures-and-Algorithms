// https://practice.geeksforgeeks.org/problems/sum-tree/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// TC - O(n)
class Solution
{
public:
    int check(Node *root)
    {

        if (!root)
            return 0; // returns 0 if null;
        if (!root->left && !root->right)
            return root->data; // return root data if leaf node;

        int left = check(root->left);
        int right = check(root->right);

        if (left == INT_MIN || right == INT_MIN)
            return INT_MIN; // condition fails so return;

        if (root->data == left + right)
            return root->data + left + right;
        else
            return INT_MIN; // condition fails.
    }
    bool isSumTree(Node *root)
    {

        if (!root)
            return true;

        if (check(root) == INT_MIN)
            return false;
        return true;
    }
};