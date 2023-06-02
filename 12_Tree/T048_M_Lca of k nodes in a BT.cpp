#include <bits/stdc++.h>
using namespace std;

// No question link available 
// we are given an array of k nodes, we have to find the lca of these nodes

class TreeNode{

    public:

        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(){
            left = right = NULL;
        }
};

class Solution {
public:

    // our answer
    TreeNode* lca = NULL;

    // special nodes -> nodes for which we have to find the lca (address of the  nodes are given)

    int lcaOFSPECIALNODES(TreeNode* current, vector<TreeNode*> &specialNodes){
        
        if(current==NULL) return 0;

        // count the numnber of special nodes in the left subtree
        int lt = lcaOFSPECIALNODES(current->left, specialNodes);
        // count the numnber of special nodes in the right subtree
        int rt = lcaOFSPECIALNODES(current->right, specialNodes);

        // total number of nodes at the current node
        // check also if the current node os special or not
        // if it is special then it would be present in the specialNodes vector.
        int meraAns = lt + rt + (binary_search(specialNodes.begin(), specialNodes.end(), current)?1:0);

        // found the lca
        if(lca==NULL and meraAns == specialNodes.size()){   
            lca = current;
        }
        return meraAns;
    }
};