#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
TreeNode *createTree(int &index, vector<int> &preorder, vector<int> &inorder, vector<bool> &visited, int n, map<int, int> &indexMap)
{

    TreeNode *root = new TreeNode(preorder[index]); // create new node.

    int index_in_inorder = indexMap[root->val]; // get the index of this root in inorder.

    visited[index_in_inorder] = true; // set this as true.
    index++;                          // move for next index in preorder.

    if (index_in_inorder - 1 >= 0 && visited[index_in_inorder - 1] == false)
    { // if element in inorder on the left is not visited.
        root->left = createTree(index, preorder, inorder, visited, n, indexMap);
    }
    else
        root->left = NULL; // no unvisited element on the left is present.

    if (index_in_inorder + 1 < n && visited[index_in_inorder + 1] == false)
    { // if element in inorder on the right is not visited.
        root->right = createTree(index, preorder, inorder, visited, n, indexMap);
    }
    else
        root->right = NULL; // no unvisited element on the right is present.

    return root; // return the root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{

    int n = preorder.size();

    vector<bool> visited(n, false); // keeps the track of which nodes have been visited in inorder.

    int index = 0;

    map<int, int> indexMap; // index map of the nodes of inorder.

    for (int i = 0; i < n; i++)
    {
        indexMap[inorder[i]] = i;
    }

    TreeNode *root = createTree(index, preorder, inorder, visited, n, indexMap);

    return root;
}

// Approach 2;
// no visited array;
TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
{

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    TreeNode *root = new TreeNode(preorder[preStart]);

    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{

    map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    TreeNode *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

    return root;
}
