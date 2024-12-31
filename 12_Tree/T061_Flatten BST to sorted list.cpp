#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int data;
    Node *left = NULL, *right = NULL;

    Node(int val)
    {
        data = val;
    }
};

class Solution
{
public:
    
    void helper(Node* root, Node** prev){
        
        if(!root) return;
        
        helper(root->right, prev);
        
        root->right = *prev;
        *prev = root;
        
        helper(root->left, prev);
        
        root->left = NULL;
        
    }

    Node *flattenBST(Node *root)
    {
        Node* prev = NULL;
        helper(root, &prev);
        
        return prev;
    }
};