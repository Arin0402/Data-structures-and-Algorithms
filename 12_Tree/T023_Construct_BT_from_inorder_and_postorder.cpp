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

// Approach 1;
// visited array is taking extra space;
// same as previous question , just indexing is started from back and root->right is called first;
TreeNode *createTree(int &index, vector<int> &postorder, vector<int> &inorder, vector<bool> &visited, int n, map<int, int> &indexMap)
{

    TreeNode *root = new TreeNode(postorder[index]); // create new node.

    int index_in_inorder = indexMap[root->val]; // get the index of this root in inorder.

    visited[index_in_inorder] = true; // set this as true.
    index--;                          // move for next index in postorder.

    if (index_in_inorder + 1 < n && visited[index_in_inorder + 1] == false)
    { // if element in inorder on the right is not visited.
        root->right = createTree(index, postorder, inorder, visited, n, indexMap);
    }
    else
        root->right = NULL; // no unvisited element on the right is present.

    if (index_in_inorder - 1 >= 0 && visited[index_in_inorder - 1] == false)
    { // if element in inorder on the left is not visited.
        root->left = createTree(index, postorder, inorder, visited, n, indexMap);
    }
    else
        root->left = NULL; // no unvisited element on the left is present.

    return root; // return the root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{

    int n = postorder.size();

    vector<bool> visited(n, false); // keeps the track of which nodes have been visited in inorder.

    int index = n - 1;

    map<int, int> indexMap; // index map of the nodes of inorder.

    for (int i = 0; i < n; i++)
    {
        indexMap[inorder[i]] = i;
    }

    TreeNode *root = createTree(index, postorder, inorder, visited, n, indexMap);

    return root;
}

// Approach 2;

TreeNode *buildTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
{

    if (postStart > postEnd || inStart > inEnd)
        return NULL;

    TreeNode *root = new TreeNode(postorder[postEnd]);

    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);

    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{

    map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    TreeNode *root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

    return root;
}
