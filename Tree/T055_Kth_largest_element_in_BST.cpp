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
    int Helper(Node *root, int &K)
    {

        if (!root)
            return 0;

        int right = Helper(root->right, K); // exrteme right for largest element.
        if (right)
            return right;

        if (K == 1) // got the desired elememt.
            return root->data;
        K--;

        int left = Helper(root->left, K);
        if (left)
            return left;
    }

    int kthLargest(Node *root, int K)
    {

        return Helper(root, K);
    }
};