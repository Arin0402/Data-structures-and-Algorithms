// https://practice.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1
#include <bits/stdc++.h>
using namespace std;

struct Node{
    
    int data;
    Node *left = NULL, *right= NULL;
    
    Node(int val){
        data = val;
    }
};

class Solution{
    public:
    
    int findSucc(Node* root, int x){ // returns the successor in a bst.
        
        Node *succ = NULL;
        
        while (root)
        {
    
            if (root->data > x)
            {
                succ = root;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        
        if(succ)
            return succ->data;
        else return -1;

    }
    
    void insertIntoBst(Node* root, int val){
        
        while (root)
        {
    
            if (root->data < val)
            {
    
                if (root->right)
                    root = root->right; // if there exists a right, got to right.
                else
                { // else insert.
                    Node *newnode = new Node(val);
                    root->right = newnode;
                    break;
                }
            }
            else
            {
                if (root->left)
                    root = root->left;
                else
                {
                    Node *newnode = new Node(val);
                    root->left = newnode;
                    break;
                }
            }
        }
            
    }
    

    vector<int> findLeastGreater(vector<int>& arr, int n) {
                  
        vector<int> ans(n, -1);
        
        Node* root = new Node(arr[n-1]);
        
        for(int i = n-2; i>=0 ; i--){ // start from the second last element of the array.
            
            insertIntoBst(root, arr[i]);
            
            ans[i] = findSucc(root, arr[i]);
            
        }            
        
        return ans;
            
    }
};