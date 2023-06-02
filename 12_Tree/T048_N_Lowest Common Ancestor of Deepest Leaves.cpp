#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// this question is a combination of two questions
// find the deepest nodes of the tree(level order traversal) + find the lca of k nodes(deepest nodes)

class Solution {
public:        

    // to find the lca of k nodes
    int lcaOfKNodes(TreeNode* root, vector<TreeNode*> &specialNodes, TreeNode** ans){
        
        if(!root) return 0;

        // left count of special nodes
        int left = lcaOfKNodes(root->left,specialNodes, ans);
        // right count of special nodes
        int right = lcaOfKNodes(root->right,specialNodes, ans);

        int count = left + right;

        // check if current node is also a special node
        if(binary_search(specialNodes.begin(), specialNodes.end(), root)) count++;

        // found
        if(*ans == NULL && count == specialNodes.size()) *ans = root;

        return count;

    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {

       // find the deepest nodes 
       vector<TreeNode*> curr;    
       vector<TreeNode*> next;

       curr.push_back(root);

        while(curr.size()){
            
            next.clear();
            for(int i = 0; i < curr.size(); i++){                
                if(curr[i]->left) next.push_back(curr[i]->left);
                if(curr[i]->right) next.push_back(curr[i]->right);
            }

            swap(curr, next);
        }

        // now next stores the deepest leavees of the tree.
        // now we need to find the lca of these nodes.

        // sort it to apply binary search
        sort(next.begin(), next.end());

        TreeNode* ans = NULL;

        lcaOfKNodes(root, next, &ans);
        
        return ans;
    }
};