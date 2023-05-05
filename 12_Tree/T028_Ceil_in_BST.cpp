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

int func(Node *root, int input)
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
    return func(root, input);
}