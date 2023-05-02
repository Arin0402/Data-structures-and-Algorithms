#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


// Approach 1
// Top Down Approach.

// To calculate the height of the tree.
int height(TreeNode *root)
{

    if (!root)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}
bool isBalanced(TreeNode *root)
{

    if (!root)
        return true;

    int leftHeight = height(root->left);   // height of left subtree.
    int rightHeight = height(root->right); // height of right subtree.

    if (abs(leftHeight - rightHeight) > 1)
        return false; // if difference in height is >1 then return false.

    if (isBalanced(root->left) == false)
        return false; // if left part returns false, the return false.
    if (isBalanced(root->right) == false)
        return false; // if right part returns false, the return false.

    return true;

    // TC - O(N^2).  O(N) time for calculating height of the tree. This need to be done for every node. so N^2.
}

// Approach 2
// Bottom Up Approach. DFS
// Same concept to calculate the height of the tree.
// TC - O(N)

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int helper(Node* root){
        
        if(!root) return 0;
        
        int left = helper(root->left); // left height
        int right = helper(root->right); // right height.
        
        if(left == -1) return -1; // condition failed at subtree.
        if(right == -1) return -1;
        
        if(abs(left - right) > 1) return -1; // difference in heights is greater than 1.
        
        return 1 + max(left, right); // difference is <= 1.
    }
    
    bool isBalanced(Node *root)
    {
        
        if(helper(root) == -1) return false;
        return true;
        
    }
};
