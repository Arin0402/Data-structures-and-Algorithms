#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    
    int helper(TreeNode* root, int &ans){
        
        if(!root) return 0;
        
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        
        ans = max(ans, root->val + left + right);
        
        // the maximum path we are trying to return is neagative
        if(root->val  + max(left, right) < 0) return 0;
        
        return root->val  + max(left, right);
    }
    
    int findMaxSum(TreeNode* root)
    {
        
        int ans = INT_MIN;        
        helper(root, ans);        
        return ans;            
    }
};