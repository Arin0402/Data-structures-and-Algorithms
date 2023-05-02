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

// Approach 1;
// Top Down
// O(n^2)
int height(TreeNode *root)
{
    if (!root)
        return 0;

    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

int diameter(TreeNode *root, int &ans)
{

    if (!root)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    ans = max(left + right, ans);

    diameter(root->left, ans);
    diameter(root->right, ans);

    return ans + 1;
}

// Approach 2
// Bottom Up Approach. DFS

class Solution {
  public:
    
    int helper(Node* root, int &ans){
        
        if(!root) return 0;
        
        int left = 0, right = 0;
        
        // left height
        if(root->left) left = helper(root->left, ans);
        
        // right height
        if(root->right) right = helper(root->right, ans);
        
        // find the max diameter
        ans = max(ans, 1 + left + right);
        
        // return the max of the heights
        return 1 + max(left, right);
        
    }
    
    int diameter(Node* root) {
        
        int ans = 0;
        
        helper(root, ans);
        
        return ans;
        
    }
};