// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
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
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/

    string dupSubHelper(Node *root, unordered_map<string, int> &mp)
    {

        if (!root)
            return "$"; // if root is NULL;

        string s = "";

        if (!root->left && !root->right)
        { // leaf node
            s += to_string(root->data);
            return s;
        }

        s += to_string(root->data);
        s += '.'; // to seperate the two values.
        s += dupSubHelper(root->left, mp);
        s += '.';
        s += dupSubHelper(root->right, mp);

        mp[s]++;

        return s;
    }

    int dupSub(Node *root)
    {

        unordered_map<string, int> mp;

        dupSubHelper(root, mp);

        for (auto m : mp)
        { // if any string is occured more than one, then return 1;
            if (m.second >= 2)
                return 1;
        }

        return 0;
    }
};