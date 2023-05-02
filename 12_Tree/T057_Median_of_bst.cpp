#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// count number of nodes using morris traversal.
int countNodes(Node *root)
{

    int count = 0;

    while (root)
    {

        if (root->left == NULL)
        {

            count++;
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
                count++;

                root = root->right;
            }
        }
    }
    return count;
}

// calculate median using morris tarversal.
float Helper(Node *root)
{

    if (!root)
        return 0;

    int n = countNodes(root);

    int count = 0;

    Node *prev = NULL;

    while (root)
    {

        if (root->left == NULL)
        {

            count++;

            // odd case
            if (n % 2 != 0 && count == (n + 1) / 2)
            {

                return root->data;
            }
            else if (n % 2 == 0 && count == (n) / 2 + 1)
            {

                return (prev->data + root->data) / 2.0;
            }

            prev = root;
            root = root->right;
        }
        else
        {

            Node *pre = root->left;

            while (pre->right && pre->right != root)
            {
                pre = pre->right;
            }

            if (pre->right == NULL)
            {

                pre->right = root;
                root = root->left;
            }
            else
            {

                pre->right = NULL;

                prev = pre;
                count++;

                // odd case
                if (n % 2 != 0 && count == (n + 1) / 2)
                {

                    return root->data;
                }
                else if (n % 2 == 0 && count == (n) / 2 + 1)
                {

                    return (prev->data + root->data) / 2.0;
                }

                prev = root;
                root = root->right;
            }
        }
    }
}

float findMedian(struct Node *root)
{

    return Helper(root);
}