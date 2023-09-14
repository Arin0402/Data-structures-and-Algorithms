#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-complete-tree-nodes/

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

// To count the total number of nodes in a perfect binary tree formula is (2^height - 1).
// To determine if its a perfect tree, go all the way down and calculate the height on left and right side, If the height is same then, its a perfect tree and our formula applies.
// If its not a perfect tree, we go on left and right subtree and again determine if they are perfect tree.
// When we have our left and right heights, we do (1 + left + right)
// If we reach null, return 0
// C++ note: 1 << n is the same as raising 2 to the power n, or 2^n

class Solution {
public:

    int leftHeight(TreeNode* root){

        int count = 0;

        while(root){

            count++;
            root = root->left;
        }
        return count;
    }

    int rightHeight(TreeNode* root){

        int count = 0;

        while(root){

            count++;
            root = root->right;

        }

        return count;
    }

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int lh =  leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return (1<<lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);

    }
};