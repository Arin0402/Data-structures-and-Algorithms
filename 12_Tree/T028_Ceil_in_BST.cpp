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
    }
};

// solution 1;
int func1(Node *root, int input)
{
    int ans = INT_MAX;

    while (root)
    {

        if (root->data == input)
            return input;

        if (root->data < ans && root->data > input)
            ans = root->data;

        if (root->data > input)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return ans;
}

// solution 2
int func2(Node *root, int input)
{

    int ceil = -1;

    while (root)
    {

        if (root->data == input)
            return input;

        if (root->data < input)
            root = root->right;
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}
int findCeil(Node *root, int input)
{

    // return func1(root, input);
    return func2(root, input);
}