#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
    }
};

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{

    if (!root)
        return "";
    string data = "";

    queue<TreeNode *> q;
    q.push(root);

    data.append(to_string(root->val) + ',');

    while (!q.empty())
    {

        TreeNode *node = q.front();
        q.pop();

        if (node->left)
        {
            data.append(to_string(node->left->val) + ',');
            q.push(node->left);
        }
        else
        {
            data.append("#,");
        }

        if (node->right)
        {
            data.append(to_string(node->right->val) + ',');
            q.push(node->right);
        }
        else
        {
            data.append("#,");
        }
    }

    cout << data;
    return data;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{

    if (data.size() == 0)
        return NULL;

    stringstream s(data); // converts string into iterable object;
    string str;

    getline(s, str, ','); // gets char from the string object, it will get auto incremented  ;

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoi(str));

    q.push(root);

    while (!q.empty())
    {

        TreeNode *curr = q.front();
        q.pop();

        getline(s, str, ',');

        if (str == "#")
            curr->left = NULL;
        else
        {
            TreeNode *leftNode = new TreeNode(stoi(str));
            curr->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');

        if (str == "#")
            curr->right = NULL;
        else
        {
            TreeNode *rightNode = new TreeNode(stoi(str));
            curr->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}