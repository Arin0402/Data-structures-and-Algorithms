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
    bool helper(Node *root, int &FirstLeafHeight, int tempHeight)
    {

        if (!root)
            return true;

        // left node
        if (!root->left && !root->right)
        {

            // this is the first leaf node
            if (FirstLeafHeight == INT_MIN)
            {
                FirstLeafHeight = tempHeight;
                return true;
            }
            // check if the height is same or not
            else
                return FirstLeafHeight == tempHeight;
        }

        // at any point if tempheight becomes greater than the FirstLeafHeight then not possible
        if (FirstLeafHeight != INT_MIN && tempHeight > FirstLeafHeight)
            return false;

        if (helper(root->left, FirstLeafHeight, tempHeight + 1) == false)
            return false;
        if (helper(root->right, FirstLeafHeight, tempHeight + 1) == false)
            return false;

        return true;
    }
    bool check(Node *root)
    {

        // The first leaf node height
        int FirstLeafHeight = INT_MIN;

        return helper(root, FirstLeafHeight, 0);
    }
};
