#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
// https://youtu.be/_9F2VgZcvdw?t=1130

// 1
// O(n)
// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    
    // count the nodes of tree
    int countNodes(Node* root){
        
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    // check if it is complete binary tree or not
    bool isComplete(Node* root, int ind, int n){
        
        if(!root) return true;
        
        if(ind >= n) return false;
        
        bool left = isComplete(root->left, 2*ind + 1, n);
        bool right = isComplete(root->right , 2*ind + 2, n);
        
        return left && right;
        
    }
    
    // check the max heap property.
    bool checkheapProperty(Node* root){
        
        if(!root) return true;
        if(!root->left && !root->right) return true;
        
        if(root->left && root->data < root->left->data) return false;
        if(root->right && root->data < root->right->data) return false;
        
        
        bool left = checkheapProperty(root->left);
        bool right = checkheapProperty(root->right);
        
        return left && right;
    }
    
    bool isHeap(struct Node* tree) {
        
        int n = countNodes(tree);
        
        // it should be both complete and justify the heap property.
        if(isComplete(tree, 0, n) && checkheapProperty(tree)){
            return true;
        }   
        return false;
        
    }
};