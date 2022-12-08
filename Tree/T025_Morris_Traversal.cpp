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

// TC - near about O(N); (amotised time complexity);
// SC - O(1);

// Inorder traversal;
vector<int> inOrder(Node *root)
{

    vector<int> ans;

    while (root)
    {

        if (root->left == NULL)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {

            Node *prev = root->left;

            while (prev->right && prev->right != root)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = root;
                root = root->left;
            }
            else
            {
                prev->right = NULL;
                ans.push_back(root->data);
                root = root->right;
            }
        }
    }

    return ans;
}

// preorder traversal;
vector<int> preOrder(Node *root)
{

    vector<int> ans;

    while (root)
    {

        if (root->left == NULL)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {

            Node *prev = root->left;

            while (prev->right && prev->right != root)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = root;
                ans.push_back(root->data);
                root = root->left;
            }
            else
            {
                prev->right = NULL;
                root = root->right;
            }
        }
    }

    return ans;
}
