#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// Brute force, for every node check if it is BST or not. If it is BST then count the number of nodes in it.
// O(n*2).  checking BST takes n and we have to do it for n nodes.

// optimised.

class NodeValue
{

public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {

        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST

    NodeValue largestBstHelper(Node *root)
    {
        // An empty tree is a BST of size 0;
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);

        // Get the values from the left and right subtree of the current node;
        auto left = largestBstHelper(root->left);
        auto right = largestBstHelper(root->right);

        // current node is greater than the max in the left and min in the right, so it is a BST.
        if (left.maxNode < root->data && root->data < right.minNode)
        {

            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
        }

        // otherwise return [-inf, inf] so that the parent can't be a valid bst.
        // return the maximum of size from the left ans right.
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBst(Node *root)
    {

        return largestBstHelper(root).maxSize;
    }
};