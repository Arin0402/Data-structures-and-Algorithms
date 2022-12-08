#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    if (!root)
        return;

    if (root->key == key)
    { // if node found.

        if (root->left)
        { // predecessor will be the extreme right child of left subtree.

            Node *tmp = root->left;

            while (tmp->right)
                tmp = tmp->right;

            pre = tmp;
        }

        if (root->right)
        { // successor will be the extreme left child of right subtree.

            Node *tmp = root->right;

            while (tmp->left)
                tmp = tmp->left;

            suc = tmp;
        }

        return;
    }

    if (root->key > key)
    { // if node value is greater, then it could also be successor.
        suc = root;
        findPreSuc(root->left, pre, suc, key); // then go to left.
    }
    else
    { // if node value is smaller, then it could also be predecessor.

        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}