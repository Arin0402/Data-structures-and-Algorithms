// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    /* Should return minimum distance between a and b
    in a tree with given root*/

    Node *findLca(Node *root, int a, int b)
    {

        if (!root)
            return NULL;

        if (root->data == a || root->data == b)
            return root;

        Node *left = findLca(root->left, a, b);
        Node *right = findLca(root->right, a, b);

        if (left && right)
            return root;
        if (left)
            return left;
        return right;
    }

    int distance(Node *root, int x)
    {

        if (!root)
            return 0;

        if (root->data == x)
            return 1;

        int left = distance(root->left, x);
        int right = distance(root->right, x);

        if (left > 0 || right > 0)
            return 1 + left + right;

        return 0;
    }

    int findDist(Node *root, int a, int b)
    {

        Node *lca = findLca(root, a, b); // calculate lca.

        int dis1 = distance(lca, a); // distance of node a from lca.
        int dis2 = distance(lca, b); // distance of node b from lca.

        return dis1 + dis2 - 2;
    }
};