#include <bits/stdc++.h>
using namespace std;

// node decleration
struct TreeNode
{
    int val;    
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// level order or breadth first traversal
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {

        int size = q.size();
        vector<int> lev;

        for (int i = 0; i < size; i++)
        {

            TreeNode *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            lev.push_back(node->val);
            
        }

        ans.push_back(lev);
    }

    return ans;
}

// Reverse level order traersal
vector<int> reverseLevelOrder(TreeNode *root)
{
    vector<int> ans;

    if (!root)
        return {};

    queue<TreeNode *> q;
    stack<int> s;

    q.push(root);

    while (!q.empty())
    {

        auto node = q.front();
        q.pop();

        s.push(node->val);

        if (node->right)
            q.push(node->right);
        if (node->left)
            q.push(node->left);
    }

    while (!s.empty())
    {

        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

void preorder(vector<int> &res, TreeNode *root)
{
    if (root == NULL)
        return;

    res.push_back(root->val);
    preorder(res, root->left);
    preorder(res, root->right);

    // TC - O(n);
    // SC - O(n), (height of the tree, in worst case skewed tree)
}

void inorder(vector<int> &res, TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(res, root->left);
    res.push_back(root->val);
    inorder(res, root->right);
}

void postorder(vector<int> &res, TreeNode *root)
{
    if (root == NULL)
        return;

    postorder(res, root->left);
    postorder(res, root->right);
    res.push_back(root->val);
}

// - Applications of Inorder Traversal

// If inorder traversal of Binary Search Tree (BST) is done , we get increasing order.
// We can get reversed order / Decreasing order by doing inorder traversal in reverse order ( where right subtree is called first and then left subtree is called)

// - Applications of Preorder Traversal

// The main use of Preorder is to get copy of Tree.
// Other use is to generate Prefix expression.

// - Applications of Postorder Traversal

// The main use of Postorder is to delete the tree ( Before deleting the parent, we should delete children first ).
// Other use is to generate Postfix expression.

// - Applications of Level order Traversal

// Level order traversal is actually Breadth First Search.
// Finding connected components in graph data structure.