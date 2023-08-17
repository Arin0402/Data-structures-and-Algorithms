#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Inorder of BST is always in sorted order.

// TC - O(N);
// SC - O(N) - auxilary;
class Solution {
  public:
    
    int helper(Node* root, int &K){
        
        // NULL
        if(!root) return -1;
        
        // Go left
        int left = helper(root->left, K);
        if(left >= 0) return left;
        
        // we will check for the Kth smallest int the order we print the BST.
        // If it is our Kth element then we return else go to the next element
        K--;
        if(K == 0) return root->data;
        
        // Go right
        int right = helper(root->right, K);
        if(right >= 0) return right;
        
        
        return -1;
        
    }
  
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        
        return helper(root, K);
    }
};

// can also be done using morris traversal.

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        
        while(root){
            
            // No left available
            if(root->left == NULL){
                // check
                k--;
                if(k == 0) return root->data;
                
                root = root->right;
            }
            else{
                
                Node* temp = root->left;
                
                // go left then extreme right
                while(temp->right && temp->right != root){
                    temp = temp->right;
                }
                
                // no right, make link
                if(temp->right == NULL){
                    temp->right = root;
                    root = root->left;
                }
                // link already there so break it and go right
                else {
                    temp->right = NULL;
                    
                    // check
                    k--;
                    if(k == 0) return root->data;
                
                    root = root->right;
                }
            }
        }
        
        return -1;
    }
};