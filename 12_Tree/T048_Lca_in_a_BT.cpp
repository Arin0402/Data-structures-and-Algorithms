// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
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
    // Function to return the lowest common ancestor in a Binary Tree.

    Node *func(Node *root, int n1, int n2)
    {

        if (!root)
            return NULL;

        if (root->data == n1 || root->data == n2)
            return root; // one of the n1 or n2.

        Node *left = func(root->left, n1, n2);
        Node *right = func(root->right, n1, n2);

        if (left && right)
            return root; // if left and right contains the n1 and n2 nodes, then root will be the answer.

        if (left)
            return left; // case in which root element is one of the n1 or n2 , and other node is in lower level of this node.

        return right;
    }

    Node *lca(Node *root, int n1, int n2)
    {

        return func(root, n1, n2);
    }
};

// !-------------------NoTE--------------------!

// For finding LCA of three numbers say a,b,c 

//     Lca(a,b,c) = LCA(a, LCA(b, c))

//     we first find LCA(b, c) and then we find the LCA of a with the result of LCA(b,c)