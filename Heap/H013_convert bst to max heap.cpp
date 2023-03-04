#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1
// see H012

struct Node {
    int data;
    Node *left, *right;
};

class Solution{
  public:
  
    void inorder(Node* root, vector<int> &ans, int &n){
        
        if(!root) return;
        
        inorder(root->left, ans, n);
        ans.push_back(root->data);
        n++;
        inorder(root->right, ans, n);
        
    }
    
    // post order because of the condition in question that
    // all the values in the left subtree of a node should be less 
    // than all the values in the right subtree of the node. 
    
    void postorder(Node* root, int &i, vector<int> &ans){
        
        if(!root) return;
        
        root->data = ans[i--];
        
        postorder(root->right, i, ans);
        postorder(root->left, i, ans);
        
        
    }
    
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> ans;
        int n = 0;
        
        inorder(root, ans, n);
        
        int i = n-1;
        
        postorder(root, i, ans);
        
    }    
};
