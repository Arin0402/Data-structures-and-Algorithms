// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
#include <bits/stdc++.h>
using namespace std;

struct Node{
    
    int data;
    Node *left = NULL, *right= NULL;
    
    Node(int val){
        data = val;
    }
};

bool Helper(Node* root, int low, int high){
    
    if(!root) return false;
    
    if(high - low == 2 && root->data  == (high + low )/2) return true; // ex:- low = 6 , high = 8, root->data = 7 , so it is not possible to insert any further.
    
    if(Helper(root->left , low, root->data)) return true;
    if(Helper(root->right , root->data, high)) return true;
    
    // or
    // return Helper(root->left , low, root->data) || Helper(root->right , root->data, high);
}

bool isDeadEnd(Node *root)
{
    return Helper(root, 0, INT_MAX);
}