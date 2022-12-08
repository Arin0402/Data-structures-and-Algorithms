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

int findFloor(Node *root, int input)
{
    int floor = -1;

    while (root)
    {

        if (root->data == input)
            return input;

        if (root->data < input)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return floor;
}