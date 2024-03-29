#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

struct node
{
    int data;
    struct node *left, *right;
};

bool isLeaf(node *root)
{
    return !root->left && !root->right;
}

void addLeftBoundary(node *root, vector<int> &res)
{
    node *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addRightBoundary(node *root, vector<int> &res)
{
    node *cur = root->right;
    vector<int> tmp;
    while (cur)
    {
        if (!isLeaf(cur))
            tmp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = tmp.size() - 1; i >= 0; --i)
    {
        res.push_back(tmp[i]);
    }
}

void addLeaves(node *root, vector<int> &res) // preorder traversal
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

vector<int> printBoundary(node *root)
{
    vector<int> res;
    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);

    // add leaf nodes
    addLeaves(root, res);

    addRightBoundary(root, res);
    return res;
}

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{

    struct node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    vector<int> boundaryTraversal;
    boundaryTraversal = printBoundary(root);

    cout << "The Boundary Traversal is : ";
    for (int i = 0; i < boundaryTraversal.size(); i++)
    {
        cout << boundaryTraversal[i] << " ";
    }
    return 0;
}