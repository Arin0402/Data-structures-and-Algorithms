// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

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
    /*You are required to complete this method*/

    bool checkHelper(Node *root, int level, int &LeftMostleaflevel)
    {

        if (!root)
            return true;

        if (!root->left && !root->right)
        { // leaf node

            if (LeftMostleaflevel == 0)
            {                              // left most leaf node
                LeftMostleaflevel = level; // set the value.
                return true;
            }

            return (LeftMostleaflevel == level); // else compare the level with left most node height.
        }

        return checkHelper(root->left, level + 1, LeftMostleaflevel) && checkHelper(root->right, level + 1, LeftMostleaflevel);
    }

    bool check(Node *root)
    {
        int LeftMostleaflevel = 0; // height of the left most node of the tree. This will be used for compariosn.

        return checkHelper(root, 0, LeftMostleaflevel);
    }
};