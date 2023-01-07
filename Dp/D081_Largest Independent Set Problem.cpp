#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// https://practice.geeksforgeeks.org/problems/largest-independent-set-problem/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// for recursion the time complexity is exponential.

// 1
// O(n)
int helper(Node *root, unordered_map<Node *, int> &mp)
{

    if (root == NULL)
        return 0;

    // single node
    if (!root->left && !root->right)
        return 1;

    if (mp[root] != 0)
        return mp[root];

    // excluding the current node
    int choice1 = helper(root->left, mp) + helper(root->right, mp);

    // including the current node
    int choice2 = 1;

    if (root->left)
    {
        choice2 += helper(root->left->left, mp) + helper(root->left->right, mp);
    }
    if (root->right)
    {
        choice2 += helper(root->right->left, mp) + helper(root->right->right, mp);
    }

    return mp[root] = max(choice1, choice2);
}
int LISS(Node *root)
{
    // for memoization
    unordered_map<Node *, int> mp;

    return helper(root, mp);
}
