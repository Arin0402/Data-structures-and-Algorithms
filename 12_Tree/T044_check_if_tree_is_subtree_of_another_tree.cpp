// https://practice.geeksforgeeks.org/problems/check-if-subtree/1
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
    // Function to check if S is a subtree of tree T.

    bool areIdentical(Node *root1, Node *root2)
    {

        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL || root2 == NULL)
            return false;

        if (root1->data != root2->data)
            return false;

        if (areIdentical(root1->left, root2->left) == false)
            return false;
        if (areIdentical(root1->right, root2->right) == false)
            return false;

        return true;
    }

    bool isSubTree(Node *T, Node *S)
    {
        if (S == NULL)
            return true;

        if (T == NULL)
            return false;

        if (areIdentical(T, S))
            return true;

        if (isSubTree(T->left, S) == true)
            return true;
        if (isSubTree(T->right, S) == true)
            return true;

        return false;
    }
};