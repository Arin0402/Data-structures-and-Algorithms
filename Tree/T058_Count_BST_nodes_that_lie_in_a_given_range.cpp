#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};


class Solution{
public:
    
    void preorder(Node* root,int& count,  int l, int h){
        
        if(!root) return ;
        
        if(root->data >= l && root->data <= h){
            count++;
            preorder(root->left, count, l, h);
            preorder(root->right, count, l, h);
            
            // or return 1 + preorder(root->left, count, l, h) + preorder(root->right, count, l, h);
            // this does not require count variable. 
        }
        else if(root->data < l){
            preorder(root->right, count, l, h);
        }
        else{
            preorder(root->left, count, l, h);   
        }
        
        
    }
    
    int getCount(Node *root, int l, int h)
    {
      int count = 0;
      preorder(root, count, l, h);
      
      return count;
      
    }
};
