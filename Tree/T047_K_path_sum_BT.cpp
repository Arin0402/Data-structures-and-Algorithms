// https://practice.geeksforgeeks.org/problems/k-sum-paths/1
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
    void Helper(Node *root, int k, int &ans, vector<int> &path)
    {

        if (!root)
            return;

        path.push_back(root->data);

        Helper(root->left, k, ans, path);
        Helper(root->right, k, ans, path);

        int sum = 0;

        for (int i = path.size() - 1; i >= 0; i--)
        { // traverse from the bck side of the vector.

            sum += path[i];

            if (sum == k)
                ans++;
        }

        path.pop_back(); // remove the last element of the vector.
    }

    int sumK(Node *root, int k)
    {

        if (!root)
            return 0;

        int ans = 0;
        vector<int> path; // store all the nodes from top to bottom.

        Helper(root, k, ans, path);

        return ans;
    }
};