#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=aZNaLrVebKQ
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

class Solution {
public:

    TreeNode* helper(int preStart, int preEnd, int inStart, int inEnd,vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &mp){

        // Base condition
        if(preStart > preEnd || inStart > inEnd) return NULL;

        // index of the current element in the inorder;
        int indIn = mp[preorder[preStart]];

        // Number of elements on the left in order
        int numLeft = indIn - inStart;      

        TreeNode* root = new TreeNode(preorder[preStart]);

        // The simple whole logic is we divide the range
        root->left = helper(preStart + 1, preStart + numLeft, inStart, inEnd -1, preorder, inorder, mp);
        root->right = helper(preStart + numLeft + 1, preEnd, indIn + 1, inEnd, preorder, inorder, mp);

        return root;                  
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Creating the map to store the indexes of inorder 
        unordered_map<int, int> mp;        

        int n = preorder.size();

        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;            
        }

        return helper(0, n - 1, 0, n - 1, preorder, inorder, mp);
        
    }
};