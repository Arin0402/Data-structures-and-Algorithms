#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> diagonal(Node *root)
{
    queue<Node *> q; // this will contain the left node of the current node.
    vector<int> ans;

    q.push(root);

    while (!q.empty())
    {

        auto node = q.front();
        q.pop();

        // going right.
        while (node)
        {

            // if the current node has left child then push into the queue.
            if (node->left)
                q.push(node->left);

            ans.push_back(node->data);
            node = node->right; // go right.
        }
    }

    return ans;
}